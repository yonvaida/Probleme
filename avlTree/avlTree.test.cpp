#pragma once
#include "catch.hpp"
#include "avlTree.h"
#include <iostream>
#include <memory>

SCENARIO("AVL Tree") {
	GIVEN("Empty tree") {
		auto testTree = std::make_unique<avlTree>();
		node * node1 = new node();
		node * node2 = new node();
		node * node3 = new node();
		node * node4 = new node();
		node * node5 = new node();
		node * node6 = new node();
		node * node7 = new node();
		node1->setValue(5);
		node2->setValue(3);
		node3->setValue(2);
		node4->setValue(4);
		node5->setValue(7);
		node6->setValue(6);
		node7->setValue(8);
		
		WHEN("Insert nodes") {
			testTree->insertNode(*node1,* testTree->rootNode);
			testTree->insertNode(*node2, *testTree->rootNode);
			testTree->insertNode(*node3, *testTree->rootNode);
			testTree->insertNode(*node4, *testTree->rootNode);
			testTree->insertNode(*node5, *testTree->rootNode);
			testTree->insertNode(*node6, *testTree->rootNode);
			testTree->insertNode(*node7, *testTree->rootNode);
			THEN("Check node adresses") {
				CHECK( testTree->rootNode->leftChildNode == node2  );
				CHECK(testTree->rootNode->rightChildNode == node5);
				CHECK( node2->leftChildNode == node3);
				CHECK(node2->rightChildNode == node4);
				CHECK(node5->leftChildNode == node6);
				CHECK(node5->rightChildNode == node7);
			}
		}
		WHEN("Get height of nodes") {
			testTree->insertNode(*node1, *testTree->rootNode);
			testTree->insertNode(*node2, *testTree->rootNode);
			testTree->insertNode(*node3, *testTree->rootNode);
			testTree->insertNode(*node4, *testTree->rootNode);
			testTree->insertNode(*node5, *testTree->rootNode);
			testTree->insertNode(*node6, *testTree->rootNode);
			testTree->insertNode(*node7, *testTree->rootNode);
			THEN("Check node heights") {
				CHECK(testTree->rootNode->getLeftHeight() == 2);
				CHECK(testTree->rootNode->getRightHeight() == 2);
		}
		}
		WHEN("Insert node ") {
			testTree->insertNode(*node1, *testTree->rootNode);
			testTree->insertNode(*node2, *testTree->rootNode);
			testTree->insertNode(*node3, *testTree->rootNode);
			testTree->insertNode(*node4, *testTree->rootNode);
			testTree->insertNode(*node5, *testTree->rootNode);
			testTree->insertNode(*node6, *testTree->rootNode);
			testTree->insertNode(*node7, *testTree->rootNode);
			THEN("Check if tree is balanced") {
				CHECK(testTree->isBalanced() == true);
			}
		}
		WHEN("rotate left") {
			node1->setValue(10);
			node2->setValue(5);
			node3->setValue(12);
			node4->setValue(13);
			node5->setValue(14);
			testTree->insertNode(*node1, *node1);
			testTree->insertNode(*node2, *node1);
			testTree->insertNode(*node3, *node1);
			testTree->insertNode(*node4, *node1);
			testTree->insertNode(*node5, *node1);
			//testTree->drawNode(testTree->rootNode);
			testTree->rotateLeft(*node1);
			//testTree->drawNode(*testTree->rootNode);
			THEN("check left rotation") {
				CHECK(testTree->isBalanced() == true);
			}
		}
		WHEN("rotate right") {
			node1->setValue(5);
			node2->setValue(4);
			node3->setValue(3);
			testTree->insertNode(*node1, *node1);
			testTree->insertNode(*node2, *node1);
			testTree->insertNode(*node3, *node1);
			//testTree->drawNode(testTree->rootNode);
			testTree->rotateRight(*node1);
			testTree->drawNode(*testTree->rootNode);
			THEN("check right rotation") {
				CHECK(testTree->isBalanced() == true);
			}
		}
	}
}