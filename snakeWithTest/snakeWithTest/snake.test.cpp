
#include "snake.h"
#include "catch.hpp"
#include <deque>
#include <iostream>

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
			snakeHead.move(SnakeRect::up);
			THEN("") {
				CHECK(snakeHead.findFood(0, -10) == true);
			}
		}
		WHEN("Move down") {
			snakeHead.move(SnakeRect::down);
			THEN("") {
				CHECK(snakeHead.findFood(0, 0) == true);
			}
		}
		WHEN("Coord of snake is same as food coord's") {
			THEN("Eat food") {
				CHECK(snakeHead.findFood(0,0) == true);
			}
		}
		WHEN("Find food") {
			if (snakeHead.findFood(0, 0)) {
				snake = elongate(snake, snakeHead);
			}
			THEN("Eat food and elongate") {
			CHECK(snake.size() == 1);
			}
		}
		WHEN("Snake is on table") {
			table snakeTable(200, 200);
			THEN("continue game"){
				CHECK(snakeHead.onTable(snakeTable) == true);
			}
		}
		WHEN("Snake go out form table") {
			table snakeTable(20, 20);
			for (int i = 0; i < 10; i++) {
				snakeHead.move(SnakeRect::left);
			}
			THEN("Game is over") {
				CHECK(snakeHead.onTable(snakeTable) == false);
			}
		}
	}
}