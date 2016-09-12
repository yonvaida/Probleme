// avlTree.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "avlTree.h"
#include <memory>

node::node() {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
}

avlTree::avlTree(){
	rootNode.height = 0;
}

void avlTree::addNode(node &newnode) {
	node &comparenode = rootNode;
	if (rootNode.height == 0) 
	{
		rootNode = newnode;
		rootNode.height++;
	}
	else {
		if (comparenode.value < newnode.value) {
			comparenode.rightChildNode = &newnode;
			std::cout <<"New node added right :" <<newnode.value <<" New node adress: "<< &newnode<< std::endl;
		}
		else {
			comparenode.leftChildNode = &newnode;
			std::cout << "New node added left:" << newnode.value << " New node adress: " << &newnode << std::endl;
		}
		numberofNodes++;
	};
	std::cout << "Number of nodes: " << numberofNodes << std::endl;
	drawnode(rootNode);
}
void avlTree::drawnode(node &currentNode) {
	std::cout << "Value: " << currentNode.value << " Left node: " << currentNode.leftChildNode << " Right Node: " << currentNode.rightChildNode << std::endl;
	if (currentNode.leftChildNode != nullptr) drawnode(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr) drawnode(*currentNode.rightChildNode);

}

int main()
{
	std::unique_ptr<avlTree> tree(new avlTree);
	bool addNextNode = true;
	while (addNextNode)
	{
		char addnew='n';
		std::unique_ptr<node> newnode(new node);
		std::cout << "New node" << std::endl;
		std::cin >> newnode->value;
		tree->addNode(*newnode);
		std::cout << "Add new node (y/n)" << std::endl;
		std::cin >> addnew;
		addNextNode = (addnew == 'y') ? true : false;
	}


	return 0;
}

