from fastapi import FastAPI,HTTPException,status
from pydantic import HttpUrl
import secrets
import schemas
from fastapi.responses import RedirectResponse
from routers import main_route
from contextlib import asynccontextmanager
from database import create_db_and_tables


@asynccontextmanager
async def lifespan(app:FastAPI):
    create_db_and_tables()
    print("creating database")
    yield
    print("shutting down")


app=FastAPI(title="Darshan R's URL Shortner",verdion="0.1.0",lifespan=lifespan,contact={"Name":"DARSHAN R","contact_details":"darshanr974151@gmail.com"})
app.include_router(main_route.router)





@app.get("/")
def home():
    return {"message":"welcome to my url shortner project go to docs for further enquiry"}

