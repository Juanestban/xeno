all: build

build:
	mkdir build
	g++ ./src/main.cpp -o ./build/main

clean:
	rm -r build

run:
	./build/main.exe