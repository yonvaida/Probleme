// avlTree.cpp : Defines the entry point for the console application.
//
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "avlTree.h"
#include <memory>
#include <algorithm>

node::node() {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
	heightLeft = 0;
	heightRight = 0;
}
void node::setValue(int val) {
	value = val;
}
int node::getValue() {
	return value;
}
int node::getLeftHeight() {
	if (leftChildNode == nullptr) {
		return 0;
	}
	else {
		return std::max(leftChildNode->getLeftHeight(),leftChildNode->getRightHeight()) + 1;
	}
}
int node::getRightHeight() {
	if (rightChildNode == nullptr) {
		return 0;
	}
	else {
		return std::max(rightChildNode->getRightHeight(),rightChildNode->getLeftHeight()) + 1;
	}
}
void node::setLeftHeight(int leftval) {
	heightLeft = leftval;
}
void node::setRightHeight(int rightval) {
	heightRight = rightval;
}

avlTree::avlTree() {
	numberofNodes = 0;
}
void avlTree::insertNode(node &currentNode,node &parentNode){
	if (numberofNodes == 0) {
		rootNode = currentNode;
		numberofNodes++;
	}
	else {
		if (parentNode.getValue() > currentNode.getValue()) {
			if (parentNode.leftChildNode == nullptr) {
				parentNode.leftChildNode = &currentNode;
			}
			else {
				insertNode(currentNode, *parentNode.leftChildNode);
			}
		}
		else {
			if (parentNode.rightChildNode == nullptr) {
				parentNode.rightChildNode = &currentNode;
			}
			else {
				insertNode(currentNode, *parentNode.rightChildNode);
			}
		}
	}
}

void avlTree::drawNode(node &currentNode) {
	std::cout << "Current Node: " << currentNode.getValue()<<" Node adress:"<< &currentNode << " Left: " << currentNode.leftChildNode << " Right " << currentNode.rightChildNode <<" Left Height: "<<currentNode.getLeftHeight()<< std::endl;
	if (currentNode.leftChildNode != nullptr)drawNode(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr)drawNode(*currentNode.rightChildNode);
}

int main(int argc, char* const argv[])
{
	int result = Catch::Session().run(argc, argv);
	std::unique_ptr<avlTree> tree(new avlTree);
	bool addNextNode = true;
	while (addNextNode)
	{
		char addnew='n';
		node * newnode = new node();
		int temp;
		std::cout << "New node" << std::endl;
		std::cin >> temp;
		newnode->setValue(temp);
		tree->insertNode(*newnode,tree->rootNode);
		tree->drawNode(tree->rootNode);
		std::cout << "Add new node (y/n)" << std::endl;
		std::cin >> addnew;
		addNextNode = (addnew == 'y') ? true : false;
	}


	return result;
}

