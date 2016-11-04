#include "treenode.h"
#include "bst.h"

ed::treeNode::treeNode(int value): value(value), left(new Bst()), right(new Bst()) {}

ed::treeNode::~treeNode(){
	delete left;
	delete right;
}

int ed::treeNode::getValue(){
	return value;
}

ed::Bst* ed::treeNode::getLeft(){
	return left;
}

ed::Bst* ed::treeNode::getRight(){
	return right;
}

void ed::treeNode::insert(int value){
	if(value < this->value){
		left->insert(value);
	}else{
		right->insert(value);
	}
}

bool ed::treeNode::remove(int value, Bst* parent){
	//TODO
}

bool ed::treeNode::search(int value){
	if(value == this->value){
		return true;
	}else{
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int ed::treeNode::height(){
	int lHeight = left->height();
	int rHeight = right->height();
	return (lHeight > rHeight) ?
		lHeight :
		rHeight;
}

int ed::treeNode::nodeCount(){
	return left->nodeCount() + right->nodeCount();
}

int ed::treeNode::balanceFactor(){
	int lHeight = left->height();
	int rHeight = right->height();
	return lHeight - rHeight;
}
