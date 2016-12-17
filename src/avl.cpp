#include "avl.h"
#include <string>

ed::Avl::Avl(): Bst(), balanceFactor(0) {}

void ed::Avl::insert(int value, Bst* parent, int* rotations, int* comparisons){
	if(isEmpty()){
		node = new TreeNode<Avl>(value);
		this->parent = parent;
	}else{
		node->insert(value, this, rotations, comparisons);
	}

	//Update balance factor
	balanceFactor = getBalanceFactor();
	
	//Rotate if unbalanced
	if(balanceFactor > 1 && value < leftTree()->access()){
		rotateR();		
	}else if(balanceFactor < -1 && value > rightTree()->access()){
		rotateL();
	}else if(balanceFactor > 1 && value > leftTree()->access()){
		node->getLeft()->rotateL();
		rotateR();
	}else if(balanceFactor < -1 && value < rightTree()->access()){
		node->getRight()->rotateR();
		rotateL();
	}
}

bool ed::Avl::remove(int value, int* rotations, int* comparisons){
	if(isEmpty()){
		return false;
	}

	if(value < access()){
		return leftTree()->remove(value, rotations, comparisons);
	}else if(value > access()){
		return rightTree()->remove(value, rotations, comparisons);
	//value == this->value
	}else{
		Bst::remove(rotations, comparisons);
	}

	//Update balance factor
	balanceFactor = getBalanceFactor();
	
	//Rotate if unbalanced
	if(balanceFactor > 1 && node->getLeft()->balanceFactor >= 0){
		rotateR();		
	}else if(balanceFactor < -1 && node->getRight()->balanceFactor <= 0){
		rotateL();
	}else if(balanceFactor > 1 && node->getLeft()->balanceFactor < 0){
		node->getLeft()->rotateL();
		rotateR();
	}else if(balanceFactor < -1 && node->getRight()->balanceFactor > 0){
		node->getRight()->rotateR();
		rotateL();
	}

	return true;
}

ed::Avl* ed::Avl::search(int value, int* comparisons){
	return isEmpty() ?
		nullptr :
		node->search(value,this, comparisons);
}

void ed::Avl::rotateR(){

}

void ed::Avl::rotateL(){

}
