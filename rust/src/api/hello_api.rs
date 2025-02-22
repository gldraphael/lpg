use axum::{
    http::StatusCode, Json
};
use serde::Serialize;
use utoipa::ToSchema;
use utoipa_axum::{router::OpenApiRouter, routes};

pub(crate) fn router() -> OpenApiRouter {
    OpenApiRouter::new()
        .routes(routes!(hello, ping))
}


#[utoipa::path(
    get,
    path = "/hello",
    responses(
        (status = 200, body = [Message])
    )
)]
async fn hello() -> (StatusCode, Json<Message>) {
    (StatusCode::OK, Json(Message {
        msg: "Hello, world!".to_string()
    }))
}

#[utoipa::path(
    post,
    path = "/ping",
    responses(
        (status = 200, body = [Message])
    )
)]
async fn ping() -> (StatusCode, Json<Message>) {
    (StatusCode::OK, Json(Message {
        msg: "pong".to_string()
    }))
}


#[derive(Serialize, ToSchema)]
struct Message {
    msg: String
}
