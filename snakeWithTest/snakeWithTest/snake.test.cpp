#include "snake.h"
#include "catch.hpp"
#include <deque>
#include <iostream>
std::deque<SnakeRect> elongate(std::deque<SnakeRect> snake, SnakeRect snakeHead) {
	 snake.push_front(snakeHead);
	 return snake;
}


SCENARIO("") {
	GIVEN("") {
		SnakeRect snakeHead(0, 0, 10, 10);
		std::deque<SnakeRect>snake;
		WHEN("Move left") {
			snakeHead.move(SnakeRect::left);
			THEN("") {
				CHECK(snakeHead.findFood(-10, 0));
			}
		}
		WHEN("Move right") {
			snakeHead.move(SnakeRect::right);
			
			THEN("") {
				CHECK(snakeHead.findFood(0, 0));
			}
		}
		WHEN("Move up") {
			//snakeHead.move(SnakeRect::up);
			THEN("") {
				//CHECK(snakeHead.findFood(0, -10) == true);
			}
		}
		WHEN("Move down") {
			//snakeHead.move(SnakeRect::down);
			THEN("") {
				//CHECK(snakeHead.findFood(0, 0) == true);
			}
		}
		WHEN("Coord of snake is same as food coord's") {
			THEN("Eat food") {
				//CHECK(snakeHead.findFood(0,0) == true);
			}
		}
		WHEN("Find food") {
			if (snakeHead.findFood(0, 0)) {
				snake = elongate(snake, snakeHead);
			}
			THEN("Eat food and elongate") {
			//	CHECK(snake.size() == 1);
			}
		}
	}
}