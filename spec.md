# Spec

Every language must implement the following features:

## Hello API


#### 1. `GET /hello`
**Request:**
```http
GET /hello
```
**Response:**
```json
{"msg": "Hello, world!"}
```

#### 2. `POST /ping`
**Request:**
```http
GET /ping
```
**Response:**
```json
{"msg": "pong"}
```

## Open API doc & Swagger UI

The implementation must:

1. expose an Open API doc at `/docs/openapi.json`,
1. tag the "Hello API" endpoints with `exp`,
1. and display swagger UI at the root (or redirect to a page with swagger UI from the root)

## Dev Container

Each implementation must be setup such that users can open the language implementation folder within a [development container](https://containers.dev/) and be able to develop, run, and debug the code in that environment.

## Dependency management

Each implementation must pin or clearly specify direct & indirect dependencies as is idiomatic in that language.

## Configuration

Each implementation must support overriding configuration externally using config files or environment variables or both.

## Structured logging

Each implementation must support structured logging. (TODO: elaborate)

## Docker support

Each implementation must include 

1. a `Dockerfile` that makes it possible to run the implementation in a container,
1. Docker compose support to make it easy to run the implementation locally.

## Helm chart

Each implementation must provide a corresponding helm chart to make it easy to install the implementation to a Kubernetes environment.

## CI pipelines

Each implementation must include GitHub action workflows for the following:

1. To build a docker image, and optionally publish it to `ghcr`.
1. To publish the helm chart as an OCI artifact to `ghcr`.

## Health checks

Each implementation must expose health check endpoints.
