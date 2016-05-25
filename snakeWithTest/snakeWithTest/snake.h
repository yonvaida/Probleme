#pragma once
#include <string.h>

class SnakeRect
{
	
public:
	enum direction { left, right, up, down };
	SnakeRect(int x, int y, int w, int h);
	void move(enum direction);
	bool findFood(int x, int y);
private:
	int xCoord;
	int yCoord;
	int width;
	int height;
};

