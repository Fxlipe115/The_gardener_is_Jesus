#include <iostream>
#include "bst.h"

int main(int argc, char** argv){
	if(argc == 2){
		ed::Bst arvore(argv[1]);
				std::cout << arvore.nodeCount() << std::endl;
				}
	return 0;
}
