#include "catch.hpp"
#include "snakeFood.h"

SCENARIO("Test for snake food") {
	GIVEN("") {
		snakeFood randomFood;
		auto dataStoreVariable = randomFood.getData();
		randomFood.randomize(10,10);
		dataStoreVariable = randomFood.getData();
		WHEN("") {
			THEN("") {

			}
		}
	}
}