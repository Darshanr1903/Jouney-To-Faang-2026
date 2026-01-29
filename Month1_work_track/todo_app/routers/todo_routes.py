from fastapi import APIRouter,HTTPException
import schemas,database

router = APIRouter(
    prefix="/todos", # This means all routes here start with /todos
    tags=["Todos"]   # This groups them in your /docs automatically!
)


@router.get("/")
def get_all_todos(completed:bool=None):
    result=database.get_todos()
    if completed is not None:
        result=[x for x in result if x.completed==completed]
    return result

@router.post("/tasks",tags=["task operation"],summary="Create a New Task",response_description="Returns the created task object")
def add_todo(todo : schemas.TodoItem):
    """
    **Detailed Logic for creating a task:**
    1. Validates the input against the **TodoItem** schema.
    2. Currently returns the data back (Logic for DB will be added in Point 2).
    """
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