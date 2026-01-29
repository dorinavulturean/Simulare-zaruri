FROM gcc:13
WORKDIR /app
COPY . .
RUN g++ -std=c++17 -O2 -o dice main.cpp
CMD ["./dice"]
