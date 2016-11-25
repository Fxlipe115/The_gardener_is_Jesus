#ifndef RELATORIO_H
#define RELATORIO_H

namespace ed{

	class Relatorio{
		private:
			int tempo;
			int nodos;
			int altura;
			int fator;
			int comparacoes;
			int rotacoes;

		public:
			Relatorio();
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
	};
}

#endif
