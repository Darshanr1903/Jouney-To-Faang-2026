import schemas

todos={}

def get_todos():
    return list(todos.values())

def add_todo_to_DB(todo:schemas.TodoItem):
    todos[todo.id]=todo

def update_todo_to_DB(id:int,status:bool):
    todos[id].completed=status

def delete_todo_from_DB(id:int):
    del todos[id]



