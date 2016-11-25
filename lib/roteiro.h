#ifndef ROTEIRO_H
#define ROTEIRO_H

#include <fstream>
#include <string>

namespace ed{

	class Roteiro{
		private:
			ifstream roteiro;
		
		public:
			Roteiro(const std::string caminho);
			~Roteiro();
			bool executar();
			bool proxima();
	};

}

#endif
