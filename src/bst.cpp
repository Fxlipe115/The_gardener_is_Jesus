/************************
*
*	Arthur Zachow Coelho
*
*	Felipe de Almeida Graeff
*
************************/

#include "./../lib/bst.h"
#include <stdexcept>

graeff_zachow::Node::Node(int value): value(value), left(new Bst()), right(new Bst()) {}

graeff_zachow::Node::~Node(){
	delete left;
	delete right;
}

int graeff_zachow::Node::getValue(){
	return value;
}

graeff_zachow::Bst* graeff_zachow::Node::getLeft(){
	return left;
}

graeff_zachow::Bst* graeff_zachow::Node::getRight(){
	return right;
}

void graeff_zachow::Node::insert(int value){
	if(value < this->value){
		left->insert(value);
	}else{
		right->insert(value);
	}
}

bool graeff_zachow::Node::search(int value){
	if(value == this->value){
		return true;
	}else{
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int graeff_zachow::Node::getLevelOf(int value){
	if(value == this->value){
		return 1;
	}else{
		return (value < this->value) ? 
			1 + left->getLevelOf(value) :
			1 + right->getLevelOf(value);
	}
}

graeff_zachow::Bst::Bst(): node(nullptr) {}

graeff_zachow::Bst::~Bst(){
	if(!isEmpty()){
		delete node;
	}
}

void graeff_zachow::Bst::insert(int value){
	if(isEmpty()){
		node = new Node(value);
	}else{
		node->insert(value);
	}
}

bool graeff_zachow::Bst::isEmpty(){
	return (node == nullptr) ?
		true :
		false;
}


int graeff_zachow::Bst::getValue(){
	if(!isEmpty())
		return node->getValue();
	else{
		throw std::logic_error("Tree is empty");
	}
}

graeff_zachow::Bst* graeff_zachow::Bst::getLeft(){
	if(!isEmpty())
		return node->getLeft();
	else{
		throw std::logic_error("Tree is empty");
	}
}

graeff_zachow::Bst* graeff_zachow::Bst::getRight(){
	if(!isEmpty())
		return node->getRight();
	else{
		throw std::logic_error("Tree is empty");
	}
}

bool graeff_zachow::Bst::search(int value){
	return isEmpty() ?
		false :
		node->search(value);
}

int graeff_zachow::Bst::getLevelOf(int value){
	if(!isEmpty()){
		return node->getLevelOf(value);
	}else{
		throw std::invalid_argument("\"value\" not found.");
	}
}

bool graeff_zachow::Bst::pathExists(int start, int end){
	if(isEmpty()){
		throw std::invalid_argument("\"start\" not found.");
	}
	if(start == getValue()){
		return this->search(end);
	}else{
		return (start < getValue()) ?
			node->getLeft()->pathExists(start, end) :
			node->getRight()->pathExists(start, end);
	}
}

bool graeff_zachow::compare(Bst* tree1, Bst* tree2){
	if(tree1->isEmpty() == tree2->isEmpty()){
		if(tree1->isEmpty()){
			return true;
		}else if(tree1->getValue() == tree2->getValue()){
			return true 
				&& compare(tree1->getLeft(), tree2->getLeft()) 
				&& compare(tree1->getRight(), tree2->getRight());
		}
	}else{
		return false;
	}
}
