#pragma once
#include <string.h>
#include <deque>
#include "table.h"
#include "Rect.h"
#include <qapplication.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
enum class Direction { left, right, up, down };
struct point {
	int x;
	int y;
};
class Snake
{
public:
	Snake();
	void elongate(point food);
	void move(Direction direction);
	bool findFood();
	bool onTable();
	bool collision();
private:
	std::vector<point> snakebody;
};