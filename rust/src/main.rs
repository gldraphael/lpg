use axum::{
    routing::{get, post},
    http::StatusCode,
    Json, Router,
};
use serde::Serialize;

#[tokio::main]
async fn main() {
    // initialize tracing
    tracing_subscriber::fmt::init();

    // build our application with a route
    let app = Router::new()
        .route("/hello", get(hello))
        .route("/ping", post(ping));

    // run our app with hyper, listening globally on port 3000
    let listener = tokio::net::TcpListener::bind("0.0.0.0:3000").await.unwrap();
    axum::serve(listener, app).await.unwrap();
}

async fn hello() -> (StatusCode, Json<Message>) {
    (StatusCode::OK, Json(Message {
        msg: "Hello, world!".to_string()
    }))
}

async fn ping() -> (StatusCode, Json<Message>) {
    (StatusCode::OK, Json(Message {
        msg: "pong".to_string()
    }))
}


#[derive(Serialize)]
struct Message {
    msg: String
}
