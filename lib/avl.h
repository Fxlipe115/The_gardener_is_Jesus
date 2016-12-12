#ifndef AVL_H
#define AVL_H

#include <string>
#include "bst.h"

namespace ed{

	class Avl: public Bst{
		private:
			int balanceFactor;
			
		public:
			Avl();
			void insert(int value, Bst* parent = nullptr) override;
			bool remove() override;
			void rotate();
	};

}

#endif
