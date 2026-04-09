from pydantic_settings import BaseSettings,SettingsConfigDict

def Settings(BaseSettings):
    project_name:str="Default url shortner"
    database_url:str
    secret_key:str
    access_token_expire_minutes:int

    # this tells pydantic to read from .env file
    model_config=SettingsConfigDict(env_file=".env",env_file_encoding="utf_8")

#instantiate settings so that it can be imported across
settings=Settings()