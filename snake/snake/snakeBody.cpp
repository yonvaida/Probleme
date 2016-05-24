#include <snakeHead.h>
#include "snakeBody.h"
#include <vector>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include <iostream>

snakeBodyRect::snakeBodyRect() {	
}
void snakeBodyRect::add(std::vector<QGraphicsRectItem> snake, snakeRect * snakeHead) {
	for (auto i = snake.begin(); i < snake.end(); i++) {
		std::cout << snake[0].pos().x() << std::endl;
	}
}
void move() {
	
}
