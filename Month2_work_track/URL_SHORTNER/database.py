from sqlmodel import SQLModel,Session,create_engine


sqlite_filename="database.db"
sqlite_url=f"sqlite:///{sqlite_filename}"

engine=create_engine(url=sqlite_url,echo=True)


def create_db_and_tables():
    SQLModel.metadata.create_all(engine)


def get_session():
    with Session(engine) as session:
        yield session

