🚀 FastAPI Todo Backend
A high-performance asynchronous Todo application backend built with FastAPI and SQLite. This project is part of my Month1_work_track progress toward mastering backend development.

🛠 Tech Stack
Framework: FastAPI

Database: SQLite (File-based)

ORM: SQLAlchemy (Logic in database.py)

Validation: Pydantic (Logic in schemas.py)

Server: Uvicorn

📂 Project Structure
Based on the current repository layout:

Plaintext
todo_app/
├── routers/          # API route handlers (Task logic)
├── database.db       # SQLite database file
├── database.py       # SQLAlchemy connection setup
├── main.py           # Application entry point
├── schemas.py        # Pydantic models for data validation
└── .gitignore        # Files ignored by Git (like __pycache__)
🚀 Getting Started
1. Clone the Repository
Bash
git clone https://github.com/Darshanr1903/Jouney-To-Faang-2026.git
cd Month1_work_track/todo_app
2. Set Up Virtual Environment
Bash
# Windows
python -m venv venv
.\venv\Scripts\activate

# macOS/Linux
python3 -m venv venv
source venv/bin/activate
3. Install Dependencies
Bash
pip install fastapi uvicorn sqlalchemy
4. Run the Application
Bash
uvicorn main:app --reload
The server will start at: http://127.0.0.1:8000

📖 Interactive API Docs
FastAPI automatically generates documentation for your routes. You can test your GET, POST, and DELETE requests directly here:

Swagger UI: http://127.0.0.1:8000/docs

ReDoc: http://127.0.0.1:8000/redoc

📝 Roadmap & Progress
[x] Initial Project Setup

[x] SQLite & SQLAlchemy Integration

[x] CRUD Operations for Todos

[ ] User Authentication (JWT)

[ ] Unit Testing with Pytest
