#pragma once
#include "snake.h"
#include "table.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <iostream>


class snakeGame {
public:
	snakeGame(int direction, std::string ip);
	void makeSnakeMove(int direction);
	boost::property_tree::ptree getData();
	std::string gameID;
private:
	boost::property_tree::ptree data;
};