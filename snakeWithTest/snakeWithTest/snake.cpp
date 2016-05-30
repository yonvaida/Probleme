#include "snake.h"
#include <iostream>
#include <vector>
#include <algorithm>

Snake::Snake() {
	
};

void Snake::move(Direction direction) {
	for (int index = 0; index < snakebody.size(); index++) {
		snakeBodyMoves[index] = (index<snakebody.size() - 1) ? snakeBodyMoves[index + 1] : direction;
		switch (snakeBodyMoves[index])
		{
		case Direction::left:
			snakebody[index].x--;
			break;
		case Direction::right:
			snakebody[index].x++;
			break;
		case Direction::up:
			snakebody[index].y--;
			break;
		case Direction::down:
			snakebody[index].y++; 
			break;
		default:
			break;
		};
	}
	
}

bool Snake::findFood(point foodPoint) {
	if (snakebody.back().x == foodPoint.x && snakebody.back().y == foodPoint.y) return true;
		return false;
}
bool Snake::onTable(int w,int h) {
	
		
		return false;
} 

void Snake::elongate(point elongatePoint,Direction direction) {
	snakebody.push_back(elongatePoint);
	snakeBodyMoves.push_back(direction);
}


bool Snake::collision() {
	point temppoint = snakebody.back();
	std::vector<point>::iterator collisionResult = std::find_if(snakebody.begin(), snakebody.end() - 1, [&](point compare) {return ((compare.x == temppoint.x) && (compare.y == temppoint.y)); });
	return ((*collisionResult).x == snakebody.back().x&& (*collisionResult).y == snakebody.back().y) ? true : false;
	return true;
}
