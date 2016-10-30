#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/


all: files.o bst.o main.o
	g++ -o main main.o bst.o files.o

main.o:
	g++ -o main.o -c main.cpp -std=c++11

bst.o:
	g++ -o bst.o -c bst.cpp -std=c++11

files.o:
	g++ -o files.o -c files.cpp -std=c++11

clean:
	rm *.o
