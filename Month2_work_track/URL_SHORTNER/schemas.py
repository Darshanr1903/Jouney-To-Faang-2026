from sqlmodel import SQLModel,Field,Relationship
from pydantic import BaseModel,EmailStr
from typing import Optional
from datetime import datetime,timezone


class URL(SQLModel,table=True):
    id:Optional[int]=Field(default=None,primary_key=True)
    short_id:str=Field(unique=True,index=True,nullable=False)
    user_id:Optional[int]=Field(default=None,foreign_key="user.user_id")
    target_url:str=Field(nullable=False)
    created_at:datetime=Field(default_factory=lambda:datetime.now(timezone.utc))
    expires_at:Optional[datetime]=Field(default=None)

    user:Optional["User"]=Relationship(back_populates='urls')
    clicks:list["UserAnalytics"]=Relationship(back_populates="url")

class User(SQLModel,table=True):
    user_id:Optional[int]=Field(default=None,primary_key=True)
    email:EmailStr=Field(index=True,unique=True)
    hashed_pswd:str
    is_active:bool=Field(default=True)

    urls:list["URL"]=Relationship(back_populates='user')

class UserAnalytics(SQLModel,table=True):
    id:Optional[int]=Field(default=None,primary_key=True)
    url_id:int=Field(foreign_key='url.id',index=True)

    #Analytics
    ip:Optional[str]=Field(default=None)
    user_agent:Optional[str]=Field(default=None)
    referer:Optional[str]=Field(default=None)
    url:URL=Relationship(back_populates="clicks")
