#include "snake.h"
#include <iostream>
#include <vector>

Snake::Snake() {

};

void Snake::move(std::string dir) {
	int i;
	std::vector<Rect>::iterator it;

	for (it=snakebody.begin(); it < snakebody.end()-1; it++) {
		it->nextMove = (it + 1)->nextMove;
		it->move();
	}
	it->nextMove =dir;
	it->move();
}

bool Snake::findFood(Rect snakeFood) {
		if (snakebody.end()->findFood(snakeFood)) return true;
		return false;
}
bool Snake::onTable(table snakeTable) {
	/*if (snakebody.begin.xCoord ) return true;*/
		return false;
} 

void Snake::elongate(Rect snakeRect,std::string dir) {
	snakeRect.nextMove = dir;
	snakeRect.move();
	snakebody.push_back(snakeRect);
	
	
}
bool Snake::collision() {
	std::vector<Rect>::iterator it;
	std::vector<Rect>::iterator snakehead=snakebody.end();
	for (it = snakebody.begin(); it < snakebody.end() - 1; it++) {
		if (it == snakehead)return false;
			
	}
	return true;
}