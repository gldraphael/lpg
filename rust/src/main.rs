use std::{io::Error, net::{Ipv4Addr, SocketAddr}};
use axum;
use tokio::net::TcpListener;
use utoipa::OpenApi;
use utoipa_axum::router::OpenApiRouter;
use utoipa_swagger_ui::SwaggerUi;

pub mod api;

const HELLO_API_TAG: &str = "exp";

#[tokio::main]
async fn main() -> Result<(), Error> {
    #[derive(OpenApi)]
    #[openapi(
        tags(
            (name = HELLO_API_TAG, description = "The Hello API")
        ),
        info(
            title = "Language Playground: Rust"
        )
    )]
    struct ApiDoc;

    let (router, api) = OpenApiRouter::with_openapi(ApiDoc::openapi())
        .merge(api::hello_api::router())
        .split_for_parts();

    let router = router
        .merge(SwaggerUi::new("/").url("/docs/openapi.json", api.clone()));

    let address = SocketAddr::from((Ipv4Addr::UNSPECIFIED, 8080));
    let listener = TcpListener::bind(&address).await?;
    axum::serve(listener, router.into_make_service()).await
}
