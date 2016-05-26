#include "snake.h"
#include <iostream>
#include <deque>

SnakeRect::SnakeRect(int x, int y, int w, int h) {

};

void SnakeRect::move(direction dir) {
	if (dir==direction::up) {
		yCoord -= 10;
	}
	else if (dir==direction::down) {
		yCoord += 10;
	}
	else if (dir==direction::left) {
		xCoord -= 10;
	}
	else if (dir==direction::right) {
		xCoord += 10;
	};
}

bool SnakeRect::findFood(int x,int y) {
		if (xCoord == x && yCoord == y) {
		return true;
	}
		return false;
}
std::deque<SnakeRect> elongate(std::deque<SnakeRect> snake, SnakeRect snakeHead) {
	snake.push_front(snakeHead);
	return snake;
}