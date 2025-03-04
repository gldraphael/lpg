# Stage 1: Build
FROM rust:slim-bookworm AS builder

RUN apt-get update && apt-get install -y \
    pkg-config \
    libssl-dev \
    curl \
    && rm -rf /var/lib/apt/lists/*

# User definition: only the 'nobody' user
WORKDIR /users
RUN cat /etc/passwd | grep nobody > passwd.nobody

WORKDIR /app
COPY ./.cargo ./.cargo
COPY Cargo.toml Cargo.lock ./
COPY ./src ./src
RUN cargo build --release

# Stage 2: Final
FROM scratch

LABEL org.opencontainers.image.source="https://github.com/gldraphael/lpg"
LABEL org.opencontainers.image.description="A simple language playground."

EXPOSE 8080

COPY --from=builder /users/passwd.nobody /etc/passwd
USER nobody

WORKDIR /app
COPY --from=builder /app/target/x86_64-unknown-linux-gnu/release/lpg /app/lpg

ENTRYPOINT ["./lpg"]
