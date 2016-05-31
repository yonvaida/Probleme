#pragma once
#include <string.h>
#include <deque>
#include "table.h"
#include "main.h"
#include <vector>


class Snake
{
public:
	Snake();
	void elongate(point elongatePoint,Direction direction);
	void move();
	void changeDirection(Direction direction);
	bool findFood(point foodPoint);
	bool onTable(table board);
	bool collision();
	void getData(boost::property_tree::ptree &data);
private:
	std::vector<point> collisionList;
	std::vector<point> snakebody;
	std::vector<Direction> snakeBodyMoves;
};