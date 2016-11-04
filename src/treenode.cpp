#include "treenode.h"
#include "bst.h"

ed::TreeNode::TreeNode(int value): value(value), left(new Bst()), right(new Bst()) {}

ed::TreeNode::~TreeNode(){
	delete left;
	delete right;
}

int ed::TreeNode::getValue(){
	return value;
}

ed::Bst* ed::TreeNode::getLeft(){
	return left;
}

ed::Bst* ed::TreeNode::getRight(){
	return right;
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

bool ed::TreeNode::search(int value){
	if(value == this->value){
		return true;
	}else{
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int ed::TreeNode::height(){
	int lHeight = left->height();
	int rHeight = right->height();
	return (lHeight > rHeight) ?
		lHeight :
		rHeight;
}

int ed::TreeNode::nodeCount(){
	return left->nodeCount() + right->nodeCount();
}

int ed::TreeNode::balanceFactor(){
	int lHeight = left->height();
	int rHeight = right->height();
	return lHeight - rHeight;
}
