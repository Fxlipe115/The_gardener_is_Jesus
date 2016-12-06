#include "treenode.h"
#include "bst.h"
#include <omp.h>

ed::TreeNode::TreeNode(int value): value(value), left(new Bst()), right(new Bst()) {}

ed::TreeNode::~TreeNode(){
	delete left;
	delete right;
}

int ed::TreeNode::getValue(){
	return value;
}

void ed::TreeNode::setValue(int value){
	this->value = value;
}

ed::Bst* ed::TreeNode::getLeft(){
	return left;
}

void ed::TreeNode::setLeft(Bst* tree){
	this->left = tree;
}

ed::Bst* ed::TreeNode::getRight(){
	return right;
}

void ed::TreeNode::setRight(Bst* tree){
	this->right = tree;
}

void ed::TreeNode::insert(int value){
	if(value < this->value){
		left->insert(value);
	}else{
		right->insert(value);
	}
}

bool ed::TreeNode::remove(int value, Bst* parent){
	//TODO
	return true;
}

ed::Bst* ed::TreeNode::search(int value, Bst* tree, Bst** parent){
	if(value == this->value){
		return tree;
	}else{
		*parent = tree;
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int ed::TreeNode::height(){
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

int ed::TreeNode::nodeCount(){
	return left->nodeCount() + right->nodeCount();
}

int ed::TreeNode::balanceFactor(){
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
