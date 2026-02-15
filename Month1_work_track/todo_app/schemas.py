from pydantic import BaseModel, Field
from typing import Optional
from sqlmodel import SQLModel,Field


class TodoItem(SQLModel,table=True):
    id:Optional[int]=Field(default=None,description="every task as unique ID",primary_key=True)
    content:str=Field(...,description="this contains the name of task")
    completed:bool=Field(default=False,description="whether the task is completed or not")

