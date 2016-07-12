#pragma once
#include "snakeGame.h"

class snakeServer {
public:
	snakeServer();
	void addNewGame();
	void moveSnakeInGame(int direction,int id);
private:
	int snakeMove;
	std::vector<snakeGame> listOfGames;
	std::vector<int> listOfPlayers;
};