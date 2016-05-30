#include "snake.h"
#include "catch.hpp"
#include <vector>
#include <iostream>

SCENARIO("") {
	GIVEN("") {
		point tempPoint;
		point tempPoint1;
		point tempPoint2;
		point foodpoint;
		tempPoint.x = -2;
		tempPoint.y = 0;
		tempPoint1.x = -1;
		tempPoint1.y = 0;
		tempPoint2.x = 0;
		tempPoint2.y = 0;	
		foodpoint.x = -7;
		foodpoint.y = -1;
		Snake snake;
		snake.elongate(tempPoint2, Direction::left);
		snake.elongate(tempPoint1, Direction::left);
		snake.elongate(tempPoint, Direction::left);
		snake.move(Direction::up);
		snake.move(Direction::left);
		snake.move(Direction::left);
		snake.move(Direction::left);
		
		WHEN("Create snake") {
			THEN("") {
			//CHECK();
			}
		}
		WHEN("Move left") {
			snake.move(Direction::left);
			snake.move(Direction::left);
			THEN("Change snake position and find if snakehead is on foodpoint") {
				CHECK(snake.findFood(foodpoint));
			}
		}
		WHEN("Move right") {
			snake.move(Direction::right);
			THEN("Change snake position to right and check collision") {
			CHECK(snake.collision() == true);
			}
		}
		WHEN("Snake ") {
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
	