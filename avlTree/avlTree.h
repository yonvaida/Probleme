#pragma once
template<typename T>
class node {
	//using value_type=T;
public:
	node();
	node(T val);
	std::shared_ptr<node<int>> leftChildNode,rightChildNode;
	node<T> * parentNode;
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
	void draw();
	void draw(node<T> &currentNode);
private:
	void insertNode(std::shared_ptr<node<T>> currentNode, node<T>& parentNode);
	std::shared_ptr<node<int>> rootNode;	
};
