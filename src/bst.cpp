#include "bst.h"
#include <string>
#include <fstream>
#include <stdexcept>

ed::Bst::Bst(): parent(nullptr), node(nullptr) {}

ed::Bst::Bst(std::string path): parent(nullptr), node(nullptr) {
	std::ifstream file(path);
	
    if(file.is_open()){
        std::string file_content;
        //Itera por todas as linhas
        while(std::getline(file, file_content)) 
            // Insere o valor na árvore
            insert(std::stoi(file_content));
        file.close();
	}
}

ed::Bst::~Bst(){
	if(!isEmpty()){
		delete node;
	}
}

void ed::Bst::setValue(int value){
	node->setValue(value);
}

void ed::Bst::setLeftTree(Bst* tree, Bst* parent){
	this->node->setLeft(tree);
	if(!tree->isEmpty()){
		tree->setParent(parent);
	}
}

void ed::Bst::setRightTree(Bst* tree, Bst* parent){
	this->node->setRight(tree);
	if(!tree->isEmpty()){
		tree->setParent(parent);
	}
}

void ed::Bst::setParent(Bst* parent){
	this->parent = parent;
}

ed::Bst* ed::Bst::getParent(){
	return parent;
}

int ed::Bst::access(){
	if(!isEmpty())
		return node->getValue();
	else{
		throw std::logic_error("Tree is empty");
	}
}

ed::Bst* ed::Bst::leftTree(){
	if(!isEmpty())
		return node->getLeft();
	else{
		throw std::logic_error("Tree is empty");
	}
}

ed::Bst* ed::Bst::rightTree(){
	if(!isEmpty())
		return node->getRight();
	else{
		throw std::logic_error("Tree is empty");
	}
}

void ed::Bst::insert(int value, Bst* parent, int* rotations, int* comparisons){
	if(isEmpty()){
		node = new TreeNode(value);
		this->parent = parent;
	}else{
		node->insert(value, this, rotations, comparisons);
	}
}

bool ed::Bst::remove(int value, int* rotations, int* comparisons){
	Bst* tree = search(value, comparisons);

	//if value was not found return false else remove node
	return (tree == nullptr) ? false : tree->remove(rotations, comparisons);
}

bool ed::Bst::remove(int* rotations, int* comparisons){
	bool lEmpty = leftTree()->isEmpty();
	bool rEmpty = rightTree()->isEmpty();

	//children are both empty
	if(lEmpty && rEmpty){
		if(parent != nullptr){
			(parent->leftTree() == this) ?
				parent->setLeftTree(new Bst()) :
				parent->setRightTree(new Bst());
		}
		delete this->node;

	//left child empty
	}else if(lEmpty && !rEmpty){
		if(parent != nullptr){
			(parent->leftTree() == this) ?
				parent->setLeftTree(rightTree(), parent) :
				parent->setRightTree(rightTree(), parent);
		}
		setRightTree(new Bst());
		delete this->node;

	
	//right child empty
	}else if(!lEmpty && rEmpty){
		if(parent != nullptr){
			(parent->leftTree() == this) ?
				parent->setLeftTree(leftTree(), parent) :
				parent->setRightTree(leftTree(), parent);
		}
		setLeftTree(new Bst());
		delete this;

	
	//neither child empty
	}else if(!lEmpty && !rEmpty){
		Bst* bigger = leftTree()->bigger();
		setValue(bigger->access());

		return leftTree()->remove(bigger->access(), rotations, comparisons);
	}
	return true;
}

ed::Bst* ed::Bst::search(int value, int* comparisons){
	return isEmpty() ?
		nullptr :
		node->search(value,this, comparisons);
}


bool ed::Bst::isEmpty(){
	return (node == nullptr) ?
		true :
		false;
}

ed::Bst* ed::Bst::bigger(){
	if(isEmpty()){
		throw std::logic_error("Tree is empty");
	}else if(rightTree()->isEmpty()){
		return this;
	}else{
		return rightTree()->bigger();
	}
}

ed::Bst* ed::Bst::smaller(){
	if(isEmpty()){
		throw std::logic_error("Tree is empty");
	}else if(leftTree()->isEmpty()){
		return this;
	}else{
		return leftTree()->smaller();
	}
}

int ed::Bst::height(){
	return isEmpty() ?
		0 :
		1 + node->height();
}

int ed::Bst::nodeCount(){
	return isEmpty() ?
		0 :
		1 + node->nodeCount();
}

int ed::Bst::getBalanceFactor(){
	return isEmpty() ?
		0 :
		node->balanceFactor();
}
