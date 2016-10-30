#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/

CC=g++ -c

LINKER=g++

FLAGS=-Wall -std=c++11 -I'include'

SRC=$(wildcard src/*.c)

OBJ=$(SRC:.c=.o)

EXEC=main

all: $(OBJ)
	$(LINKER) -o $(EXEC) $<

$(OBJ): $(SRC)
	$(CC) -o $@ -c $< $(CFLAGS) 

clean:
	rm 	src/*.o
