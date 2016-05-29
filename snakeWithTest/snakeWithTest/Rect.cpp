#include "Rect.h"

Rect::Rect() {
};
void Rect::setRectDimPos(int x, int y, int w, int h) {
	xCoord = x;
	yCoord = y;
	width = w;
	height = h;
};
void Rect::move() {
	if (nextMove== "up") {
		yCoord -= 5;
	}
	else if (nextMove == "down") {
		yCoord += 5;
	}
	else if (nextMove == "left") {
		xCoord -= 5;
	}
	else if (nextMove == "right") {
		xCoord += 5;
	};
}
bool Rect::findCollision(Rect it) {
	if (xCoord == it.xCoord && yCoord == it.yCoord) return true;
	return false;
}