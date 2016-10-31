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
#include "binarytree.h"
#include "treenode.h"

namespace ed{

		class Bst: public BinaryTree{
			public:
				Bst();
				Bst(std::string path);
				void insert(int value);
		};

}

#endif
