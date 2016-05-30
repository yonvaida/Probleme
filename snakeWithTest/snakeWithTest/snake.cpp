#include "snake.h"
#include <iostream>
#include <vector>

Snake::Snake() {
	
};

void Snake::move(Direction direction) {
	for (int index = 0; index < snakebody.size() - 1; index++) {
		if (snakeBodyMoves[index + 1] == Direction::left) {
			snakebody[index].x--;
			snakeBodyMoves[index] = snakeBodyMoves[index + 1];
		}
		else if (snakeBodyMoves[index + 1] == Direction::right) {
			snakebody[index].x++;
			snakeBodyMoves[index] = snakeBodyMoves[index + 1];

		}else if(snakeBodyMoves[index + 1] == Direction::up){
			snakebody[index].y--;
			snakeBodyMoves[index] = snakeBodyMoves[index + 1];
		
		}
		else if (snakeBodyMoves[index + 1] == Direction::down) {
			snakebody[index].y++;
			snakeBodyMoves[index] = snakeBodyMoves[index + 1];
		}
	}
	if (direction == Direction::left) {
		snakebody.back().x--;
		snakeBodyMoves.back() = Direction::left;
	}else if(direction==Direction::right){
		snakebody.back().x++;
		snakeBodyMoves.back() = Direction::right;
	}
	else if (direction == Direction::up) {
		snakebody.back().y--;
		snakeBodyMoves.back() = Direction::up;
	}
	else if (direction == Direction::down) {
		snakebody.back().y++;
		snakeBodyMoves.back() = Direction::down;
	}
}

bool Snake::findFood(int x, int y) {
	if (snakebody.back().x == x && snakebody.back().y == y) return true;
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

	return false;
}
