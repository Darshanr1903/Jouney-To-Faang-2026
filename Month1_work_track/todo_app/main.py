from fastapi import FastAPI# type: ignore
from routers import todo_routes

app = FastAPI()

app.include_router(todo_routes.router)

@app.get("/")
def home():
    return {"message": "Main Entry Point - Go to /docs for the Todo API"}
