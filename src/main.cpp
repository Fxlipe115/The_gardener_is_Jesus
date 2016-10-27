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
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

using namespace graeff_zachow;

void inserirMenu(Bst* abp);
void buscaMenu(Bst* abp);
void caminhoMenu(Bst* abp);
void compararMenu(Bst* abp);
void erro(std::string mensagem);

int main(void){
    int op = 0;
	bool sair = false;
	Bst abp[2];

	while(!sair){
		std::system(CLEAR);
		std::cout << "1 - Inserir nodo na ABP; 2 - Busca em ABP; 3 - Caminho entre 2 valores; 4 - Comparar ABP's; 0 -  Sair" << std::endl;
		std::cin >> op;
		
		switch(op){
			case 0:
				sair = true;
				break;
			case 1:
				inserirMenu(abp);
				break;
			case 2:
				buscaMenu(abp);
				break;
			case 3:
				caminhoMenu(abp);
				break;
			case 4:
				compararMenu(abp);
				break;
			default:
				erro("Opcao invalida.");
				break;
		 }
	}

    std::system(CLEAR);
    return 0;
}

void inserirMenu(Bst* abp){
	std::system(CLEAR);

	int valor = 0, index = 0;
	
	std::cout << "Informe o valor a ser inserido: ";
	std::cin >> valor;
	std::cout << "Informe em qual ABP deseja inserir o valor " << valor << "(1 ou 2): ";
	std::cin >> index;
	
	if(index > 0 && index < 3){
		abp[index-1].insert(valor);
	}else{
		erro("ABP inexistente.");
	}
}

void buscaMenu(Bst* abp){
	std::system(CLEAR);
	
	int valor = 0, index = 0;
	
	std::cout << "Informe o valor a ser procurado: ";
	std::cin >> valor;
	std::cout << "Informe em qual ABP deseja procurar o valor " << valor << "(1 ou 2): ";
	std::cin >> index;
	
	if(index > 0 && index < 3){
		try{
			std::system(CLEAR);
			std::cout << valor << " esta no nivel " << abp[index-1].getLevelOf(valor) << std::endl;
			std::cout << std::endl << "Pressione ENTER para continuar...";
			std::cin.ignore(256,'\n');
			std::cin.get();
		}catch(...){
			erro("Valor nao encontrado.");
		}
	}else{
		erro("ABP inexistente.");
	}
}

void caminhoMenu(Bst* abp){
	std::system(CLEAR);
	
	int inicio = 0, fim = 0, index = 0;
	
	std::cout << "Informe o valor a inicial: ";
	std::cin >> inicio;
	std::cout << "Informe o valor a final: ";
	std::cin >> fim;
	std::cout << "Informe em qual ABP deseja fazer a verificacao(1 ou 2): ";
	std::cin >> index;
	
	if(index > 0 && index < 3){
		std::system(CLEAR);
		try{
			if(abp[index-1].pathExists(inicio, fim)){
				std::cout << "Existe um caminho de " << inicio << " ate " << fim << "." << std::endl;
			}else{
				std::cout << "Nao existe um caminho de " << inicio << " ate " << fim << "." << std::endl;
			}
			std::cout << std::endl << "Pressione ENTER para continuar...";
			std::cin.ignore(256,'\n');
			std::cin.get();	
		}catch(...){
			erro("Valor de inicio nao encontrado.");
		}
	}else{
		erro("ABP inexistente.");
	}
}

void compararMenu(Bst* abp){
	std::system(CLEAR);
	
	if(compare(&abp[0], &abp[1])){
		std::cout << "As ABP's sao iguais." << std::endl;
	}else{
		std::cout << "As ABP's sao diferentes." << std::endl;
	}
	std::cout << std::endl << "Pressione ENTER para continuar...";
	std::cin.ignore(256,'\n');
	std::cin.get();
}

void erro(std::string mensagem){
	std::system(CLEAR);
	
	std::cout << "ERRO: " << mensagem << std::endl;
	
	std::cout << std::endl << "Pressione ENTER para continuar...";
	std::cin.ignore(256,'\n');
	std::cin.get();
}
