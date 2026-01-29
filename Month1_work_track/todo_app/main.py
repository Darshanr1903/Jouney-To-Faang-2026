from fastapi import FastAPI# type: ignore
from routers import todo_routes

app = FastAPI(
    task="Darshan R's Task manager API",
    description="An API to manage my 100 Days of Code tasks.",
    version="1.0.1",
    contact={
        "name":"Darshan R",
        "url":"https://github.com/Darshanr1903",
    }
)

app.include_router(todo_routes.router)

@app.get("/")
def home():
    return {"message": "Main Entry Point - Go to /docs for the Todo API"}
