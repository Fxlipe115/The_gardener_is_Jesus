#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/

CC=g++ -std=c++11 -c

LINKER=g++

CFLAGS=-Wall -I./lib -fopenmp

LFLAGS=-lgomp

SRC=$(wildcard src/*.cpp)

OBJ=$(addprefix bin/,$(notdir $(SRC:.cpp=.o)))

EXEC=main

all: $(OBJ)
	$(LINKER) -o $(EXEC) $^ $(LFLAGS)

bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CC) -o $@ $< $(CFLAGS) 

clean:
	rm 	bin/*.o
