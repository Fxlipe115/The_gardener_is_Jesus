#ifndef BST_H
#define BST_H

#include <string>
#include "treenode.h"

namespace ed{

	class Bst{
		protected:
			TreeNode* node;
			void setValue(int value);
			void setLeftTree(Bst* tree);
			void setRightTree(Bst* tree);

		public:
			Bst();
			Bst(std::string path);
			virtual ~Bst();
			int access();
			Bst* leftTree();
			Bst* rightTree();
			virtual void insert(int value);
			virtual bool remove(int value);
			virtual bool remove(Bst* parent);
			virtual Bst* search(int value, Bst** parent = nullptr);
			bool isEmpty();
			Bst* bigger();
			Bst* smaller();
			int height();
			int nodeCount();
			int balanceFactor();
	};

}

#endif
