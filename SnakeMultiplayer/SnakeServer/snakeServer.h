#pragma once
#include "snakeGame.h"
#include <string>

class snakeServer {
public:
	snakeServer();
	void addNewGame(int direction, std::string ip);
	void moveSnakeInGame(int direction,std::string ip);
	snakeGame getGame(std::string ip);
private:
	int snakeMove;
	std::vector<snakeGame> listOfGames;
	//std::vector<int> listOfPlayers;
	int gameNumber;
};