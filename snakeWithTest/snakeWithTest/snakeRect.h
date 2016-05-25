#pragma once
#include <string.h>

class SnakeRect
{
public:
	SnakeRect(int x, int y, int w, int h) {
		xCoord = x;
		yCoord = y;
		width = w;
		height = h;
	}

	void setCoord(int x, int y) {
		xCoord = x;
		yCoord = y;
	}
	int getXCoord() { return xCoord; }
	int getYCoord() { return yCoord; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	void createTable() {
		xCoord = -width/2;
		yCoord = -height/2;
	}
	void move(std::string direction) {
		if (direction == "left") {
			xCoord -= 10;
		}
		else if (direction == "right") {
			xCoord += 10;
		}
		else if (direction == "up") {
			yCoord -= 10;
		}else if(direction =="down"){
			yCoord += 10;
		};
	}

private:
	int xCoord;
	int yCoord;
	int width;
	int height;
};

