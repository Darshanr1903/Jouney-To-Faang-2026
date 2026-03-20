from fastapi import FastAPI,Request# type: ignore
from fastapi.middleware.cors import CORSMiddleware
from .routers import todo_routes,user_routes
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
    title="Darshan R's Task manager API",
    description="An API to manage my 100 Days of Code tasks.",
    version="1.0.1",
    lifespan=lifespan,
    contact={
        "name":"Darshan R",
        "url":"https://github.com/Darshanr1903",
    }
)

origins=[
    "http://localhost:3000",
    "http://localhost:5173",
    "http://loacalhost:8000",
    "http://127.0.0.1:5500",
    # future domains or urls you can add accordingly
]
app.add_middleware(CORSMiddleware,allow_origins=origins,allow_credentials=True,allow_methods=['*'],allow_headers=['*'])

@app.middleware('http')
async def add_security_headers(request:Request,call_request):
    response=await call_request(request)

    # Inject HSTS (Forces HTTPS for 1 year, including subdomains)
    response.headers["Strict-Transport-Security"] = "max-age=31536000; includeSubDomains"
    
    # Inject CSP (Prevents Cross-Site Scripting)
    # Note: We allow cdn.jsdelivr.net and 'unsafe-inline' here specifically 
    # so that your FastAPI /docs (Swagger UI) interface doesn't break!
    response.headers["Content-Security-Policy"] = (
        "default-src 'self'; "
        "script-src 'self' 'unsafe-inline' https://cdn.jsdelivr.net; "
        "style-src 'self' 'unsafe-inline' https://cdn.jsdelivr.net; "
        "img-src 'self' data: fastapitiangolo.github.io;"
    )

    # Prevent browsers from MIME-sniffing a response away from the declared content-type
    response.headers["X-Content-Type-Options"] = "nosniff"


    return response

app.include_router(todo_routes.router)
app.include_router(user_routes.router)

@app.get("/")
def home():
    return {"message": "Main Entry Point - Go to /docs for the Todo API"}
