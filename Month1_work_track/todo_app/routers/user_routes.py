from fastapi import APIRouter,HTTPException,Path,Depends,status
from sqlmodel import Session,select
from .. import schemas,database

router=APIRouter(
    prefix="/users",
    tags=["Users"]
)

@router.post("/",response_model=schemas.UserRead)
def create_user(user_in:schemas.UserCreate,session:Session=Depends(database.get_session)):
    existing_user=session.exec(select(schemas.User).where(schemas.User.email==user_in.email))

    if existing_user:
        raise HTTPException(status_code=400,detail="user already exists")
    
    # 2. Convert UserCreate to User (Table Model)
    # Note: We manually hash here (logic for real hashing with passlib is the next step!)
    db_user=schemas.User(
        username=user_in.username,
        email=user_in.email,
        hashed_password=f"fake_hash{user_in.password}"

    )

    session.add(db_user)
    session.commit()
    session.refresh(db_user)
    return db_user
    

