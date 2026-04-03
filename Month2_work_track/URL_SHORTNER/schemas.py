from sqlmodel import SQLModel,Field
from pydantic import BaseModel
from typing import Optional


class URL(SQLModel,table=True):
    id:Optional[int]=Field(default=None,primary_key=True)
    short_id:str=Field(unique=True,index=True)
    target_url:str
    is_active:bool=Field(default=True)