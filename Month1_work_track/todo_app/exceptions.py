from fastapi import HTTPException,status

class AuthException(HTTPException):
    def __init__(self,detail:str="Authentication Failed",status_code:int=status.HTTP_401_UNAUTHORIZED):
        super().__init__(status_code=status_code,detail=detail,headers={"WWW-Authenticate": "Bearer"})


class CredentialException(AuthException):
    def __init__(self):
        super().__init__(detail="Invalid Credentials")

class UserAlreadyExistException(HTTPException):
    def __init__(self,detail:str="User already exists",status_code:int=status.HTTP_400_BAD_REQUEST):
        super().__init__(status_code=status_code,detail=detail)