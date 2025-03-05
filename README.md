# Language playground



## Run with docker compose

```sh
docker compose build
docker compose up
```

This will expose the services at different ports as follows:

Service  | Port
---------|-------
`csharp` | 8181
`go`     | 8182
`python` | 8183
`python` | 8184

## Support Matrix

|                       | C++ | C# | Go | Python | Rust |
|-----------------------|-----|----|----|--------|------|
| Hello API             | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Open API & Swagger UI | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Dev container         | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Dependency management | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Configuration         | ❌ | ✅ | ✅ |  ✅   |  ❌  |
| Structured logging    | ❌ | ❌ | ❌ |  ❌   |  ❌  |
| Docker container      | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Helm chart            | ❌ | ❌ | ❌ |  ❌   |  ❌  |
| CI pipelines          | ✅ | ✅ | ✅ |  ✅   |  ✅  |
| Health checks         | ❌ | ❌ | ❌ |  ❌   |  ❌  |

For more information, refer to the [spec](./spec.md).

