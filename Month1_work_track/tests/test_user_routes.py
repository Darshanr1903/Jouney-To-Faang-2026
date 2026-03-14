import pytest
from fastapi.testclient import TestClient
from todo_app.main import app

client=TestClient(app)

def test_post_user_route():
    payload = {
        "username": "vaibhav_test",
        "password": "Vaibhav@01",
        "email": "vaibhav@gmail.com"
    }
    response = client.post("/users/registration", json=payload)
    
    # ADD THIS LINE TO DEBUG:
    if response.status_code == 422:
        print("\nValidation Error Details:", response.json())
        
    assert response.status_code == 200


def test_user_duplicate_email():
    payload={
        "email":"duplicate@email.com",
        "password":"Password@123",
        "username":"firstuser"
    }
    # first regestration
    client.post("/users/registration",json=payload)
    # second regestration
    response=client.post("/users/registration",json=payload)

    assert response.status_code==400
    assert response.json()["detail"]=="User already exists"
