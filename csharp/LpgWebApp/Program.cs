var builder = WebApplication.CreateSlimBuilder(args);

builder.Services.AddOpenApi();

var app = builder.Build();

app.MapOpenApi();

app.MapGet("/hello", () => Results.Ok(new {msg = "Hello, world!"}))
    .WithName("hello");
app.MapPost("/ping", () => Results.Ok(new {msg = "pong"}))
    .WithName("ping");

app.Run();
