CC = g++
CFLAGS = -Wall -Iinclude -mconsole -std=c++11
LFLAGS = -mconsole -mwindows
SRC = src/Vector.cpp src/Matrix.cpp src/LinearSystem.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LFLAGS)

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXEC)

run:
	./$(EXEC)