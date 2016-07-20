#pragma once
#include "snakeGame.h"

void snakeGame::joinGame(std::shared_ptr<snakePlayer> player) {
	playersList.insert(player);
}
void snakeGame::leaveGame(std::shared_ptr<snakePlayer> player) {
	playersList.erase(player);
}
int snakeGame::getNumberofPlayers() {
	return playersList.size();
}
void snakeGame::makeMove() {
	int i = 0;
	std::cout << playersList.size() << std::endl;
	for (auto player : playersList) {
		std::cout << "Game "<<i<<" making moves " << std::endl;
		i++;
		player->movesnake();
	};
}