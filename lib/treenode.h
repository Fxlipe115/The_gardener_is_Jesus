#ifndef TREENODE_H
#define TREENODE_H

#include "binarytree.h"

namespace ed{

		class treeNode{
			private:
				int value;
				binaryTree* left;
				BinaryTree* right;
				
			public:
				treeNode(int value);
				int getValue();
				//TODO
		};
		
}

#endif
