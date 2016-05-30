#include "snake.h"
#include <iostream>
#include <vector>
#include <algorithm>

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
