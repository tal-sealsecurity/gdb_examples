FROM debian:13

RUN apt-get update && apt-get install -y \
    vim \
    gdb \
    file \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

CMD ["bash"]