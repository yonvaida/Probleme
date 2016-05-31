
#include "snake.h"
#include "catch.hpp"
#include <vector>
#include <iostream>
#include <string>

SCENARIO("") {
	GIVEN("") {
		point tempPoint;
		point tempPoint1;
		point tempPoint2;
		tempPoint.x = -2;
		tempPoint.y = 0;
		tempPoint1.x = -1;
		tempPoint1.y = 0;
		tempPoint2.x = 0;
		tempPoint2.y = 0;	
		Snake snake;
		snake.elongate(tempPoint2, Direction::left);
		snake.elongate(tempPoint1, Direction::left);
		snake.elongate(tempPoint, Direction::left);
		boost::property_tree::ptree data;
		
		WHEN("Move left and check position of elements of snake") {
			snake.move();
			snake.getData(data);
			//snake.move(Direction::left);
			THEN("Change snake position and find if snakehead is on foodpoint") {
				CHECK(data.get<int>("snakebody.point0.x") == -1);
				CHECK(data.get<int>("snakebody.point0.y") == 0);
				CHECK(data.get<int>("snakebody.point1.x") == -2);
				CHECK(data.get<int>("snakebody.point1.y") == 0);
				CHECK(data.get<int>("snakebody.point2.x") == -3);
				CHECK(data.get<int>("snakebody.point2.y") == 0);
			}
		}
		WHEN("Move up and left") {
			snake.changeDirection(Direction::up);
			snake.move();
			snake.getData(data);
			THEN("Change snake position up and move another step up and chef position of snake") {
				CHECK(data.get<int>("snakebody.point0.x") == -2);
				CHECK(data.get<int>("snakebody.point0.y") == 0);
				CHECK(data.get<int>("snakebody.point1.x") == -2);
				CHECK(data.get<int>("snakebody.point1.y") == -1);
				CHECK(data.get<int>("snakebody.point2.x") == -2);
				CHECK(data.get<int>("snakebody.point2.y") == -2);
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
	