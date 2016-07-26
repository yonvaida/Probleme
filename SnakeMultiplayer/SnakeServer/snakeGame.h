#pragma once
#include "snake.h"
#include "table.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <iostream>
#include "snakePlayer.h"
#include "serialization.h"

class snakeGame {
public:
	void joinGame(std::shared_ptr<snakePlayer> player);
	void leaveGame(std::shared_ptr<snakePlayer> player);
	void createSnakeBoard(boost::property_tree::ptree &data);
	snakeFood food;	
	void createSnakeFood(boost::property_tree::ptree &data);
	void getAllSnakes(boost::property_tree::ptree &allSnakes);
	std::vector<boost::property_tree::ptree> allSnakes; 
	void moveSnakes();
private:
	
	std::set<std::shared_ptr<snakePlayer>> playersList;
	
};

