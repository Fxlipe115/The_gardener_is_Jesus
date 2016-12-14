#include "avl.h"
#include <string>

ed::Avl::Avl(): Bst(), balanceFactor(0) {}

void ed::Avl::insert(int value, Bst* parent, int* rotations, int* comparisons){
	if(isEmpty()){
		node = new TreeNode(value);
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
		leftTree()->rotateL(leftTree());
		rotateR();
	}else if(balanceFactor < -1 && value < rightTree()->access()){
		rightTree()->rotateR();
		rotateL();
	}
}

bool ed::Avl::remove(int value, int* rotations, int* comparisons){
	if(isEmpty()){
		return false;
	}

	if(value < this->value){
		return leftTree()->remove(value, rotations, comparisons);
	}else if(value > this->value){
		return rightTree()->remove(value, rotations, comparisons);
	//value == this->value
	}else{
		remove(rotations, comparisons);
	}

	//Update balance factor
	balanceFactor = getBalanceFactor();
	
	//Rotate if unbalanced
	if(balanceFactor > 1 && leftTree()->balanceFactor >= 0){
		rotateR();		
	}else if(balanceFactor < -1 && rightTree()->balanceFactor <= 0){
		rotateL();
	}else if(balanceFactor > 1 && leftTree()->balanceFactor < 0){
		leftTree()->rotateL();
		rotateR();
	}else if(balanceFactor < -1 && rightTree()->balanceFactor > 0){
		rightTree()->rotateR();
		rotateL();
	}

	return true;
}
