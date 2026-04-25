from fastapi import APIRouter,HTTPException,status,Depends
from sqlmodel import Session
from pydantic import HttpUrl
import uuid
import utils
import schemas,database
import secrets
from fastapi.responses import RedirectResponse
from sqlalchemy.exc import IntegrityError

fake_db={}

router=APIRouter(
    tags=["main router"]
)


@router.post("/urls/short", status_code=201)
def create_short_url(long_url: schemas.URL_Create, session: Session = Depends(database.get_session)):
    is_reachable=utils.verify_url_reachability(str(long_url.target_url))
    if not is_reachable:
        raise HTTPException(status_code=400,details="url not found or doesnt exist") 
    
    max_retries = 3  # How many times to try generating a unique hash
    
    for attempt in range(max_retries):
        # 1. Generate the hash
        entropy=""if attempt==1 else str(uuid.uuid4())
        hash_input=str(long_url.target_url)+entropy
        code = utils.generate_secure_hash(hash_input)
        
        # 2. Create the model instance
        new_url = schemas.URL(short_id=code, target_url=str(long_url.target_url))
    
        # 3. Add to the session
        session.add(new_url)
        
        try:
            # 4. Attempt to save to the SQLite database
            session.commit()
            session.refresh(new_url)
            
            # If commit is successful, return and exit the function completely!
            return {
                "short_code": new_url.short_id,
                "target_url": new_url.target_url
            }
            
        except IntegrityError:
            # 5. Collision detected! Undo the failed transaction.
            session.rollback()
            
            # The loop will automatically go back up and try a new hash!
            # If we've reached our max retries, then we finally throw an error.
            if attempt == max_retries - 1:
                raise HTTPException(
                    status_code=500, 
                    detail="Server busy or collision detected. Please try again."
                )

@router.get("/urls",status_code=200)
def get_all_urls():
    return list(fake_db.values())

@router.get("/{short_id}",status_code=200)
def get_actual_url(short_id:str):
    if short_id not in fake_db:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND,detail="short id not found")
    actual_url=fake_db[short_id]
    return RedirectResponse(url=actual_url)
