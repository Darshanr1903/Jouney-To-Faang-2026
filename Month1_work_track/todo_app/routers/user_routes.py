from fastapi import APIRouter,HTTPException,Path,Depends,status
from sqlmodel import Session,select,func
from .. import schemas,database,utils

router=APIRouter(
    prefix="/users",
    tags=["Users"]
)

@router.post("/registration",response_model=schemas.UserRead)
def create_user(user_in:schemas.UserCreate,session:Session=Depends(database.get_session)):
    existing_user=session.exec(select(schemas.User).where(schemas.User.email==user_in.email)).first()

    if existing_user:
        raise HTTPException(status_code=400,detail="user already exists")
    
    # 2. Convert UserCreate to User (Table Model)
    # Note: We manually hash here (logic for real hashing with passlib is the next step!)

    user_count=session.exec(select(func.count(schemas.User.id))).one()
    assigned_role=schemas.Role.Admin if user_count==0 else schemas.Role.User
    db_user=schemas.User(
        username=user_in.username,
        email=user_in.email,
        hashed_password=utils.hashed_password(user_in.password),
        UserRole=assigned_role

    )

    session.add(db_user)
    session.commit()
    session.refresh(db_user)
    return db_user

@router.post("/login")
def login(user_in:schemas.UserCreate,session:Session=Depends(database.get_session)):
        statement=select(schemas.User).where(schemas.User.username==user_in.username)
        db_user=session.exec(statement).first()

        if not db_user or not utils.verifying_password(user_in.password,db_user.hashed_password):
            raise HTTPException(status_code=403,detail="user not found or invalid credentials")
        
        return {"message": "Login successful", "user": db_user}
    

