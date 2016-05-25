#include "snake.h"
#include <iostream>

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
	std::cout << xCoord << "--" << yCoord << std::endl;
	if (xCoord == x && yCoord == y) {
		return true;
	}
		return false;
}
