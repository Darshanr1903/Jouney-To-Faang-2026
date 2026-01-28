from fastapi import APIRouter,HTTPException
from todo_app import schemas,database

router = APIRouter(
    prefix="/todos", # This means all routes here start with /todos
    tags=["Todos"]   # This groups them in your /docs automatically!
)


@router.get("/")
def router(completed:bool=None):
    result=database.get_todos()
    if completed is not None:
        result=[x for x in result if x.completed==completed]
    return result

@router.post("/")
def add_todo(todo : schemas.TodoItem):
    if todo.id in database.todos:
        raise HTTPException(status_code=400,detail="id already exists")
    database.add_todo_to_DB(todo)
    return {"meassage":"Todo added sucessfully"}

@router.put("/{id}")
def update_todo(id:int,status:bool):
    if id not in database.todos:
        raise HTTPException(status_code=404,detail="NOT FOUND")
    
    database.update_todo_to_DB(id,status)
        
    return {"meassage":"Todo updated sucessfully"}

@router.delete("/{id}")
def delete_task(id:int):
    if id not in database.todos:
        raise HTTPException(status_code=404,detail=f"no particular data with {id} exists")
    database.delete_todo_from_DB(id)
    return {"message":"task deleted sucessfully"}