#ifndef TREENODE_H
#define TREENODE_H

#include "bst.h"

namespace ed{

	class TreeNode{
		private:
			int value;
			Bst* left;
			Bst* right;
			
		public:
			TreeNode(int value);
			int getValue();
			Bst* getLeft();
			Bst* getRight();
			void insert(int value);
			bool remove(int value, Bst* parent = nullptr);
			bool search(int value);
			int height();
			int nodeCount();
			int balanceFactor();
	};
		
}

#endif
