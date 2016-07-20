#pragma once
#include "snake.h"
#include "table.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <iostream>
#include "snakePlayer.h"

class snakeGame {
public:
	void joinGame(std::shared_ptr<snakePlayer> player);
	void leaveGame(std::shared_ptr<snakePlayer> player);
	void makeMove();
	int getNumberofPlayers();
private:
	std::set<std::shared_ptr<snakePlayer>> playersList;
};

