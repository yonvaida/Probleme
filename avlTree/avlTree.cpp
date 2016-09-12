// avlTree.cpp : Defines the entry point for the console application.
//
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "avlTree.h"
#include <memory>

node::node() {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
}
void node::setleftChildNode(node &newnode) {
	leftChildNode = &newnode;
}
void node::setrightChildNode(node &newnode) {
	rightChildNode = &newnode;
}
void node::setheight(int h) {
	height = h;
}
int node::getValue() {
	return value;
}



avlTree::avlTree(){
	rootNode.setheight(0);
}
node avlTree::findParent(node &newNode,node currentNode) {
	if(currentNode.getValue()<newNode.getValue()){}

}


void avlTree::addNode(node &newnode,node &parentnode) {
	
}
void avlTree::drawnode(node &currentNode) {
	std::cout << "Value: " << currentNode.value << " Left node: " << currentNode.leftChildNode << " Right Node: " << currentNode.rightChildNode << std::endl;
	if (currentNode.leftChildNode != nullptr) drawnode(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr) drawnode(*currentNode.rightChildNode);

}

int main(int argc, char* const argv[])
{
	int result = Catch::Session().run(argc, argv);
	std::unique_ptr<avlTree> tree(new avlTree);
	bool addNextNode = true;
	while (addNextNode)
	{
		char addnew='n';
		//auto newnode=std::make_unique<node>();
		node * newnode = new node();
		std::cout << "New node" << std::endl;
		std::cin >> newnode->value;
		tree->addNode(*newnode);
		std::cout << "Add new node (y/n)" << std::endl;
		std::cin >> addnew;
		addNextNode = (addnew == 'y') ? true : false;
	}


	return result;
}

