#include "snake.h"
#include <iostream>
#include <vector>
#include <algorithm>

Snake::Snake() {
	
};

void Snake::move() {
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

void Snake::changeDirection(Direction direction) {
	snakeBodyMoves.back() = direction;
	move();
}


bool Snake::findFood(point foodPoint) {
	point nextPosition;
	nextPosition = snakebody.back();
	switch (snakeBodyMoves.back())
	{
	case Direction::left:
		nextPosition.x--;
		break;
	case Direction::right:
		nextPosition.x++;
		break;
	case Direction::up:
		nextPosition.y--;
		break;
	case Direction::down:
		nextPosition.y++;
		break;
	default:
		break;
	};
	if (nextPosition.x == foodPoint.x && nextPosition.y == foodPoint.y) {
		elongate(nextPosition, snakeBodyMoves.back());
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
	std::vector<point>::iterator collisionResult = std::find_if(snakebody.begin(), snakebody.end() - 1, [&](point compare) {return ((compare.x == temppoint.x) && (compare.y == temppoint.y)); });
	return ((*collisionResult).x == snakebody.back().x&& (*collisionResult).y == snakebody.back().y) ? true : false;
	return true;
}

void Snake::getData(boost::property_tree::ptree &data) {
	
	for (int i = 0; i < snakebody.size(); i++) {
		data.put("snakebody.point"+ std::to_string(i)+".x", snakebody[i].x);
		data.put("snakebody.point" + std::to_string(i) + ".y", snakebody[i].y);
	}
}