from fastapi import FastAPI

app = FastAPI()


@app.get("/")
def router():
    return {"message": "hello Darshan"}