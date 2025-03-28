# Используем официальный образ для C++
FROM gcc:latest

# Установка библиотек Boost
RUN apt-get update && \
    apt-get install -y libboost-all-dev

# Копируем файлы проекта в контейнер
WORKDIR /app
COPY . .

# Собираем проект
RUN make

# Открываем порт для доступа к сервер