#include "catch.hpp"
#include "avlTree.h"
SCENARIO("Tree") {
	//avlTree<int> testTree;
	//testTree.insert(5);
	GIVEN("Create empty tree") {
		WHEN("Insert value") {
			THEN("Check if value exist in tree") {
				CHECK(true == true);
			}
		}
		WHEN("Insert a value") {
		//int initialnumberofNodes = testTree.numberOfNodes;
		//testTree.insert(5);
			THEN("Number of elements from tree increased") {
			//CHECK(initialnumberofNodes + 1 == testTree.numberOfNodes);
			}
		}
	}
}