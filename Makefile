CXX = g++
CXXFLAGS =  -g -std=c++23 -Iexternal/glad/include -Isrc -Iexternal #-Wall -Wextra 
LDFLAGS = -lglfw -lGL -ldl

SRC = $(shell find src -name "*.cpp") external/glad/src/glad.c
OBJ = $(SRC:.cpp=.o)

TARGET = LuminaEngine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
