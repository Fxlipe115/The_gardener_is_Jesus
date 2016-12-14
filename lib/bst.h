#ifndef BST_H
#define BST_H

#include <string>
#include "treenode.h"

namespace ed{

	class Bst{
		protected:
			Bst* parent;
			TreeNode<Bst>* node;
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
			virtual void insert(int value, Bst* parent = nullptr, int* rotations = nullptr, int* comparisons = nullptr);
			virtual bool remove(int value, int* rotations = nullptr, int* comparisons = nullptr);
			bool remove(int* rotations = nullptr, int* comparisons = nullptr);
			virtual Bst* search(int value, int* comparisons = nullptr);
			bool isEmpty();
			Bst* bigger();
			Bst* smaller();
			int height();
			int nodeCount();
			int getBalanceFactor();
	};

}

#endif
