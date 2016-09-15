#pragma once
class node {
public:
	node();
	void setValue(int val);
	node *leftChildNode,*rightChildNode,*parentNode;
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
	void rotateRight(node &currentNode);
	void rotateLeft(node &currentNode);
	void balanceTree();
	void drawNode(node &currentNode);
	node  * rootNode;
	bool isBalanced();
private:
	
	int numberofNodes;
	
};
