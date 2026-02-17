import pytest
from fastapi.testclient import TestClient

from todo_app.main import app

# We move the client inside the test or use a fixture
def test_read_main():
    # Using 'with' triggers the @asynccontextmanager lifespan!
    with TestClient(app) as client:
        response = client.get("/")
        assert response.status_code == 200
        assert response.json()=={"message": "Main Entry Point - Go to /docs for the Todo API"}

def test_post_route():
    task = {
        "content": "Watching Movie",
        "completed": False
    }
    
    # Using 'with' here ensures create_db_and_tables() is called
    with TestClient(app) as client:
        response = client.post("/todos/tasks", json=task)
        
        assert response.status_code == 200
        data = response.json()
        assert "id" in data
        assert data["content"] == "Watching Movie"


def test_put_route():
    id=1
    flag=True
    with TestClient(app) as client:
        response=client.put(f"/todos/{id}",params={"status":flag})
        assert response.status_code==200
        data=response.json()
        assert data["completed"]==flag

def test_delete_route():
    id=1
    with TestClient(app) as client:
        response=client.delete(f"/todos/{id}",params={"id":id})
        assert response.status_code==200
        data=response.json()
        assert data["message"]==f"Task with {id} was deleted successfully"

