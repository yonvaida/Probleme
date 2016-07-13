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
	Snake(boost::property_tree::ptree &data);
	void elongate(point elongatePoint,Direction direction);
	void move();
	void changeDirection(Direction direction);
	bool findFood(point foodPoint);
	bool onTable(int width, int height);
	bool collision();
	void getData(boost::property_tree::ptree &data);
	void setFoodPoint(point foodpoint);
private:
	std::vector<point> collisionList;
	std::vector<point> snakebody;
	std::vector<Direction> snakeBodyMoves;
	point food;
	point nextHeadPosition();
};