from fastapi import APIRouter,HTTPException,status
from pydantic import HttpUrl
import schemas
import secrets
from fastapi.responses import RedirectResponse

fake_db={}

router=APIRouter(
    prefix="/urls",
    tags=["main router"]
)


@router.post("/urls",status_code=202)
def create_short_url(long_url:HttpUrl):
    short_code=secrets.token_urlsafe(5)

    new_url=schemas.URL(short_id=short_code,target_url=long_url)

    fake_db[short_code]=new_url

    return new_url

@router.get("/urls",status_code=200)
def get_all_urls():
    return list(fake_db.values())

@router.get("/{short_id}",status_code=200)
def get_actual_url(short_id:str):
    if short_id not in fake_db:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND,detail="short id not found")
    actual_url=fake_db[short_id]
    return RedirectResponse(url=actual_url.target_url)
