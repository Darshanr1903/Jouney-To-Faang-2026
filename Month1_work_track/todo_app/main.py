from fastapi import FastAPI, HTTPException# type: ignore

from pydantic import BaseModel

app = FastAPI()


class TodoItem(BaseModel):
    id:int
    task:str
    completed:bool=False


todos={}
@app.get("/")
def home():
    return "Welcome to my project for testing go to /docs"


@app.get("/todos")
def router(completed:bool=None):
    result=list(todos.values())
    if completed is not None:
        result=[x for x in result if x.completed==completed]
    return result

@app.post("/todos")
def add_todo(todo : TodoItem):
    if todo.id in todos:
        raise HTTPException(status_code=400,detail="id already exists")
    todos[todo.id]=todo
    return {"meassage":"Todo added sucessfully"}

@app.put("/todos/{id}")
def update_todo(id:int):
    if id not in todos:
        raise HTTPException(status_code=404,detail="NOT FOUND")
    
    todos[id].completed=True
        
    return {"meassage":"Todo updated sucessfully"}

@app.delete("/todos/{id}")
def delete_task(id:int):
    if id not in todos:
        raise HTTPException(status_code=404,detail=f"no particular data with {id} exists")
    del todos[id]
    return {"message":"task deleted sucessfully"}