from fastapi import FastAPI

app = FastAPI()


@app.get("/hello")
def hello():
    return {"msg": "Hello, world!"}

@app.post("/ping")
def ping():
    return {"msg": "pong"}

