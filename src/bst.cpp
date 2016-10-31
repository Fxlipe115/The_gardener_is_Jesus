/************************
*
*	Arthur Zachow Coelho
*
*	Felipe de Almeida Graeff
*
************************/

#include "bst.h"
#include <string>
#include <fstream>
#include <stdexcept>

ed::Bst::Bst(): BinaryTree() {}

ed::Bst::Bst(std::string path): BinaryTree(path) {}

void ed::Bst::insert(int value){
	if(isEmpty()){
		node = new Node(value);
	}else{
		node->insert(value);
	}
}

bool ed::Bst::isEmpty(){
	return (node == nullptr) ?
		true :
		false;
}


int ed::Bst::getValue(){
	if(!isEmpty())
		return node->getValue();
	else{
		throw std::logic_error("Tree is empty");
	}
}

ed::Bst* ed::Bst::getLeft(){
	if(!isEmpty())
		return node->getLeft();
	else{
		throw std::logic_error("Tree is empty");
	}
}

ed::Bst* ed::Bst::getRight(){
	if(!isEmpty())
		return node->getRight();
	else{
		throw std::logic_error("Tree is empty");
	}
}

bool ed::Bst::search(int value){
	return isEmpty() ?
		false :
		node->search(value);
}
