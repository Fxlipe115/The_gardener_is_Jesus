#ifndef ROTEIRO_H
#define ROTEIRO_H

#include "bst.h"
#include "avl.h"
#include <fstream>
#include <string>

namespace ed{

	class Roteiro{
		private:
            std::ifstream roteiro;
            Bst bst;
            Avl avl;

		public:
			Roteiro(const std::string caminho);
			~Roteiro();
			void executar();
	};

}

#endif
