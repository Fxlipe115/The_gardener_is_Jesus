#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/

CC=g++ -std=c++11 -c

LINKER=g++

CFLAGS=-Wall -I./lib

SRC=$(wildcard src/*.cpp)

OBJ=$(addprefix bin/,$(notdir $(SRC:.cpp=.o)))

EXEC=main

all: $(OBJ)
	$(LINKER) -o $(EXEC) $^

bin/%.o: src/%.cpp
	$(CC) -o $@ $< $(CFLAGS) 

clean:
	rm 	bin/*.o
