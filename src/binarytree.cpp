#include <iostream.h>
#include "binarytree.h"

//Construtores
ed::BinaryTree::BinaryTree(): node(nullptr) {}

ed::BinaryTree::BinaryTree(std::string path): node(nullptr) {
	std::ifstream arq(path);
	
    if(arq.is_open()){
        std::string file_content;
        //Itera por todas as linhas
        while(std::getline(arq, file_content)) 
            // Insere o valor na árvore
            insert(std::stoi(file_content));
        arq.close();
	}
}

ed::BinaryTree::~BinaryTree(){
	if(!isEmpty()){
		delete node;
	}
}


//Métodos
int ed::BinaryTree::getValue(){
	
}

BinaryTree* ed::BinaryTree::getLeft(){
	
}

BinaryTree* ed::BinaryTree::getRight(){
	
}

bool ed::BinaryTree::remove(int value){
	
}

bool ed::BinaryTree::search(int value){
	
}

bool ed::BinaryTree::isEmpty(){
	
}

int ed::BinaryTree::height(){
	
}

int ed::BinaryTree::nodeCount(){
	
}

int ed::BinaryTree::balanceFactor(){
	
}
