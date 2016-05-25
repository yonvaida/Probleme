#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "snakeRect.h"
#include <deque>
bool validSnakePosition(SnakeRect table, SnakeRect snakehead) {
	if (snakehead.getXCoord() > table.getXCoord()
		&& snakehead.getXCoord() < table.getXCoord()+table.getWidth()
		&& snakehead.getYCoord() > table.getYCoord()
		&& snakehead.getXCoord() < table.getXCoord()+table.getHeight()) {
		return true;
	}
	else return false;
}
std::deque<SnakeRect> elongateSnake(SnakeRect head, std::deque<SnakeRect> snakeBody) {
	snakeBody.push_front(head);
	return snakeBody;
}


SCENARIO("") {
	GIVEN("") {
		SnakeRect table(0,0,500,500);
		SnakeRect snakeHead(0, 0, 10, 10);
		std::deque<SnakeRect> snakebody;
		SnakeRect snakeFood(40, 20, 10, 10);
		WHEN("") {
			table.createTable();
			THEN("") {
				CHECK(table.getXCoord()==-250);
				CHECK(table.getYCoord()==-250);
			}
		}
		WHEN("Move Up") {
			snakeHead.move("up");
			THEN("Y position decreased") {
				CHECK(snakeHead.getYCoord() == -10);
			}
		}
		WHEN("Move Down") {
			snakeHead.move("down");
			THEN("Y position increased"){
				CHECK(snakeHead.getYCoord() == 10);
			}
		}
		WHEN("Move Left") {
			snakeHead.move("left");
			THEN("X position decreased") {
				CHECK(snakeHead.getXCoord() == -10);
			}
		}
		WHEN("Move Right") {
			snakeHead.move("right");
			THEN("x position increased") {
				CHECK(snakeHead.getXCoord() == 10);
			}
		}
		WHEN("Exit from table") {
			snakeHead.setCoord(-300, 300);
			THEN("Return GAME OVER") {
				CHECK(validSnakePosition(table,snakeHead) == false);
			}
		}
		WHEN("Snake eat food") {
			snakebody=elongateSnake(snakeHead, snakebody);
			THEN("Snake elongate") {
				CHECK(snakebody.size() == 1);
			}
		}
	}
}