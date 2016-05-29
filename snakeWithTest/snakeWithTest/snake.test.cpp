#include "snake.h"
#include "catch.hpp"
#include <vector>
#include <iostream>

SCENARIO("") {
	GIVEN("") {
		Snake snake;
		Rect snakeRect1;
		snakeRect1.setRectDimPos(0, 0, 5, 5);
		snakeRect1.nextMove = "left";
		Rect snakeRect2;
		snakeRect2.setRectDimPos(-5, 0, 5, 5);
		snakeRect2.nextMove = "left";
		Rect snakeRect3;
		snakeRect3.setRectDimPos(-10, 0, 5, 5);
		snakeRect3.nextMove = "left";
		snake.elongate(snakeRect1,"left");
		snake.elongate(snakeRect2,"left");
		snake.elongate(snakeRect3,"left");
		Rect snakeFood;
		snakeFood.setRectDimPos(-15, -5, 5, 5);
		//snake.move("right");
		
		WHEN("Create snake") {
			snake.move("up");
			snake.move("left");
			THEN("") {
			CHECK(snake.findFood(snakeFood));
			}
		}
		WHEN("Move left") {
			snake.move("left");
			snake.move("left");
			snake.move("left");
			snakeFood.setRectDimPos(-25, 0, 5, 5);
			THEN("Change snake position") {
			CHECK(snake.findFood(snakeFood));
			}
		}
		WHEN("Move right") {
			snake.move("right");
			
			THEN("Change snake position") {
				CHECK(snake.collision() == true);
			}
		}
		WHEN("Move up") {
			THEN("Change snake position") {
				//snake.move("up");
			}
		}
		WHEN("Move down") {
			THEN("Change snake position") {
				//snake.move("left");
			}
		}
		
	}
}
	