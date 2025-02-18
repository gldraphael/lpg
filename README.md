# Language playground



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

## Support Matrix

|                       | C# | Go | Python |   |
|-----------------------|----|----|--------|---|
| Hello API             | ✅ | ✅ | ✅   |   |
| Open API & Swagger UI | ✅ | ✅ | ✅   |   |
| Dev container         | ✅ | ✅ | ✅   |   |
| Dependency management | ✅ | ✅ | ✅   |   |
| Configuration         | ✅ | ✅ | ✅   |   |
| Structured logging    |    |    |        |   |
| Docker container      | ✅ | ✅ |  ✅  |   |
| Helm chart            |    |    |        |   |
| CI pipelines          |    |    |        |   |
| Health checks         |    |    |        |   |

For more information, refer to the [spec](./spec.md).

