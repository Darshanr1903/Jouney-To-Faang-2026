from pydantic import BaseModel, Field
from typing import Optional
from sqlmodel import SQLModel,Field
from pydantic import EmailStr,field_validator
from enum import Enum
import re

class Role(str,Enum):
    User="user"
    Admin="admin"


class TodoItem(SQLModel,table=True):
    id:Optional[int]=Field(default=None,description="every task as unique ID",primary_key=True)
    content:str=Field(...,description="this contains the name of task")
    completed:bool=Field(default=False,description="whether the task is completed or not")


# user models

class UserBase(SQLModel):
    username:str=Field(index=True,unique=True,min_length=8,max_length=28)
    email:EmailStr=Field(index=True,unique=True)
    UserRole:Role=Field(default=Role.User)


class UserCreate(UserBase):
    # plain password
    password:str

    @field_validator('password')
    @classmethod
    def password_complexity(cls,v:str)->str:
        "custom rules verifivation for password"
        if len(v)<8:
            raise ValueError("password must be at least 8 characters long")
        if not re.search(r'[A-Z]',v):
            raise ValueError("password must contain at least one uppercase letter")
        if not re.search(r'[a-z]',v):
            raise ValueError("password must contain at least one lowercase letter")
        if not re.search(r'\d',v):
            raise ValueError("password must contain at least one digit")
        if not re.search(r'[!@#$%^&*(),.?":{}|<>]', v):
            raise ValueError('Password must contain at least one special character')
        return v

class User(UserBase,table=True):
    id:Optional[int]=Field(default=None,primary_key=True)
    hashed_password:str

class UserRead(UserBase):
    id:int

class Token(BaseModel):
    access_token:str
    token_type:str

class TokenData(BaseModel):
    username:Optional[str]=Field(default=None)

