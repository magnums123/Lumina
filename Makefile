CXX = g++
CXXFLAGS =  -g -std=c++23 -Wall -Wextra -Iexternal/glad/include -Isrc
LDFLAGS = -lglfw -lGL -ldl

SRC = $(shell find src -name "*.cpp") external/glad/src/glad.c
OBJ = $(SRC:.cpp=.o)

TARGET = engine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
