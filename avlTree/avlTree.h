#pragma once
class node {
public:
	node();
	void setleftChildNode(node &newnode);
	void setrightChildNode(node &newnode);
	void setValue(int value);
	void setheight(int h);
	int getValue();
private:
	node *leftChildNode;
	node *rightChildNode;
	int height;
	int value;

};


class avlTree {
public:
	avlTree();
	node findParent(node &newNode,node currentNode);
	void addNode(node &newNode);
	void drawnode(node &currentnode);
private:
	node rootNode;
	int numberofNodes;
	bool isBalanced();
};
