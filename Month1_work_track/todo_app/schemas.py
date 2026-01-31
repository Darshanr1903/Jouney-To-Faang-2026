from pydantic import BaseModel, Field
from typing import Optional

class TodoItem(BaseModel):
    # ... means field required
    id:int=Field(...,example=1,description="every task as unique ID")
    task:str=Field(...,example="Watch movies",description="this contains name of the task")
    completed:bool=Field(default=False,example=False,description="status of the task whether completed?")
