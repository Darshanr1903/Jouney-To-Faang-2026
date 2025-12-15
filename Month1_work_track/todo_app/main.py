from fastapi import FastAPI, HTTPException# type: ignore

from pydantic import BaseModel

app = FastAPI()


class TodoItem(BaseModel):
    id:int
    task:str
    Completed:bool=False


todos={}


@app.get("/todos")
def router():
    return list(todos.values())

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
    
    todos[id].Completed=True
        
    return {"meassage":"Todo updated sucessfully"}

@app.delete("/todos/{id}")
def delete_task(id:int):
    if id not in todos:
        raise HTTPException(status_code=404,detail=f"no particular data with {id} exists")
    del todos[id]
    return {"message":"task deleted sucessfully"}