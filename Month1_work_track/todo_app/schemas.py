from pydantic import BaseModel, EmailStr, field_validator
from sqlmodel import SQLModel, Field, Relationship # Added Relationship
from typing import Optional, List
from enum import Enum
import re

class Role(str, Enum):
    User = "user"
    Admin = "admin"

# --- USER MODELS ---

class UserBase(SQLModel):
    username: str = Field(index=True, unique=True, min_length=8, max_length=28)
    email: EmailStr = Field(index=True, unique=True)
    UserRole: Role = Field(default=Role.User)

class UserCreate(UserBase):
    password: str

    @field_validator('password')
    @classmethod
    def password_complexity(cls, v: str) -> str:
        if len(v) < 8:
            raise ValueError("password must be at least 8 characters long")
        if not re.search(r'[A-Z]', v):
            raise ValueError("password must contain at least one uppercase letter")
        if not re.search(r'[a-z]', v):
            raise ValueError("password must contain at least one lowercase letter")
        if not re.search(r'\d', v):
            raise ValueError("password must contain at least one digit")
        if not re.search(r'[!@#$%^&*(),.?":{}|<>]', v):
            raise ValueError('Password must contain at least one special character')
        return v

class User(UserBase, table=True):
    id: Optional[int] = Field(default=None, primary_key=True)
    hashed_password: str
    
    # MAGIC RELATIONSHIP: A user has a list of TodoItems
    todos: List["TodoItem"] = Relationship(back_populates="owner")

class UserRead(UserBase):
    id: int

# --- TODO MODELS ---

class TodoItem(SQLModel, table=True):
    id: Optional[int] = Field(default=None, description="every task has a unique ID", primary_key=True)
    content: str = Field(..., description="this contains the name of task")
    completed: bool = Field(default=False, description="whether the task is completed or not")
    username: Optional[str] = Field(default=None, foreign_key="user.username")
    
    # MAGIC RELATIONSHIP: A TodoItem belongs to a User
    owner: Optional[User] = Relationship(back_populates="todos")

# --- TOKEN MODELS ---

class Token(BaseModel):
    access_token: str
    token_type: str

class TokenData(BaseModel):
    username: Optional[str] = Field(default=None)