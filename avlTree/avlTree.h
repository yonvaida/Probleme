#pragma once

#include <memory>
#include <algorithm>
#include <iostream>




template<typename T>
class node {
public:
	node();
	node(T val);
	std::shared_ptr<node<T>> parentNode, leftChildNode, rightChildNode;
	int getNumberofChildren();
	int getHeight();
	T getValue();
private:
	int getLeftHeight();
	int getRightHeight();
	T value;
};

template<typename T>
class avlTree {
public:
	avlTree();
	bool isEmpty();
	int sizeOf();
	void insert(T value);
	void draw();
	void draw(node<T> &currentNode);
	void balance(std::shared_ptr<node<T>>& currentNode);
	void rotateLeft(std::shared_ptr < node<T>>& node);
	void rotateRight(std::shared_ptr < node<T>>& node);
	std::shared_ptr<node<int>> rootNode;	
private:
	void insertNode(std::shared_ptr<node<T>>& currentNode, std::shared_ptr<node<T>>&  parentNode);
	
};

/***************************Node Declaration*************************************************/
template<typename T>
node<T>::node() {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
	parentNode = nullptr;

};
template<typename T>
node<T>::node(T val) {
	leftChildNode = nullptr;
	rightChildNode = nullptr;
	parentNode = nullptr;
	value = val;
};

template<typename T>
T node<T>::getValue() {
	return value;
}
template<typename T>
int node<T>::getNumberofChildren() {
	int number = 0;
	if (leftChildNode) {
		number += leftChildNode->getNumberofChildren()+1;
	}
	if (rightChildNode) {
		number +=rightChildNode->getNumberofChildren()+1;
	}
	return number;
}

template<typename T>
int node<T>::getLeftHeight() {
	return (leftChildNode)?std::max(leftChildNode->getLeftHeight(), leftChildNode->getRightHeight()) + 1:0;
}

template<typename T>
int node<T>::getRightHeight() {
	return (rightChildNode)?std::max(rightChildNode->getRightHeight(), rightChildNode->getLeftHeight()) + 1:0;
}
template<typename T>
int node<T>::getHeight() {
	return getLeftHeight() - getRightHeight();
}

/***************************TREE declaration*************************************************/

template<typename T>
avlTree<T>::avlTree() {
};

template<typename T>
bool avlTree<T>::isEmpty() {
	return (rootNode.get() == nullptr) ? true : false;
}

template<typename T>
void avlTree<T>::insertNode(std::shared_ptr<node<T>>& currentNode, std::shared_ptr<node<T>>& parentNode) {
	if (parentNode->getValue() > currentNode->getValue()) {
		if (parentNode->leftChildNode == nullptr) {
			currentNode->parentNode = parentNode;
			parentNode->leftChildNode=currentNode;
			balance(currentNode);

		}
		else {
			insertNode(currentNode, parentNode->leftChildNode);
		}
	}
	else {
		if (parentNode->rightChildNode == nullptr) {
			currentNode->parentNode = parentNode;
			parentNode->rightChildNode=currentNode;
			balance(currentNode);
		}
		else {
			insertNode(currentNode, parentNode->rightChildNode);
		}
	}
}

template<typename T>
void avlTree<T>::rotateLeft(std::shared_ptr < node<T>>& rotatenode) {
	if (rotatenode == rootNode) {
		auto temp_ptr = rotatenode->rightChildNode->leftChildNode;
		if(temp_ptr)temp_ptr->parentNode = rotatenode;
		rotatenode->rightChildNode->parentNode = nullptr;
		rotatenode->rightChildNode->leftChildNode = rotatenode;
		rotatenode->parentNode = rotatenode->rightChildNode;
		rotatenode->rightChildNode = temp_ptr;
		rootNode = rotatenode->parentNode;
	}
	else {
		auto temp_ptr = rotatenode;
		rotatenode.swap(rotatenode->rightChildNode);
		temp_ptr->rightChildNode = rotatenode->leftChildNode;
		rotatenode->leftChildNode = temp_ptr;
		rotatenode->parentNode = temp_ptr->parentNode;
		rotatenode->leftChildNode->parentNode = rotatenode;
	}
}

template<typename T>
void avlTree<T>::rotateRight(std::shared_ptr < node<T>>& rotatenode) {
	if (rotatenode == rootNode) {
		auto temp_ptr = rotatenode->leftChildNode->rightChildNode;
		if(temp_ptr)temp_ptr->parentNode = rotatenode;
		rotatenode->leftChildNode->parentNode = nullptr;
		rotatenode->leftChildNode->rightChildNode = rotatenode;
		rotatenode->parentNode = rotatenode->leftChildNode;
		rotatenode->leftChildNode = temp_ptr;
		rootNode = rotatenode->parentNode;
	}
	else {
		auto temp_ptr = rotatenode;
		rotatenode.swap(rotatenode->leftChildNode);
		temp_ptr->leftChildNode = rotatenode->rightChildNode;
		rotatenode->rightChildNode = temp_ptr;
		rotatenode->parentNode = temp_ptr->parentNode;
		rotatenode->rightChildNode->parentNode = rotatenode;
	}
}

template<typename T>
void avlTree<T>::insert(T val) {
	std::shared_ptr<node<T>> newNode(new node<T>(val));
	if (rootNode) {
		insertNode(newNode, rootNode);
		}
	else {
		rootNode.swap(newNode);
	}
}

template<typename T>
void avlTree<T>::draw() {
	draw(*rootNode);
}

template<typename T>
void avlTree<T>::draw(node<T> &currentNode) {
	std::cout<< "Node value: " << currentNode.getValue() << " adress: " << &currentNode << " left child: " << currentNode.leftChildNode << " Right child: " << currentNode.rightChildNode << " Parent node: " << currentNode.parentNode << std::endl;
	//std::cout << " Left height: " << currentNode.getLeftHeight() << " Right height: " << currentNode.getRightHeight()<<std::endl;
	if (currentNode.leftChildNode != nullptr) draw(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr) draw(*currentNode.rightChildNode);
}

template<typename T>
int avlTree<T>::sizeOf() {
	return rootNode.get()->getNumberofChildren()+1;
}
template<typename T>
void avlTree<T>::balance(std::shared_ptr<node<T>>& currentNode) {
	auto temp_ptr = currentNode;
	while (temp_ptr != nullptr) {
		if (temp_ptr->getHeight() < -1 ) {
			std::cout << "Balancing node: " << temp_ptr->getValue() << std::endl;
			rotateLeft(temp_ptr);
			temp_ptr = temp_ptr->parentNode;
		}
		else {
			if (temp_ptr->getHeight() >1 ) {
			std::cout << "Balancing tree\n" << temp_ptr->getValue();
			rotateRight(temp_ptr);
			temp_ptr = temp_ptr->parentNode;
		}
		else {
			temp_ptr = temp_ptr->parentNode;
		}
		}
		

	}
	//rotateLeft(rootNode->rightChildNode);
	
}