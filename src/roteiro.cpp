#include "roteiro.h"
#include <stdexcept>

ed::Roteiro::Roteiro(const std::string caminho){
	try{
		roteiro.open(caminho);
	}catch(...){
		throw std::invalid_argument("Arquivo nao encontrado");
	}
}

ed::Roteiro::~Roteiro(){
	roteiro.close();
}
