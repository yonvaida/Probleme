#include "snakeServer.h"

snakeServer::snakeServer() {
	std::cout << "Snake Server created..." << std::endl;
}
void snakeServer::addNewGame(int direction,std::string ip) {
	snakeGame newSnakeGame(direction,ip);
	listOfGames.push_back(newSnakeGame);
}
void snakeServer::moveSnakeInGame(int direction,std::string ip) {
	
	gameNumber = -1;
	for (int i = 0; i < listOfGames.size(); i++) {
		if (listOfGames.at(i).gameID == ip) {
			gameNumber = i;
		};
	};
		if (gameNumber == -1) {
			addNewGame(direction,ip);
		}
		else {
			listOfGames.at(gameNumber).makeSnakeMove(direction);
			
		};

}
snakeGame snakeServer::getGame(std::string ip) {
	for (int i = 0; i < listOfGames.size(); i++) {
		if (listOfGames.at(i).gameID == ip) {
			gameNumber = i;
		};
	}
	return listOfGames.at(gameNumber);
}

