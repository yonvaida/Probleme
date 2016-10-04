#pragma once
#include "catch.hpp"
#include "avlTree.h"


SCENARIO("Testing tree") {
	GIVEN("New tree object") {
		std::unique_ptr<avlTree<int>> tree(new avlTree<int>());
		WHEN("Insert new object") {
			tree->insert(3);
			tree->insert(2);
			tree->insert(1);
			//tree->insert(8);
			//tree->draw();
			//tree->insert(9);
			//tree.get()->insert(10);
			//tree.get()->balance();
			//tree->balance(tree->rootNode);
			tree->draw();
			THEN("Number of objects changed") {
				CHECK(tree->sizeOf() == 3);
			}
		}
	}
}