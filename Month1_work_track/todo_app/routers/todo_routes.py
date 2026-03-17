from fastapi import APIRouter,HTTPException,Path,Depends,status
from sqlmodel import Session,select
from .. import schemas,database,utils

router = APIRouter(
    prefix="/todos", # This means all routes here start with /todos
    tags=["Todos"]   # This groups them in your /docs automatically!
)

@router.get("/tasks/{task_id}",tags=["task operation"])
def get_single_task(task_id:int,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
    if task_id<0:
        raise HTTPException(status_code=status.HTTP_406_NOT_ACCEPTABLE,detail="invalid task id")
    db_todo=session.get(schemas.TodoItem,task_id)
    if not db_todo or db_todo.username!=current_user:
        raise HTTPException(status_code=404, detail="Task not found in your roadmap list")
    
    return db_todo



@router.get("/")
def get_all_todos(completed:bool=None,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
    statement=select(schemas.TodoItem).where(schemas.TodoItem.username==current_user)
    if completed is not None:
        statement=statement.where(schemas.TodoItem.completed==completed)
    results=session.exec(statement).all()
    return results

@router.post("/tasks",tags=["task operation"],summary="Create a New Task",response_description="Returns the created task object")
def add_todo(todo : schemas.TodoItem,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
    """
    **Detailed Logic for creating a task:**
    1. Validates the input against the **TodoItem** schema.
    2. Currently returns the data back (Logic for DB will be added in Point 2).
    """
    # to convert it into database model object
    if not todo.content or not todo.content.strip():
        raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST,detail="Bad Request")
    todo.username=current_user

    # 1) stagging 

    session.add(todo)
    # 2) commiting(saving)
    session.commit()
    # 3) refreshing to get ID created by SQLite
    session.refresh(todo)
    return todo

@router.put("/{task_id}")
def update_todo(task_id:int,is_completed:bool,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
    if task_id<0:
        raise HTTPException(status_code=status.HTTP_406_NOT_ACCEPTABLE,detail="invalid task id")
    db_todo=session.get(schemas.TodoItem,task_id)

    if not db_todo or db_todo.username!=current_user:
        raise HTTPException(status_code=404,detail="Task not found")
    db_todo.completed=is_completed
    session.add(db_todo)
    session.commit()
    session.refresh(db_todo)
    return db_todo

@router.delete("/{task_id}")
def delete_task(task_id:int,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
    if task_id<0:
        raise HTTPException(status_code=status.HTTP_406_NOT_ACCEPTABLE,detail="invalid task id")
    db_todo=session.get(schemas.TodoItem,task_id)

    if not db_todo or db_todo.username!=current_user:
        raise HTTPException(status_code=404,detail=f"no task with {task_id} was found")
    session.delete(db_todo)
    session.commit()
    return {"message" : f"Task with {task_id} was deleted successfully"}