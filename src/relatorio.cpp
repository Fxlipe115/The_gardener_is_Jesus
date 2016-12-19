#include "relatorio.h"
#include <fstream>
#include <string>

ed::Relatorio::Relatorio(): tree(""), operacao(""), tempo(0), nodos(0), 
			altura(0), fator(0), 
			comparacoes(0), rotacoes(0) {}

bool ed::Relatorio::save(){
	std::string path = "relatorio";
	path << tree << ".txt";

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
