from sqlmodel import SQLModel,Session
from sqlalchemy.ext.asyncio import AsyncSession, create_async_engine
from config import settings
from sqlalchemy.orm import sessionmaker




engine=create_async_engine(url=settings.database_url,echo=True,future=True,connect_args={"check_same_thread":False})


async def create_db_and_tables():
    async with engine.begin() as conn:
        await conn.run_sunc(SQLModel.metadata.create_all(engine))

    


async def get_session():
    async_session_maker=sessionmaker(engine,class_=AsyncSession,Expire_on_commit=False)
    async with async_session_maker() as session:
        yield session

