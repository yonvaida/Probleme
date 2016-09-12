#pragma once
class node {
public:
	node();
	node *leftChildNode;
	node *rightChildNode;
	int height;
	int value;
};


class avlTree {
public:
	avlTree();
	void addNode(node &newNode);
	void drawnode(node &currentnode);
private:
	node rootNode;
	int numberofNodes;
	bool isBalanced();
};
