#ifndef AVL_H
#define AVL_H

#include <string>
#include "bst.h"

namespace ed{

	class Avl: public Bst{
		private:
			TreeNode<Avl>* node;
			int balanceFactor;
			
		public:
			Avl();
			void insert(int value, Bst* parent = nullptr, int* rotations = nullptr, int* comparisons = nullptr) override;
			bool remove(int value, int* rotations = nullptr, int* comparisons = nullptr) override;
			void rotateR();
			void rotateL();
	};

}

#endif
