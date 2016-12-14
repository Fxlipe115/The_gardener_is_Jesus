#ifndef TREENODE_H
#define TREENODE_H

namespace ed{

	template <class Tree>
	class TreeNode{
		private:
			int value;
			Tree* left;
			Tree* right;
			
		public:
			TreeNode(int value);
			virtual ~TreeNode();
			int getValue();
			void setValue(int value);
			Tree* getLeft();
			void setLeft(Tree* tree);
			Tree* getRight();
			void setRight(Tree* tree);
			void insert(int value, Tree* parent, int* rotations = nullptr, int* comparisons = nullptr);
			Tree* search(int value, Tree* tree, int* comparisons = nullptr);
			int height();
			int nodeCount();
			int balanceFactor();
	};
		
}

#endif
