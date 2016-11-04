#ifndef BST_H
#define BST_H

#include <string>
#include "binarytree.h"
#include "treenode.h"

namespace ed{

	class Bst{
		protected:
			TreeNode* node;
			
		public:
			Bst();
			Bst(std::string path);
			~Bst();
			int access();
			Bst* leftTree();
			Bst* rightTree();
			virtual void insert(int value);
			virtual bool remove(int value, Bst* parent = nullptr);
			virtual bool search(int value);
			bool isEmpty();
			int bigger();
			int smaller();
			int height();
			int nodeCount();
			int balanceFactor();
	};

}

#endif
