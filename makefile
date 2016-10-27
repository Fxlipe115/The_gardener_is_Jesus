#/************************
#*
#*	Arthur Zachow Coelho
#*
#*	Felipe de Almeida Graeff
#*
#************************/


all: bst.o main.o
	g++ -o main main.o bst.o

main.o: main.cpp
	g++ -c -o main.o main.cpp -std=c++11

bst.o: bst.cpp
	g++ -c -o bst.o bst.cpp -std=c++11

clean:
	rm *.o
