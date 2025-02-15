# Stage 1: build
FROM mcr.microsoft.com/dotnet/sdk:9.0 AS build
WORKDIR /app

COPY ./LpgWebApp/LpgWebApp.csproj ./LpgWebApp/
RUN dotnet restore ./LpgWebApp/LpgWebApp.csproj

COPY . ./
RUN dotnet publish -o /out

# Stage 2: final
FROM mcr.microsoft.com/dotnet/aspnet:9.0-azurelinux3.0-distroless-composite AS final
WORKDIR /app
COPY --from=build /out .
ENTRYPOINT ["dotnet", "LpgWebApp.dll"]
