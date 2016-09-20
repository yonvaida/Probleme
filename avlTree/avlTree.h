#pragma once
template<typename T>
class node {
	//using value_type=T;
public:
	node();
	std::unique_ptr<node<T>> leftChildNode, rightChildNode;
	node<T>* parentNode;
	void setValue(T val);
	T getValue();
	int getLeftHeight();
	int getRightHeight();
private:
	T value;
};

template<typename T>
class avlTree {
public:
	avlTree();
	bool isEmpty();
	void insert(T value);
	int numberOfNodes;
private:
	void insertNode(std::unique_ptr<node<T>> &currentNode, std::unique_ptr<node<T>> & parentNode);
	std::unique_ptr<node<int>> rootNode;	
};
