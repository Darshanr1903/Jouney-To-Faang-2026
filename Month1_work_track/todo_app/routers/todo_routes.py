from fastapi import APIRouter,HTTPException,Path,Depends
from sqlmodel import Session,select
import schemas,database

router = APIRouter(
    prefix="/todos", # This means all routes here start with /todos
    tags=["Todos"]   # This groups them in your /docs automatically!
)

@router.get("/tasks/{task_id}",tags=["task operation"])
async def get_single_task(task_id:int=Path(...,gt=0, description="The ID must be greater than zero")):
    """
    Goal for Jan 30: Practice returning an error if the ID is valid but not found.
    """
    # Dummy check for now:
    if task_id > 50:
        raise HTTPException(status_code=404, detail="Task not found in your roadmap list")
    
    return {"task_id": task_id, "message": "Task details retrieved"}



@router.get("/")
def get_all_todos(completed:bool=None,session:Session=Depends(database.get_session)):
    statement=select(schemas.TodoItem)
    if completed is not None:
        statement=statement.where(schemas.TodoItem.completed==completed)
    results=session.exec(statement).all()
    return results

@router.post("/tasks",tags=["task operation"],summary="Create a New Task",response_description="Returns the created task object")
def add_todo(todo : schemas.TodoItem,session:Session=Depends(database.get_session)):
    """
    **Detailed Logic for creating a task:**
    1. Validates the input against the **TodoItem** schema.
    2. Currently returns the data back (Logic for DB will be added in Point 2).
    """
    # to convert it into database model object
    db_todo=schemas.TodoItem(**todo.model_dump())
    # 1) stagging 
    session.add(db_todo)
    # 2) commiting(saving)
    session.commit()
    # 3) refreshing to get ID created by SQLite
    session.refresh(db_todo)
    return db_todo

@router.put("/{id}")
def update_todo(id:int,status:bool,session:Session=Depends(database.get_session)):
    db_todo=session.get(schemas.TodoItem,id)

    if not db_todo:
        raise HTTPException(status_code=404,detail="Task not found")
    db_todo.completed=status
    session.add(db_todo)
    session.commit()
    session.refresh(db_todo)
    return db_todo

@router.delete("/{id}")
def delete_task(id:int,session:Session=Depends(database.get_session)):
    db_todo=session.get(schemas.TodoItem,id)

    if not db_todo:
        raise HTTPException(status_code=404,detail=f"no task with {id} was found")
    session.delete(db_todo)
    session.commit()
    return {"message" : f"Task with {id} was deleted successfully"}