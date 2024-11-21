# compiler and flags
CXX = g++

all: build

build:
	mkdir -p build
	$(CXX) $(CXXFLAGS) ./src/main.cpp -o ./build/xeno

clean:
	rm -r build

run:
	./build/xeno.exe
