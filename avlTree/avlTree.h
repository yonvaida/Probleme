#pragma once
#include <memory>
#include <algorithm>
#include <iostream>
template<typename T>
class node {
	//using value_type=T;
public:
	node();
	node(T val);
	std::shared_ptr<node<int>> leftChildNode,rightChildNode;
	node<T> * parentNode;
	int getNumberofChildren();
	int getLeftHeight();
	int getRightHeight();
	T getValue();
	void rotateLeft();
	void rotateRight();
private:
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
	void balance();
private:
	void insertNode(std::shared_ptr<node<T>> currentNode, node<T>& parentNode);
	std::shared_ptr<node<int>> rootNode;	
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
		number += leftChildNode.get()->getNumberofChildren()+1;
	}
	if (rightChildNode) {
		number +=rightChildNode.get()->getNumberofChildren()+1;
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
void node<T>::rotateLeft(){
	std::shared_ptr<node<T>> temp_ptr;
	if (rightChildNode)parentNode->rightChildNode.swap(leftChildNode);
	//leftChildNode.swap(parentNode);
	parentNode = parentNode->parentNode;
	
}

template<typename T>
void node<T>::rotateRight(){

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
void avlTree<T>::insertNode(std::shared_ptr<node<T>> currentNode, node<T>& parentNode) {
	if (parentNode.getValue() > currentNode.get()->getValue()) {
		if (parentNode.leftChildNode == nullptr) {
			currentNode.get()->parentNode = &parentNode;
			parentNode.leftChildNode.swap(currentNode);

		}
		else {
			insertNode(currentNode, *parentNode.leftChildNode);
		}
	}
	else {
		if (parentNode.rightChildNode == nullptr) {
			currentNode.get()->parentNode = &parentNode;
			parentNode.rightChildNode.swap(currentNode);
		}
		else {
			insertNode(currentNode, *parentNode.rightChildNode);
		}
	}
}

template<typename T>
void avlTree<T>::insert(T val) {
	std::shared_ptr<node<T>> newNode(new node<T>(val));
	if (rootNode) {
		insertNode(std::move(newNode), *rootNode);
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
	std::cout << " Left height: " << currentNode.getLeftHeight() << " Right height: " << currentNode.getRightHeight()<<std::endl;
	if (currentNode.leftChildNode != nullptr) draw(*currentNode.leftChildNode);
	if (currentNode.rightChildNode != nullptr) draw(*currentNode.rightChildNode);
}

template<typename T>
int avlTree<T>::sizeOf() {
	return rootNode.get()->getNumberofChildren()+1;
}
template<typename T>
void avlTree<T>::balance() {
	rootNode->rightChildNode->rotateLeft();
}