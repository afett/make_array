TARGET=test_make_array

CXX ?= g++
CXXFLAGS=-Wall -Werror -Wextra -std=c++11
CPPFLAGS=
LDFLAGS=

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -rf  $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean


