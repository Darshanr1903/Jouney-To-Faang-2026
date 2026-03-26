from fastapi import APIRouter,HTTPException,Path,Depends,status,Body
from sqlmodel import Session,select,func
from datetime import datetime,timezone,timedelta
from .. import schemas,database,utils
from..exceptions import CredentialException,UserAlreadyExistException
from jose import jwt,JWTError
import os

router=APIRouter(
    prefix="/users",
    tags=["Users"]
)

SECRET_KEY=os.getenv("SECRET_KEY")
ALGORITHM=os.getenv("ALGORITHM")
REGESTRATION_TOKEN_EXPIRE_MINUTES=int(os.getenv("REGESTRATION_TOKEN_EXPIRE_MINUTES"))

@router.post("/registration",response_model=schemas.UserRead)
def create_user(user_in:schemas.UserCreate,session:Session=Depends(database.get_session)):
    existing_user=session.exec(select(schemas.User).where(schemas.User.email==user_in.email)).first()

    if existing_user:
        raise UserAlreadyExistException()
    
    # 2. Convert UserCreate to User (Table Model)
    # Note: We manually hash here (logic for real hashing with passlib is the next step!)

    user_count=session.exec(select(func.count(schemas.User.id))).one()
    assigned_role=schemas.Role.Admin if user_count==0 else schemas.Role.User
    db_user=schemas.User(
        username=user_in.username,
        email=user_in.email,
        hashed_password=utils.hashed_password(user_in.password),
        UserRole=assigned_role,
        regestration_token=utils.create_regestration_token(data={"sub":user_in.username,"role":assigned_role}),
        is_verified=False

    )

    session.add(db_user)
    session.commit()
    session.refresh(db_user)



    # --- STEP 3: SIMULATE EMAIL DELIVERY ---
    verification_url = f"http://localhost:8000/users/verify-email?token={db_user.registration_token}"
    print(f"\n--- EMAIL INTERCEPTED ---")
    print(f"To: {db_user.email}")
    print(f"Subject: Please verify your Todo App account")
    print(f"Body: Click here to verify: {verification_url}")
    print(f"-------------------------\n")


    return db_user

@router.post("/login")
def login(user_in:schemas.UserCreate,session:Session=Depends(database.get_session)):
        statement=select(schemas.User).where(schemas.User.username==user_in.username)
        db_user=session.exec(statement).first()

        if not db_user or not utils.verifying_password(user_in.password,db_user.hashed_password):
            raise CredentialException()
        
        access_token=utils.create_access_token(data={"sub":db_user.username,"role":db_user.UserRole})
        refresh_token=utils.create_refresh_token(data={"sub":db_user.username,"role":db_user.UserRole})
        db_user.refresh_token=refresh_token
        session.add(db_user)
        session.commit()
        session.refresh(db_user)
        
        return {"access_token":access_token,"refresh_token":refresh_token,"token_type":"bearer"}

@router.post("/logout")
def logout(token:str,session:Session=Depends(database.get_session),current_user:str=Depends(utils.verify_access_token)):
        is_blacklist=session.exec(select(schemas.blacklist).where(schemas.blacklist.token==token))
        if not is_blacklist:
          #add to blacklist
          blacklist_token=schemas.blacklist(token)
          session.add(blacklist_token)
          session.commit()
        return {"message":"successfully logout.Token revoked"}

     


@router.post("/refresh",response_model=schemas.Token)
def refresh_access_token(refresh_token:str=Body(...,embed=True),session:Session=Depends(database.get_session)):
     try:
          payload=jwt.decode(refresh_token,SECRET_KEY,algorithms=[ALGORITHM])
          username=payload["sub"]
          if not username:
               raise CredentialException()
          user=session.exec(select(schemas.User).where(schemas.User.username==username)).first()

          if not user or user.refresh_token!=refresh_token:
               raise CredentialException()
          new_access_token=utils.create_access_token(data={"sub":username,"role":user.UserRole})
          return {"access_token":new_access_token,"refresh_token":refresh_token,"token_type":"bearer"}
     except JWTError:
          raise CredentialException()
     

@router.get("/verify-email")
def verify_email(token:str,session:Session=Depends(database.get_session)):
     try:
          
          decode_data=jwt.decode(token,SECRET_KEY,alogorithms=[ALGORITHM])
          user_name=decode_data["sub"]
          if not user_name:
            raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST,detail="Invalid token")
        
          user=session.exec(select(schemas.User).where(schemas.User.username==user_name)).first()
          if not user:
           raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail="User not found")
          if user.registration_token != token:
           raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST, detail="Invalid or already used token")
          if user.is_verified:
           return {"message": "Account is already verified!"}
        
          user.is_verified=True
          user.refresh_token=None
          session.add(user)
          session.commit()

          return {"message":"Account verified successfully"}
     except JWTError:
         # If the token is expired or altered, JWTError is thrown
        raise HTTPException(status_code=status.HTTP_400_BAD_REQUEST, detail="Token is invalid or expired")
         


        
    

