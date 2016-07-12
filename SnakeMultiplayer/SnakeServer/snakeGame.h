#pragma once
#include "snake.h"
#include "table.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <iostream>


class snakeGame {
public:
	snakeGame(boost::property_tree::ptree &data, int direction);
	void makeSnakeMove();
private:
	boost::property_tree::ptree data;
};