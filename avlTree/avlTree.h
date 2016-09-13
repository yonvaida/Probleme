#pragma once
class node {
public:
	node();
	void setValue(int val);
	
	node *leftChildNode;
	node *rightChildNode;
	int getValue();
	int getLeftHeight();
	int getRightHeight();
	void setLeftHeight(int leftval);
	void setRightHeight(int rightval);
private:
	int heightLeft;
	int heightRight;
	int value;

};


class avlTree {
public:
	avlTree();
	void setHeight(node &rootnode);
	void deleteNode(node &currentNode);
	void insertNode(node &currentNode, node &parentNode);
	void drawNode(node &currentNode);
	node rootNode;
private:
	
	int numberofNodes;
	bool isBalanced();
};
