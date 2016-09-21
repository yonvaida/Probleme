#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "avlTree.h"


/*
template<typename T>
void avlTree<T>::drawTree(node<T> &currentNode) {
		std::cout << "Node value is: " << currentNode.getValue() << " and adress is: " << std::endl;
}
template<typename T>
void avlTree<T>::drawTree() {
	std::cout << "Node value is: " << rootNode->getValue() << " and adress is: " << rootNode.get() << " Left child: " << rootNode.get()->leftChildNode << " Right child: " << rootNode.get()->rightChildNode << std::endl;
	if (rootNode.get()->leftChildNode != nullptr) {
		std::cout << "left node: " << rootNode.get()->leftChildNode << std::endl;
		drawTree(*rootNode.get()->leftChildNode);
}
	if (rootNode.get()->rightChildNode != nullptr) {
		drawTree(*rootNode.get()->rightChildNode);
	}
}






template<typename T>
node::node() {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
	parentNode = nullptr;
}

node::node() {
	
}
void node::setValue(int val) {
	
}
int node::getValue() {
	
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
		rootNode = &currentNode;
		numberofNodes++;
	}
	else {
		if (parentNode.getValue() > currentNode.getValue()) {
			if (parentNode.leftChildNode == nullptr) {
				parentNode.leftChildNode = &currentNode;
				currentNode.parentNode = &parentNode;
			}
			else {
				insertNode(currentNode, *parentNode.leftChildNode);
			}
		}
		else {
			if (parentNode.rightChildNode == nullptr) {
				parentNode.rightChildNode = &currentNode;
				currentNode.parentNode = &parentNode;
			}
			else {
				insertNode(currentNode, *parentNode.rightChildNode);
			}
		}
	}
}

void avlTree::balanceTree() {
	if (!isBalanced()) {};
}
bool avlTree::isBalanced() {
	int height=rootNode->getRightHeight()-rootNode->getLeftHeight();
	return (height > -2 && height < 2) ? true : false;
 }
void avlTree::rotateLeft(node &currentNode) { 
	node * tempNodeRef = currentNode.rightChildNode;
	if (currentNode.parentNode==nullptr) {
		rootNode = currentNode.rightChildNode;
		currentNode.parentNode = rootNode;
		currentNode.rightChildNode = rootNode->leftChildNode;
		rootNode->leftChildNode = &currentNode;
		
		
	}
	else {
		currentNode.rightChildNode->parentNode = currentNode.parentNode;
		currentNode.parentNode->rightChildNode = currentNode.rightChildNode;
		currentNode.parentNode = currentNode.rightChildNode;
		currentNode.rightChildNode = currentNode.parentNode->leftChildNode;
		currentNode.parentNode->leftChildNode = &currentNode;
	}
	
	

};

void avlTree::rotateRight(node &currentNode) {
	node * tempNodeRef = currentNode.rightChildNode;
	if (currentNode.parentNode == nullptr) {
		rootNode = currentNode.leftChildNode;
		currentNode.parentNode = rootNode;
		currentNode.leftChildNode = rootNode->rightChildNode;
		rootNode->rightChildNode = &currentNode;


	}
	else {
		currentNode.leftChildNode->parentNode = currentNode.parentNode;
		currentNode.parentNode->leftChildNode = currentNode.leftChildNode;
		currentNode.parentNode = currentNode.leftChildNode;
		currentNode.leftChildNode = currentNode.parentNode->rightChildNode;
		currentNode.parentNode->rightChildNode = &currentNode;
	}



};


void avlTree::drawNode(node &currentNode) {
	std::cout << "Current Node: " << currentNode.getValue()<<" Node adress:"<< &currentNode << " Left: " << currentNode.leftChildNode << " Right " << currentNode.rightChildNode <<" Parrent node: "<<currentNode.parentNode<< std::endl;
	if (currentNode.leftChildNode != nullptr)drawNode(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr)drawNode(*currentNode.rightChildNode);
}
*/

int main(int argc, char *argv[])
{

	int result = Catch::Session().run(argc, argv);
	//std::unique_ptr<avlTree<int>> tree(new avlTree<int>);
	//tree.get()->insert(5);
	//tree.get()->insert(3);
	//tree.get()->insert(1);
	//tree.get()->insert(6);
	//tree.get()->draw();


	return result;

}