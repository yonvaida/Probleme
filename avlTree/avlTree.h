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
	void draw(std::shared_ptr<node<T>> &currentNode);
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
		}
		else {
			insertNode(currentNode, parentNode->leftChildNode);
		}
	}
	else {
		if (parentNode->rightChildNode == nullptr) {
			currentNode->parentNode = parentNode;
			parentNode->rightChildNode=currentNode;
			
		}
		else {
			insertNode(currentNode, parentNode->rightChildNode);
		}
	}
}

template<typename T>
void avlTree<T>::rotateLeft(std::shared_ptr < node<T>>& rotatenode) {
		auto temp_ptr = rotatenode;
        rotatenode.swap(rotatenode->rightChildNode);
		
		if (temp_ptr == rootNode) { 
			temp_ptr->parentNode = rotatenode;
			rootNode = rotatenode;
		}
		else {
			rotatenode->parentNode = temp_ptr->parentNode;
			temp_ptr->parentNode->rightChildNode = rotatenode;
		}
		(rotatenode->leftChildNode).swap(temp_ptr);
		if(rotatenode->leftChildNode)rotatenode->leftChildNode->rightChildNode = temp_ptr;
		if (rotatenode->leftChildNode->rightChildNode)rotatenode->leftChildNode->rightChildNode->parentNode = rotatenode->leftChildNode;
		rotatenode->leftChildNode->parentNode = rotatenode;	
		rootNode->parentNode = nullptr;
}

template<typename T>
void avlTree<T>::rotateRight(std::shared_ptr < node<T>>& rotatenode) {
	
		auto temp_ptr = rotatenode;
		rotatenode.swap(rotatenode->leftChildNode);
		if (temp_ptr == rootNode) {
			temp_ptr->parentNode = rotatenode;
			rootNode = rotatenode;
		}
		else {
			rotatenode->parentNode = temp_ptr->parentNode;
			temp_ptr->parentNode->rightChildNode = rotatenode;
		}
		(rotatenode->rightChildNode).swap(temp_ptr);
		if(rotatenode->rightChildNode)rotatenode->rightChildNode->leftChildNode = temp_ptr;
		if (rotatenode->rightChildNode->leftChildNode)rotatenode->rightChildNode->leftChildNode->parentNode = rotatenode->rightChildNode;
		rotatenode->rightChildNode->parentNode = rotatenode;
		rootNode->parentNode = nullptr;
}

template<typename T>
void avlTree<T>::insert(T val) {
	std::shared_ptr<node<T>> newNode(new node<T>(val));
	if (rootNode) {
		insertNode(newNode, rootNode);
		balance(newNode);
		}
	else {
		rootNode.swap(newNode);
	}
}

template<typename T>
void avlTree<T>::draw() {
	draw(rootNode);
}

template<typename T>
void avlTree<T>::draw(std::shared_ptr<node<T>> &currentNode) {

	auto left = (currentNode->leftChildNode == nullptr) ? 0 : currentNode->leftChildNode->getValue();
	auto right = (currentNode->rightChildNode == nullptr) ? 0 : currentNode->rightChildNode->getValue();
	auto parent = (currentNode->parentNode == nullptr) ? 0 : currentNode->parentNode->getValue();
	std::cout<< "Node value: " << currentNode->getValue() << " adress: " << currentNode << " left child: " << left<< " Right child: " << right << " Parent node: " << parent << std::endl;
	if (currentNode->leftChildNode != nullptr) draw(currentNode->leftChildNode);
	if (currentNode->rightChildNode != nullptr) draw(currentNode->rightChildNode);
}

template<typename T>
int avlTree<T>::sizeOf() {
	return rootNode.get()->getNumberofChildren()+1;
}
template<typename T>
void avlTree<T>::balance(std::shared_ptr<node<T>>& currentNode) {
	auto temp_ptr = currentNode;
	if (temp_ptr != nullptr) {
		switch (temp_ptr->getHeight())
		{
		case -2:
			std::cout << "Balancing node: " << temp_ptr->getValue() << std::endl;
			if(temp_ptr->rightChildNode->getHeight() > 0){
				rotateRight(temp_ptr->rightChildNode);
				rotateLeft(temp_ptr);
			}
			else {
				rotateLeft(temp_ptr);
			}
			break;
		case 2:
			std::cout << "Balancing node\n" << temp_ptr->getValue();
			if (temp_ptr->leftChildNode->getHeight() < 0) {
				rotateLeft(temp_ptr->leftChildNode);
				rotateRight(temp_ptr);
			}
			else {
				rotateRight(temp_ptr);
			}
			break;
		default:
			balance(temp_ptr->parentNode);
		}
	}
	

}