#include "bst.h"
#include <string>
#include <fstream>
#include <stdexcept>

ed::Bst::Bst(): node(nullptr) {}

ed::Bst::Bst(std::string path): node(nullptr) {
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

void ed::Bst::insert(int value){
	if(isEmpty()){
		node = new TreeNode(value);
	}else{
		node->insert(value);
	}
}

bool ed::Bst::remove(int value, Bst* parent){
	//TODO
	return true;
}

bool ed::Bst::search(int value){
	return isEmpty() ?
		false :
		node->search(value);
}
	

bool ed::Bst::isEmpty(){
	return (node == nullptr) ?
		true :
		false;
}

int ed::Bst::bigger(){
	if(isEmpty()){
		throw std::logic_error("Tree is empty");
	}else if(rightTree()->isEmpty()){
		return access();
	}else{
		return rightTree()->bigger();
	}
}

int ed::Bst::smaller(){
	if(isEmpty()){
		throw std::logic_error("Tree is empty");
	}else if(leftTree()->isEmpty()){
		return access();
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

int ed::Bst::balanceFactor(){
	return isEmpty() ?
		0 :
		node->balanceFactor();
}
