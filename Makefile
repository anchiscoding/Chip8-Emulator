CC=g++
CFLAGS= -Wall -Wextra -std=c++20 -I./includes
EXECUTABLE=emulator
INCLUDES=./includes
SRC=./src
OBJECTS= *.o
LINK = -lsfml-graphics -lsfml-window -lsfml-system 

.PHONY: clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LINK)


%.o : emulator.cpp $(SRC)/%.cpp
	$(CC) -c $(CFLAGS) $^


clean:
	rm *.o $(EXECUTABLE)
