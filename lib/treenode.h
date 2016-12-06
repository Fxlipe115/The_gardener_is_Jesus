#ifndef TREENODE_H
#define TREENODE_H

namespace ed{

	class Bst;

	class TreeNode{
		private:
			int value;
			Bst* left;
			Bst* right;
			
		public:
			TreeNode(int value);
			virtual ~TreeNode();
			int getValue();
			void setValue(int value);
			Bst* getLeft();
			void setLeft(Bst* tree);
			Bst* getRight();
			void setRight(Bst* tree);
			void insert(int value);
			bool remove(int value, Bst* parent = nullptr);
			Bst* search(int value, Bst* tree, Bst** parent);
			int height();
			int nodeCount();
			int balanceFactor();
	};
		
}

#endif
