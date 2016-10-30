/************************
*
*	Arthur Zachow Coelho
*
*	Felipe de Almeida Graeff
*
************************/

#ifndef BST_H
#define BST_H

#include <string>
#include "treenode.h"

namespace ed{

		class Bst{
			private:
				treeNode<Bst>* node;
			public:
				Bst();
				Bst(std::string path);
				~Bst();				
				int getValue();
				Bst* getLeft();
				Bst* getRight();
				void insert(int value);
				bool remove(int value);
				bool search(int value);
				bool isEmpty();
				int height();
				int nodeCount();
				int balanceFactor();
		};

}

#endif
