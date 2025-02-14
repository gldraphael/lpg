### Build
FROM golang:1.23 AS build

# User definition: only the 'nobody' user
WORKDIR /users
RUN cat /etc/passwd | grep nobody > passwd.nobody

# Source
WORKDIR /build
ADD go.mod . 
# ADD go.mod go.sum
RUN go mod download

ADD . .

# Compile
RUN CGO_ENABLED=0 go build -o app .


### Run
FROM scratch

COPY --from=build /users/passwd.nobody /etc/passwd
USER nobody

COPY --from=build /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/
COPY --from=build /build/app .

CMD ["./app"]
