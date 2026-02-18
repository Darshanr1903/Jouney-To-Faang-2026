FastAPI Todo BackendA high-performance asynchronous Todo application backend built with FastAPI and SQLite. This project is part of the Month1_work_track progress.🛠 Tech StackFramework: FastAPIDatabase: SQLiteORM: SQLAlchemy (defined in database.py)Data Validation: Pydantic (defined in schemas.py)Server: Uvicorn📂 Project StructureFollowing your current repository layout:Plaintexttodo_app/
├── routers/          # API route handlers
├── database.db       # SQLite database file
├── database.py       # SQLAlchemy connection & session setup
├── main.py           # Application entry point
├── schemas.py        # Pydantic models for request/response validation
└── .gitignore        # Files to exclude from Git
🚀 Getting Started1. Clone and NavigateBashgit clone https://github.com/Darshanr1903/Jouney-To-Faang-2026.git
cd Month1_work_track/todo_app
2. Set Up Virtual Environment (Recommended)Bash# Windows
python -m venv venv
.\venv\Scripts\activate

# macOS/Linux
python3 -m venv venv
source venv/bin/activate
3. Install DependenciesBashpip install fastapi uvicorn sqlalchemy
4. Run the ServerLaunch the application using Uvicorn with hot-reload enabled:Bashuvicorn main:app --reload
The server will start at http://127.0.0.1:8000.📖 API DocumentationOnce the server is running, you can access the interactive documentation to test the endpoints:Swagger UI: http://127.0.0.1:8000/docsReDoc: http://127.0.0.1:8000/redoc🛣 API EndpointsThe application provides the following core functionalities through the files in /routers:MethodEndpointDescriptionGET/todosFetch all todo itemsPOST/todosCreate a new taskGET/todos/{id}Get details for a specific taskPUT/todos/{id}Update task status or contentDELETE/todos/{id}Remove a task📝 Current Progress[x] Database configuration and models[x] Schema validation with Pydantic[x] CRUD logic implementation[ ] User authentication (JWT) — Next Step
