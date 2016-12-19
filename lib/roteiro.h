#ifndef ROTEIRO_H
#define ROTEIRO_H

#include <fstream>
#include <string>

namespace ed{

	class Roteiro{
		private:
			ifstream roteiro;
			Bst bst;
			Avl avl;
		
		public:
			Roteiro(const std::string caminho);
			~Roteiro();
			void executar();
	};

}

#endif
