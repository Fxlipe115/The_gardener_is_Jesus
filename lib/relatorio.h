#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>

namespace ed{

	class Relatorio{
		private:
			std::string tree;
			std::string operacao;
			int tempo;
			int nodos;
			int altura;
			int fator;
			int comparacoes;
			int rotacoes;

		public:
			Relatorio(std::string tree, std::string operacao, int tempo, int nodos, int altura, int fator, int comparacoes, int rotacoes);
			void setTempo(int tempo);
			int getTempo();
			void setNodos(int nodos);
			int getNodos();
			void setAltura(int altura);
			int getAltura();
			void setFator(int fator);
			int getFator();
			void setComparacoes(int comparacoes);
			int getComparacoes();
			void setRotacoes(int rotacoes);
			int getRotacoes();
			void print();
			bool save();
	};
}

#endif
