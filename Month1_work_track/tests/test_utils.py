import pytest
from fastapi.testclient import TestClient
from todo_app.utils import hashed_password,verifying_password

def test_hashed_password():
    password="Darshanr@01"
    hashed_paswrd=hashed_password(password)
    assert password!=hashed_paswrd
    assert len(hashed_paswrd)>20

def test_verify_correct_password():
    password="Darshanr@01"
    hashed_paswrd=hashed_password(password)
    assert verifying_password(password,hashed_paswrd)


def test_verify_incorrect_password():
    password="Darshanr@01"
    hashed_paswrd=hashed_password(password)
    assert verifying_password("wrongPassword",hashed_paswrd)==False