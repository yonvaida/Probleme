#pragma once
#include <QGraphicsRectItem>
#include "SnakeHead.h"
#include <memory.h>
#include <vector>


class snakeBodyRect :public QGraphicsRectItem {
public:
	snakeBodyRect();
	void add(std::vector<QGraphicsRectItem>snake, snakeRect * snakeHead);
	void move();
};