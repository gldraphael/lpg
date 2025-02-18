package main

import (
	"context"
	"fmt"
	"log"
	"net/http"

	"github.com/alecthomas/kong"
	kongyaml "github.com/alecthomas/kong-yaml"
	"github.com/danielgtaylor/huma/v2"
	"github.com/danielgtaylor/huma/v2/adapters/humago"
)

var config struct {
	Port int `required:"" default:"8080" env:"LPG_PORT"`
}


type MessageOutput struct {
	Body struct {
		Message string `json:"msg" example:"Hello, world!" doc:"A generic message"`
	}
}


func main() {
	kong.Parse(&config, kong.Configuration(kongyaml.Loader, "./config.yaml"))

	router := http.NewServeMux()
	humaConfig := huma.DefaultConfig("Language Playground: Go", "0.1.0")
	humaConfig.DocsPath = "" // disable default docs
	humaConfig.OpenAPIPath = "/docs/openapi"
	api := humago.New(router, humaConfig)

	huma.Register(api, huma.Operation{
		Method:      http.MethodGet,
		Path:        "/hello",
		Tags:        []string{"exp"},
	}, func(ctx context.Context, input *struct{}) (*MessageOutput, error) {
		resp := &MessageOutput{}
		resp.Body.Message = "Hello, world!"
		return resp, nil
	})

	huma.Register(api, huma.Operation{
		Method:      http.MethodPost,
		Path:        "/ping",
		Tags:        []string{"exp"},
	}, func(ctx context.Context, input *struct{}) (*MessageOutput, error) {
		resp := &MessageOutput{}
		resp.Body.Message = "pong"
		return resp, nil
	})


	router.HandleFunc("GET /", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "text/html")
		w.Write([]byte(`<!DOCTYPE html>
	<html lang="en">
	<head>
	  <meta charset="utf-8" />
	  <meta name="viewport" content="width=device-width, initial-scale=1" />
	  <meta name="description" content="Language Playground: Go" />
	  <title>Language Playground: Go</title>
	  <link rel="stylesheet" href="https://unpkg.com/swagger-ui-dist@5.19.0/swagger-ui.css" />
	</head>
	<body>
	<div id="swagger-ui"></div>
	<script src="https://unpkg.com/swagger-ui-dist@5.19.0/swagger-ui-bundle.js" crossorigin></script>
	<script>
	  window.onload = () => {
		window.ui = SwaggerUIBundle({
		  url: '/docs/openapi.json',
		  dom_id: '#swagger-ui',
		});
	  };
	</script>
	</body>
	</html>`))
	})
	
    log.Fatal(http.ListenAndServe(fmt.Sprint(":",config.Port), router))
}
