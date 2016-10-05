#pragma once
#include "catch.hpp"
#include "avlTree.h"


SCENARIO("Testing tree") {
	GIVEN("New tree object") {
		std::unique_ptr<avlTree<int>> tree(new avlTree<int>());
		WHEN("Insert new object") {
			tree->insert(10);
			tree->insert(5);
			tree->insert(20);
			tree->insert(15);
			tree->insert(14);
			tree->insert(16);
			tree->draw();
			THEN("Number of objects changed") {
				CHECK(tree->sizeOf() == 6);
			}
		}
	}
}