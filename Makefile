# compiler and flags
CC=g++
AR=ar

ifeq ($(DEBUG),yes)
  CXXFLAGS=-Iheader -Wall -ggdb
else
  CXXFLAGS=-Iheader -O2
endif

# DIRECTORIES
SRC_DIR=src
BUILD_DIR=build

SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
HEADERS = $(shell find $(SRC_DIR) -name '*.hpp')
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# sub_directories
BUILD_SUBDIRS = $(sort $(dir $(OBJECTS)))

# target
all: $(BUILD_DIR)/xeno

# compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | prepare_build_dir
	$(CC) $(CXXFLAGS) -c $< -o $@

# build directory
prepare_build_dir:
	mkdir -p $(BUILD_SUBDIRS)

# link the final executable
$(BUILD_DIR)/xeno: $(OBJECTS) | prepare_build_dir
	$(CC) $(OBJECTS) -o $@


debug:
	@echo "Sources: $(SOURCES)"
	@echo "Headers: $(HEADERS)"
	@echo "Objects: $(OBJECTS)"
	@echo "Build sub directories: $(BUILD_SUBDIRS)"

test:
	./build/xeno.exe ./src/main.xn

clean:
	rm -r build
  $(shell find -name â€™*~â€™ -delete)
# $(RM) .*.o *.a main

run:
	./build/xeno.exe
