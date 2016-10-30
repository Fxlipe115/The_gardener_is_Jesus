
graeff_zachow::treeNode::treeNode(int value): value(value), left(new Bst()), right(new Bst()) {}

graeff_zachow::treeNode::~treeNode(){
	delete left;
	delete right;
}

int graeff_zachow::treeNode::getValue(){
	return value;
}

graeff_zachow::Bst* graeff_zachow::treeNode::getLeft(){
	return left;
}

graeff_zachow::Bst* graeff_zachow::treeNode::getRight(){
	return right;
}

void graeff_zachow::treeNode::insert(int value){
	if(value < this->value){
		left->insert(value);
	}else{
		right->insert(value);
	}
}

bool graeff_zachow::treeNode::search(int value){
	if(value == this->value){
		return true;
	}else{
		return (value < this->value) ?
			left->search(value) :
			right->search(value);
	}
}

int graeff_zachow::treeNode::getLevelOf(int value){
	if(value == this->value){
		return 1;
	}else{
		return (value < this->value) ? 
			1 + left->getLevelOf(value) :
			1 + right->getLevelOf(value);
	}
}
