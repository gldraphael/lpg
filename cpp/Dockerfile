# Stage 1: Build
FROM ubuntu:plucky AS builder

RUN apt-get update && apt-get install -y \
    pkg-config \
    libssl-dev \
    curl \
    build-essential \
    cmake \
    git \
    zip unzip tar \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/microsoft/vcpkg.git \
    && cd vcpkg \
    && ./bootstrap-vcpkg.sh
ENV VCPKG_ROOT=/vcpkg
ENV PATH=$VCPKG_ROOT:$PATH


# User definition: only the 'nobody' user
WORKDIR /users
RUN cat /etc/passwd | grep nobody > passwd.nobody

WORKDIR /app
COPY vcpkg-configuration.json vcpkg.json ./
RUN vcpkg install

COPY CMakeLists.txt CMakePresets.json ./
COPY ./src ./src
RUN cmake --preset release \
    && cmake --build --preset release

# Stage 2: Final
FROM scratch AS final

LABEL org.opencontainers.image.source="https://github.com/gldraphael/lpg"
LABEL org.opencontainers.image.description="A simple language playground."

EXPOSE 8080

COPY --from=builder /users/passwd.nobody /etc/passwd
USER nobody

WORKDIR /app
COPY --from=builder /app/out/build/release/lpg  .
COPY --from=builder /app/out/build/release/res/ ./res
ENTRYPOINT ["./lpg"]
