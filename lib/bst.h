/************************
*
*	Arthur Zachow Coelho
*
*	Felipe de Almeida Graeff
*
************************/

#ifndef BST_H
#define BST_H

namespace graeff_zachow{

		class Node;
		class Bst;

		class Node{
			private:
				int value;
				Bst* left;
				Bst* right;
			public:
				Node(int value);
				~Node();
				int getValue();
				Bst* getLeft();
				Bst* getRight();
				void insert(int value);
				bool search(int value);
				int getLevelOf(int value);
		};

		class Bst{
			private:
				Node* node;
			public:
				Bst();
				~Bst();
				void insert(int value);
				bool isEmpty();
				int getValue();
				Bst* getLeft();
				Bst* getRight();
				bool search(int value);
				int getLevelOf(int value);
				bool pathExists(int start, int end);
		};

		bool compare(Bst* tree1, Bst* tree2);

}

#endif
