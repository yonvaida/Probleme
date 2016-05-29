#pragma once
#include <string.h>
#include <deque>
#include "table.h"
#include <qapplication.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>

class SnakeRect
{
	
public:
	
	SnakeRect(int x, int y, int w, int h);
	void move(enum direction);
	bool findFood(int x, int y);
	bool onTable(table snakeArea);
	direction nextMove;
private:
	int xCoord;
	int yCoord;
	int width;
	int height;
};
std::deque<SnakeRect> elongate(std::deque<SnakeRect> snake, SnakeRect snakeHead);
