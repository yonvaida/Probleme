#include "snake.h"
#include <iostream>
#include <vector>
#include <algorithm>

Snake::Snake() {
};

void Snake::move() {
	if (nextHeadPosition().x == food.x && nextHeadPosition().y==food.y) {
		elongate(food, snakeBodyMoves.back());
	}
	else {
		for (int index = 0; index < snakebody.size(); index++) {
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
			snakeBodyMoves[index] = (index<snakebody.size() - 1) ? snakeBodyMoves[index + 1] : snakeBodyMoves[index];
		}
	}
}
point Snake::nextHeadPosition() {
	point position;
	position = snakebody.back();
	switch (snakeBodyMoves.back()) {
	case Direction::left:
		position.x--;
		break;
	case Direction::right:
		position.x++;
		break;
	case Direction::up:
		position.y--;
		break;
	case Direction::down:
		position.y++;
		break;
	}
	return position;
};

void Snake::changeDirection(Direction direction) {
	snakeBodyMoves.back() = direction;
	move();
}

bool Snake::findFood(point foodPoint) {
	if (snakebody.back().x == food.x && snakebody.back().y == food.y) {
		std::cout << "snake food find" << std::endl;	
		return true;
	}
	else {
		return false;
	}
}

bool Snake::onTable(table board) {
	boost::property_tree::ptree data;
	board.getData(data);
	auto width = data.get<int>("table.width");
	auto height = data.get<int>("table.height");
	return (snakebody.back().x<0 || snakebody.back().y<0 || snakebody.back().x>width || snakebody.back().y>height) ? false : true;
} 

void Snake::elongate(point elongatePoint,Direction direction) {
	snakebody.push_back(elongatePoint);
	snakeBodyMoves.push_back(direction);
}

bool Snake::collision() {
	point temppoint = snakebody.back();
	for (int i = 0; i < snakebody.size() - 1; i++) {
		if (temppoint.x == snakebody.at(i).x && temppoint.y == snakebody.at(i).y) return true;
	}
	//std::vector<point>::iterator collisionResult = std::find_if(snakebody.begin(), snakebody.end() - 2, [&](point compare) {return ((compare.x == temppoint.x) && (compare.y == temppoint.y)); });
	return false;	
}

void Snake::getData(boost::property_tree::ptree &data) {
	
	for (int i = 0; i < snakebody.size(); i++) {
		data.put("snakebody.point"+ std::to_string(i)+".x", snakebody[i].x);
		data.put("snakebody.point" + std::to_string(i) + ".y", snakebody[i].y);
		data.put("snakebody.length", snakebody.size());
	}
}

void Snake::setFoodPoint(point foodpoint) {
	food = foodpoint;
}