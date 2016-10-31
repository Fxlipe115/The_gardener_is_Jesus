#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "treenode.h"

namespace ed{

	class BinaryTree{
		protected:
			TreeNode* node;
		public:
			BinaryTree();
			BinaryTree(std::string path);
			~BinaryTree();
			int getValue();
			BinaryTree* getLeft();
			BinaryTree* getRight();
			virtual void insert(int value) = 0;
			bool remove(int value);
			bool search(int value);
			bool isEmpty();
			int height();
			int nodeCount();
			int balanceFactor();
	};

}

#endif
