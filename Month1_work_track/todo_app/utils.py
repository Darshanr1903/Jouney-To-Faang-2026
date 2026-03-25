from passlib.context import CryptContext
from datetime import datetime,timezone,timedelta
from dotenv import load_dotenv
from .exceptions import CredentialException
from jose import jwt,JWTError
import os
from fastapi import Depends
from sqlmodel import SQLModel,Session,select
from . import database,schemas,exceptions
from fastapi.security import OAuth2PasswordBearer

load_dotenv()

ALGORITHM=os.getenv("ALGORITHM")
SECRET_KEY=os.getenv("SECRET_KEY")
ACCESS_TOKEN_EXPIRE_MINUTES=int(os.getenv("ACCESS_TOKEN_EXPIRE_MINUTES"))
REFRESH_TOKEN_EXPIRE_DAYS=int(os.getenv("REFRESH_TOKEN_EXPIRE_DAYS"))

pwd_context=CryptContext(schemes=["argon2","bcrypt"],deprecated="auto")
oauth2_scheme = OAuth2PasswordBearer(tokenUrl="login")


def hashed_password(password:str)->str:
    "this will be taking plain password and will be returning hash"
    return pwd_context.hash(password)


def verifying_password(plain_password:str,hash_password:str)->bool:
    return pwd_context.verify(plain_password,hash_password)


def create_access_token(data:dict):
    to_encode=data.copy()
    expire=datetime.now(timezone.utc)+timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    to_encode.update({"exp":expire})
    encoded_jwt=jwt.encode(to_encode,SECRET_KEY,ALGORITHM)
    return encoded_jwt

def create_refresh_token(data:dict):
    to_encode=data.copy()
    expire=datetime.now(timezone.utc)+timedelta(days=REFRESH_TOKEN_EXPIRE_DAYS)
    to_encode.update({"exp":expire})
    encode_jwt=jwt.encode(to_encode,SECRET_KEY,ALGORITHM)
    return encode_jwt


def verify_access_token(token:str):
    try:
        payload=jwt.decode(token,SECRET_KEY,algorithms=[ALGORITHM])
        username:str=payload.get("sub")
        if not username:
            raise CredentialException()
        return username
    except JWTError:
        raise CredentialException()
    
def check_blacklist(token:str=Depends(oauth2_scheme),session:Session=Depends(database.get_session)):
    is_blacklist=session.exec(select(schemas.blacklist).where(schemas.blacklist.token==token)).first()
    if is_blacklist:
        raise exceptions.CredentialException()
    
    return verify_access_token(token)

def get_current_user(user_name:str=Depends(check_blacklist),session:Session=Depends(database.get_session))->schemas.User:
    user=session.exec(select(schemas.User).where(schemas.User.username==user_name)).first()
    if not user:
        raise exceptions.CredentialException()
    return user

def admin_verification(current_user:schemas.User=Depends(get_current_user))->schemas.User:
    if current_user.UserRole!=schemas.Role.Admin:
        raise exceptions.CredentialException()
    return current_user
    

    

