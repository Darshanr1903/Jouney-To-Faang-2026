from passlib.context import CryptContext

pwd_context=CryptContext(schemes=["argon2","bcrypt"],deprecated="auto")


def hashed_password(password:str)->str:
    "this will be taking plain password and will be returning hash"
    return pwd_context.hash(password)


def verifying_password(plain_password:str,hash_password:str)->bool:
    return pwd_context.verify(plain_password,hash_password)
