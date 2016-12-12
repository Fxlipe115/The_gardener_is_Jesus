#ifndef BST_H
#define BST_H

#include <string>
#include "treenode.h"

namespace ed{

	class Bst{
		protected:
			Bst* parent;
			TreeNode* node;
			void setValue(int value);
			void setLeftTree(Bst* tree, Bst* parent = nullptr);
			void setRightTree(Bst* tree, Bst* parent = nullptr);

		public:
			Bst();
			Bst(std::string path);
			virtual ~Bst();
			void setParent(Bst* parent);
			Bst* getParent();
			int access();
			Bst* leftTree();
			Bst* rightTree();
			virtual void insert(int value, Bst* parent = nullptr);
			virtual bool remove(int value);
			virtual bool remove();
			virtual Bst* search(int value);
			bool isEmpty();
			Bst* bigger();
			Bst* smaller();
			int height();
			int nodeCount();
			int balanceFactor();
	};

}

#endif
