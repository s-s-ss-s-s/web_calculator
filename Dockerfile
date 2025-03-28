# Dockerfile

FROM gcc:latest

# Установить Boost
RUN apt-get update && \
    apt-get install -y libboost-all-dev && \
    apt-get clean

WORKDIR /app

COPY . .

RUN make

EXPOSE 8080

CMD ["./calculator"]