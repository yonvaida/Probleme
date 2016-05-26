#pragma once


class snakePoint {
public:
	snakePoint(int x, int y) {
		xCoord = x;
		yCoord=y;
	}
	void setPoint(int x, int y) {
		xCoord = x;
		yCoord = y;
	}
	int getXPoint() {
		return xCoord;
	}
	int getYPoint() {
		return yCoord;
	}
private:
	int xCoord;
	int yCoord;
};