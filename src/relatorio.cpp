#include "relatorio.h"
#include <fstream>
#include <string>

ed::Relatorio::Relatorio(std::string tree, std::string operacao, int tempo, int nodos, int altura, int fator, int comparacoes, int rotacoes): tree(tree), operacao(operacao), tempo(tempo), nodos(nodos), altura(altura), fator(fator), comparacoes(comparacoes), rotacoes(rotacoes) {}

bool ed::Relatorio::save(){
	std::string path = "relatorio";
	path += tree;
	path += ".txt";

	std::ofstream file(path);

	if(file.is_open()){
		file << "Relatorio de " << tree << "\n\n";
		file << "Operacao: " << operacao << "\n";
		file << "Tempo: " << tempo << "\n";
		file << "Nodos: " << nodos << "\n";
		file << "Altura: " << altura << "\n";
		file << "Fator: " << fator << "\n";
		file << "Comparacoes: " << comparacoes << "\n";
		file << "Rotacoes: " << rotacoes << "\n";


		file.close();
		return true;
	}else{
		return false;
	}
}
