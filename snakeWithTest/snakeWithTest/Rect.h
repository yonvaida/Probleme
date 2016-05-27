#pragma once
#include <string>
class Rect
{
public:
	Rect();
	Rect(int xCoord, int yCoord, int width, int height);
	void setRectDimPos(int x, int y, int w, int h);
	void move();
	std::string nextMove;
	bool findFood(Rect snakefood);
private:
	int xCoord;
	int yCoord;
	int width;
	int height;
};
