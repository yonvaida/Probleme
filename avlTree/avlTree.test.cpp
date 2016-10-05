#pragma once
#include "catch.hpp"
#include "avlTree.h"


SCENARIO("Testing tree") {
	GIVEN("New tree object") {
		std::unique_ptr<avlTree<int>> tree(new avlTree<int>());
		WHEN("Insert new object") {
			tree->insert(4);
			tree->insert(3);
			tree->insert(5);
			tree->insert(6);
			//tree->draw();
			//tree->insert(6);
			tree->insert(7);
			//tree->draw();
			//tree->insert(5);
			//tree.get()->balance();
			//tree->balance(tree->rootNode);
			//tree->draw();
			THEN("Number of objects changed") {
				CHECK(tree->sizeOf() == 3);
			}
		}
	}
}