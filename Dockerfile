# Dockerfile

FROM gcc:latest

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        libboost-all-dev \
        && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    libasio-dev

WORKDIR /app

COPY . .

RUN make

EXPOSE 8080

CMD ["./calculator"]
