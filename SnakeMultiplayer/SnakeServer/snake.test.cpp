#pragma once
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
		table board(3,3);
		tempPoint.x = 2;
		tempPoint.y = 0;
		tempPoint1.x = 1;
		tempPoint1.y = 0;
		tempPoint2.x = 0;
		tempPoint2.y = 0;	
		Snake snake;
		snake.elongate(tempPoint2, Direction::right);
		snake.elongate(tempPoint1, Direction::right);
		snake.elongate(tempPoint, Direction::right);
		boost::property_tree::ptree data;
		
		WHEN("Move down") {
			snake.changeDirection(Direction::down);
			snake.getData(data);
			THEN("Change snake position") {
				CHECK(data.get<int>("snakebody.point0.x") == 1);
				CHECK(data.get<int>("snakebody.point0.y") == 0);
				CHECK(data.get<int>("snakebody.point1.x") == 2);
				CHECK(data.get<int>("snakebody.point1.y") == 0);
				CHECK(data.get<int>("snakebody.point2.x") == 2);
				CHECK(data.get<int>("snakebody.point2.y") == 1);
			}
		}
		WHEN("Move down") {
			snake.changeDirection(Direction::down);
			snake.move();
			snake.move();
			snake.changeDirection(Direction::right);
			snake.changeDirection(Direction::up);
			snake.getData(data);
			THEN("Change snake position") {
				CHECK(data.get<int>("snakebody.point0.x") == 2);
				CHECK(data.get<int>("snakebody.point0.y") == 3);
				CHECK(data.get<int>("snakebody.point1.x") == 3);
				CHECK(data.get<int>("snakebody.point1.y") == 3);
				CHECK(data.get<int>("snakebody.point2.x") == 3);
				CHECK(data.get<int>("snakebody.point2.y") == 2);
			}
		}
		WHEN("Move left") {
			snake.changeDirection(Direction::right);
			snake.getData(data);
			THEN("Change snake position") {
				CHECK(data.get<int>("snakebody.point0.x") == 1);
				CHECK(data.get<int>("snakebody.point0.y") == 0);
				CHECK(data.get<int>("snakebody.point1.x") == 2);
				CHECK(data.get<int>("snakebody.point1.y") == 0);
				CHECK(data.get<int>("snakebody.point2.x") == 3);
				CHECK(data.get<int>("snakebody.point2.y") == 0);
			}
		}
		WHEN("Move right") {
			snake.changeDirection(Direction::left);
			snake.getData(data);
			THEN("Change snake position") {
				CHECK(data.get<int>("snakebody.point0.x") == 1);
				CHECK(data.get<int>("snakebody.point0.y") == 0);
				CHECK(data.get<int>("snakebody.point1.x") == 2);
				CHECK(data.get<int>("snakebody.point1.y") == 0);
				CHECK(data.get<int>("snakebody.point2.x") == 1);
				CHECK(data.get<int>("snakebody.point2.y") == 0);
			}
		}		
		WHEN("Snake move and intersect hi's body") {
			snake.changeDirection(Direction::left);
			THEN("Collision is true and game is over") {
				CHECK(snake.collision() == true);
			}
		}
		WHEN("Move snake move on table") {
			snake.move();
			THEN("On table function is true and snake game continue") {
				CHECK(snake.onTable(50,50) == true);

			}
		}
		WHEN("Move snake move out of table") {
			snake.move();
			snake.move();
			snake.move();
			snake.move();
			THEN("On table function is false and snake game is over") {
				CHECK(snake.onTable(2,2) == false);

			}
		}
		
	}
}
	