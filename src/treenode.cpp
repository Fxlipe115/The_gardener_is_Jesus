#include "treenode.h"
#include <omp.h>

template <class Tree>
ed::TreeNode<Tree>::TreeNode(int value): value(value), left(new Tree()), right(new Tree()) {}

template <class Tree>
ed::TreeNode<Tree>::~TreeNode(){
	delete left;
	delete right;
}

template <class Tree>
int ed::TreeNode<Tree>::getValue(){
	return value;
}

template <class Tree>
void ed::TreeNode<Tree>::setValue(int value){
	this->value = value;
}

template <class Tree>
Tree* ed::TreeNode<Tree>::getLeft(){
	return left;
}

template <class Tree>
void ed::TreeNode<Tree>::setLeft(Tree* tree){
	this->left = tree;
}

template <class Tree>
Tree* ed::TreeNode<Tree>::getRight(){
	return right;
}

template <class Tree>
void ed::TreeNode<Tree>::setRight(Tree* tree){
	this->right = tree;
}

template <class Tree>
void ed::TreeNode<Tree>::insert(int value, Tree* parent, int* rotations, int* comparisons){
	if(comparisons != nullptr)
		*comparisons += 1;
	if(value < this->value){
		left->insert(value, parent, rotations, comparisons);
	}else{
		right->insert(value, parent, rotations, comparisons);
	}
}

template <class Tree>
Tree* ed::TreeNode<Tree>::search(int value, Tree* tree, int* comparisons){
	if(value == this->value){
		return tree;
	}else{
		if(comparisons != nullptr)
			*comparisons += 1;
		return (value < this->value) ?
			left->search(value, comparisons) :
			right->search(value, comparisons);
	}
}

template <class Tree>
int ed::TreeNode<Tree>::height(){
	int lHeight = 0;
	int rHeight = 0;
	#pragma omp sections
	{
		#pragma omp section
		lHeight = left->height();
		#pragma omp section
		rHeight = right->height();
	}
	return (lHeight > rHeight) ? lHeight : rHeight;
}

template <class Tree>
int ed::TreeNode<Tree>::nodeCount(){
	return left->nodeCount() + right->nodeCount();
}

template <class Tree>
int ed::TreeNode<Tree>::balanceFactor(){
	int lHeight = 0;
	int rHeight = 0;
	#pragma omp sections
	{
		#pragma omp section
		lHeight = left->height();
		#pragma omp section
		rHeight = right->height();
	}
	return lHeight - rHeight;
}
