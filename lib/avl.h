#ifndef AVL_H
#define AVL_H

#include "bst.h"

namespace ed{

	class Avl: public Bst{
		private:
			int balanceFactor;
			
		public:
			Avl();
			Avl(std::string path);
			void insert(int value);
			bool remove(int value, Bst* parent = nullptr);
	};

}

#endif