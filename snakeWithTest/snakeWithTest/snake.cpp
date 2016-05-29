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
		if (snakeFood.findCollision(snakebody.at(snakebody.size()-1))) return true;
		return false;
}
bool Snake::onTable(table snakeTable) {
	
	
	/*if (snakebody.begin.xCoord ) return true;*/
		return false;
} 

void Snake::elongate(Rect snakeRect,std::string dir) {
	snakebody.push_back(snakeRect);
	snakeRect.nextMove = dir;
	snakeRect.move();
	
	
	
}
bool Snake::collision() {
	std::vector<Rect>::iterator it;
	

	for (it = snakebody.begin(); it < snakebody.end() - 1; it++) {
		
		if (snakebody.at(snakebody.size()-1).findCollision(*it)) return true;
	
	}
	return false;
}