FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ cmake

WORKDIR /app
COPY . .
RUN mkdir -p build && cd build && cmake .. && cmake --build .

CMD ["./build/sorting", "0", "tests/input.txt"]
