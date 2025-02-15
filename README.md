# Language playground



## Matrix


|                       | C# | Go | Python |   |
|-----------------------|----|----|--------|---|
| Hello API             | ✅ | ✅ | ✅   |   |
| Dev container setup   | ✅ | ✅ | ✅   |   |
| Dependency management | ✅ | ✅ | ✅   |   |
| Configuration         | ✅ | ✅ | ✅   |   |
| Structured logging    |    |    |        |   |
| Docker container      | ✅ | ✅ |  ✅  |   |
| Helm chart            |    |    |        |   |
| CI pipelines          |    |    |        |   |
| Health checks         |    |    |        |   |

## Run with docker compose

```sh
docker compose build
docker compose up
```

This will expose the services at different ports as follows:

Service  | Port
---------|-------
`csharp` | 8081
`go`     | 8082
`python` | 8083
