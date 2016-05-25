#include "snake.h"

Snake::Snake(int x, int y, int w, int h) {

};

void Snake::move(enum direction) {
	if (direction::up) {
		yCoord -= 10;
	}
	else if (direction::down) {
		yCoord += 10;
	}
	else if (direction::left) {
		xCoord -= 10;
	}
	else if (direction::right) {
		yCoord += 10;
	};
}