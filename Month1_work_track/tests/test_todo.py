import sys
import os
import pytest
from fastapi.testclient import TestClient

# Path setup
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

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