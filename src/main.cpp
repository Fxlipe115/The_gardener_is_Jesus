/************************
*
*	Arthur Zachow Coelho
*
*	Felipe de Almeida Graeff
*
************************/


#if defined (_WIN32) || defined (_WIN64)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


#include "bst.h"
#include "avl.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include "roteiro.h"

using namespace ed;

int main(int argc, char** argv){
	Roteiro roteiro(argv[1]);
	roteiro.executar();

	/*Bst bst;
	int comparacoes = 0;
	int rotacoes = 0;

	std::ifstream file(argv[1]);
	if(file.is_open()){
	    std::string file_content;
		    //Itera por todas as linhas
			    while(std::getline(file, file_content)) 
				        // Insere o valor na árvore
						        bst.insert(std::stoi(file_content),nullptr,&rotacoes,&comparacoes);
								    file.close();
	}
	std::cout << bst.nodeCount() << "\n";
	std::cout << comparacoes << "\n";
	std::cout << rotacoes << "\n";

	comparacoes = 0;
	rotacoes = 0;

	file.open(argv[2]);
	if(file.is_open()){
	    std::string file_content;
		    //Itera por todas as linhas
			    while(std::getline(file, file_content)) 
				        // Insere o valor na árvore
						        bst.remove(std::stoi(file_content),&rotacoes,&comparacoes);
								    file.close();
	}
	
	std::cout << bst.nodeCount() << "\n";
	std::cout << comparacoes << "\n";
	std::cout << rotacoes << "\n";*/

	return 0;
}  
