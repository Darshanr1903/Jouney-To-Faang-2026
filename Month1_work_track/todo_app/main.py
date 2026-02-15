from fastapi import FastAPI# type: ignore
from .routers import todo_routes
from . import database 
from contextlib import asynccontextmanager

@asynccontextmanager
async def lifespan(app:FastAPI):
    database.create_db_and_tables()
    print("creating database")
    yield
    # optional
    print("shuting down")


app = FastAPI(
    task="Darshan R's Task manager API",
    description="An API to manage my 100 Days of Code tasks.",
    version="1.0.1",
    lifespan=lifespan,
    contact={
        "name":"Darshan R",
        "url":"https://github.com/Darshanr1903",
    }
)

app.include_router(todo_routes.router)

@app.get("/")
def home():
    return {"message": "Main Entry Point - Go to /docs for the Todo API"}
