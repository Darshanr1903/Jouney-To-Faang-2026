from sqlmodel import SQLModel,Field,Relationship
from pydantic import BaseModel,EmailStr,HttpUrl
from typing import Optional
from datetime import datetime,timezone

#URL API SCHEMAS

class URL_Create(BaseModel):
    target_url:HttpUrl

class URL_Responce(BaseModel):
    id:int
    short_id:str
    target_url:HttpUrl
    created_at:datetime
    expires_at:Optional[datetime]=None


#USER API SCHEMAS

class User_create(BaseModel):
    email:EmailStr
    password:str

class User_Responce(BaseModel):
    user_id:int
    email:EmailStr
    is_active:bool

#UserAnalytics API SCHEMAS
class UserAnalytics_Responce(BaseModel):
    url_id:int
    ip:Optional[str]=None
    user_agent:Optional[str]=None
    referer:Optional[str]=None


class URL(SQLModel,table=True):
    id:Optional[int]=Field(default=None,primary_key=True)
    short_id:Optional[str]=Field(default=None,unique=True,index=True)
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
