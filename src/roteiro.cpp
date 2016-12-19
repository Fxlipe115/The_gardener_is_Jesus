#include "avl.h"
#include "roteiro.h"
#include <stdexcept>
#include <time.h>

ed::Roteiro::Roteiro(const std::string caminho): avl(ed::Avl()), bst(ed::Bst()){
	try{
		roteiro.open(caminho);
	}catch(...){
		throw std::invalid_argument("Arquivo nao encontrado");
	}
}

ed::Roteiro::~Roteiro(){
	roteiro.close();
}

void ed::Roteiro::executar(){
	std::string comando;
	int comparacoesBst = 0, comparacoesAvl = 0, rotacoes = 0;
	clock_t start, end, elapsed;

	while(roteiro >> comando){
		if(comando.compare("I")){
			comparacoesBst = 0;
			comparacoesAvl = 0;
			rotacoes = 0;
			
			//pega nome do arquivo
			std::string arquivo;
			roteiro >> arquivo;

			std::ifstream file(arquivo);

			if(file.is_open()){
				std::string file_content;
				start = clock();
				//Itera por todas as linhas
				while(std::getline(file, file_content)) {
					// Procura o valor na árvore
					bst.insert(std::stoi(file_content), nullptr, nullptr, &comparacoesBst);
					//avl.insert(std::stoi(file_content), nullptr, &rotacoes, &comparacoesAvl);
				}
				end = clock();
				file.close();	
				elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC);
			}

		}else if(comando.compare("C")){
			comparacoesBst = 0;
			comparacoesAvl = 0;
			rotacoes = 0;
			
			//pega nome do arquivo
			std::string arquivo;
			roteiro >> arquivo;
			
			std::ifstream file(arquivo);
	
			if(file.is_open()){
				std::string file_content;
				start = clock();
				//Itera por todas as linhas
				while(std::getline(file, file_content)) {
					// Insere o valor na árvore
					bst.search(std::stoi(file_content), &comparacoesBst);
					//avl.search(std::stoi(file_content), &comparacoesAvl);
				}
				end = clock();
				file.close();	
				elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC);
			}
			
		}else if(comando.compare("R")){
			comparacoesBst = 0;
			comparacoesAvl = 0;
			rotacoes = 0;
			
			//pega nome do arquivo
			std::string arquivo;
			roteiro >> arquivo;
			
			std::ifstream file(arquivo);
	
			if(file.is_open()){
				std::string file_content;
				start = clock();
				//Itera por todas as linhas
				while(std::getline(file, file_content)) {
					// Remove o valor na árvore
					bst.remove(std::stoi(file_content), nullptr, &comparacoesBst);
					//avl.remove(std::stoi(file_content), &rotacoes, &comparacoesAvl);
				}
				end = clock();
				file.close();	
				elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC);
			}
			
		}else if(comando.compare("E")){
			Relatorio relatorioAbp("ABP", elapsed, bst.nodeCount(), bst.height(), bst.getBalanceFactor(), comparacoesBst, 0);
			Relatorio relatorioAvl("AVL", elapsed, avl.nodeCount(), avl.height(), avl.getBalanceFactor(), comparacoesAvl, rotacoes);
			relatorioAbp.save();
			relatorioAvl.save();
		}
	}
}
