#include "snakeServer.h"

snakeServer::snakeServer() {
	std::cout << "Snake Server created..." << std::endl;
}
void snakeServer::addNewGame() {
	//auto newSnakeGame = std::make_shared<snakeGame>;
	//listOfGames.push_back(newSnakeGame);
}
void snakeServer::moveSnakeInGame(int direction,int id) {
	if (id == 0) {
		addNewGame();
		//listOfPlayers
	}
}


