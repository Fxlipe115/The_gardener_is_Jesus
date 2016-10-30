#ifndef TREENODE_H
#define TREENODE_H

namespace ed{

		template <typename Tree>
		class treeNode{
			private:
				int value;
				Tree* left;
				Tree* right;
				
			public:
				treeNode(int value);
				int getValue();
				//TODO
		};
		
}

#endif