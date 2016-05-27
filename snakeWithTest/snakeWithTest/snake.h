#pragma once
#include <string.h>
#include <deque>
#include "table.h"
#include "Rect.h"
#include <qapplication.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
enum class Direction { left, right, up, down };

class Snake: public Rect
{
public:
	Snake();
	void elongate(Rect snakeRect,std::string dir);
	void move(std::string dir);
	bool findFood(Rect snakeRect);
	bool onTable(table snakeArea);
	bool collision();
private:
	std::vector<Rect> snakebody;
};