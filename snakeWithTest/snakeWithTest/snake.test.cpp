#include "snake.h"
#include "catch.hpp"
#include <vector>
#include <iostream>

SCENARIO("") {
	GIVEN("") {
		Snake snake;
		Rect snakeRect1;
		snakeRect1.setRectDimPos(0, 0, 5, 5);
		Rect snakeRect2;
		snakeRect2.setRectDimPos(-5, 0, 5, 5);
		Rect snakeRect3;
		snakeRect3.setRectDimPos(-10, 0, 5, 5);
		snake.elongate(snakeRect1,"left");
		snake.elongate(snakeRect2,"left");
		snake.elongate(snakeRect3,"left");
		Rect snakeFood;
		snakeFood.setRectDimPos(-10, 0, 5, 5);
		snake.move("right");
		
		WHEN("Create snake") {

			THEN("") {
			//CHECK(snake.findFood(snakeFood));
			}
		}
		WHEN("Move left") {
			//snake.move("left");
			THEN("Change snake position") {

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
	