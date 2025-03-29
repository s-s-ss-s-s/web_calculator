# Dockerfile

FROM gcc:latest

# зависимости для Boost
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        libboost-all-dev \
        && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN make

EXPOSE 8080

CMD ["./app"]
