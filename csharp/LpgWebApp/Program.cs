var builder = WebApplication.CreateSlimBuilder(args);

const string DOC_TITLE = "Language Playground: C#";

builder.Services.AddOpenApi("openapi", options => {
    options.AddDocumentTransformer((document, context, cancellationToken) =>
    {
        document.Info.Title = DOC_TITLE;
        return Task.CompletedTask;
    });
});

var app = builder.Build();

app.MapOpenApi(pattern: "/docs/{documentName}.json");
app.UseSwaggerUI(options => {
    options.DocumentTitle = DOC_TITLE;
    options.RoutePrefix = string.Empty;
    options.SwaggerEndpoint("/docs/openapi.json", "v1");
});

app.MapGet("/hello", () => Results.Ok(new {msg = "Hello, world!"}))
    .WithName("hello")
    .WithTags("exp");
app.MapPost("/ping", () => Results.Ok(new {msg = "pong"}))
    .WithName("ping")
    .WithTags("exp");;

app.Run();
