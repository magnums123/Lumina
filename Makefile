CXX = g++

CXXFLAGS = -std=c++23 -g \
	-Wall -Wextra -Wpedantic -Wshadow -Wconversion \
	-fsanitize=address,undefined \
	-Iexternal/glad/include -Isrc -Iexternal

LDFLAGS = -lglfw -lGL -ldl \
	-fsanitize=address,undefined

SRC = $(shell find src -name "*.cpp") external/glad/src/glad.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = LuminaEngine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
