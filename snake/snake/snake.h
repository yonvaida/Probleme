#pragma once
#include <QGraphicsRectItem>
#include "SnakeHead.h"
#include <memory.h>


class snakeBody :public QGraphicsRectItem {
public:
	snakeBody();
	int elongate();
	void move();

};