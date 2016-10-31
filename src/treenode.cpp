
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

bool ed::treeNode::search(int value){
	if(value == this->value){
		return true;
	}else{
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int ed::treeNode::getLevelOf(int value){
	if(value == this->value){
		return 1;
	}else{
		return (value < this->value) ? 
			1 + left->getLevelOf(value) :
			1 + right->getLevelOf(value);
	}
}
