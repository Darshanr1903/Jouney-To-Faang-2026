from fastapi import APIRouter,HTTPException,status,Depends
from sqlmodel import Session
from pydantic import HttpUrl
import schemas,database
import secrets
from fastapi.responses import RedirectResponse

fake_db={}

router=APIRouter(
    tags=["main router"]
)


@router.post("/urls/short",status_code=202)
def create_short_url(long_url:schemas.URL_Create,session:Session=Depends(database.get_session)):
    short_code=secrets.token_urlsafe(5)


    # Optional but recommended: Check for collisions in the DB
    # while session.exec(select(URL).where(URL.short_id == short_code)).first():
    #     short_code = secrets.token_urlsafe(5)

    new_url=schemas.URL(short_id=short_code,target_url=str(long_url.target_url))

    session.add(new_url)
    session.commit()
    session.refresh(new_url)

    return {
        "short_code": new_url.short_id,
        "target_url": new_url.target_url
    }

@router.get("/urls",status_code=200)
def get_all_urls():
    return list(fake_db.values())

@router.get("/{short_id}",status_code=200)
def get_actual_url(short_id:str):
    if short_id not in fake_db:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND,detail="short id not found")
    actual_url=fake_db[short_id]
    return RedirectResponse(url=actual_url)
