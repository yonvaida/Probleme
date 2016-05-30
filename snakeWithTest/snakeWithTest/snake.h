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
	void move(Direction direction);
	bool findFood(int x, int y);
	bool onTable(int w,int h);
	bool collision();

private:
	
	std::vector<point> snakebody;
	std::vector<Direction> snakeBodyMoves;
};