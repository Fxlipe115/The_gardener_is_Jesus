#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/


all: bst.o main.o
	g++ -o main main.o bst.o

files:
	g++ -o files files.o bst.o -std=c++11

main.o:
	g++ -c -o main.o main.cpp -std=c++11

bst.o:
	g++ -c -o bst.o bst.cpp -std=c++11

files.o:
	g++ -c -o files.o files.cpp -std=c++11

clean:
	rm *.o
