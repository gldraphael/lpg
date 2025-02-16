from fastapi import FastAPI

app = FastAPI(
    title= 'Language Playground: Python',
    docs_url= '/',
    openapi_url= '/docs/openapi.json'
)

@app.get("/hello", tags=["exp"])
def hello():
    return {"msg": "Hello, world!"}

@app.post("/ping", tags=["exp"])
def ping():
    return {"msg": "pong"}


