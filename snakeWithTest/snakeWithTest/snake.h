#pragma once
#include <string.h>

class Snake
{
	enum direction { left, right, up, down };
public:
	Snake(int x, int y, int w, int h);
	void move(enum direction);

private:
	int xCoord;
	int yCoord;
	int width;
	int height;
};

