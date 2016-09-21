#pragma once
#include "catch.hpp"
#include "avlTree.h"


SCENARIO("Testing tree") {
	GIVEN("New tree object") {
		std::unique_ptr<avlTree<int>> tree(new avlTree<int>());
		WHEN("Insert new object") {
			tree.get()->insert(5);
			tree.get()->insert(6);
			tree.get()->insert(7);
			tree.get()->insert(2);
			//tree.get()->balance();
			tree.get()->draw();
			THEN("Number of objects changed") {
				CHECK(tree->sizeOf() == 4);
			}
		}
	}
}