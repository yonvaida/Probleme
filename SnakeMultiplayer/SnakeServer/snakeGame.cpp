#pragma once
#include "snakeGame.h"

void snakeGame::joinGame(std::shared_ptr<snakePlayer> player) {
	playersList.insert(player);
}
void snakeGame::leaveGame(std::shared_ptr<snakePlayer> player) {
	playersList.erase(player);
}
int snakeGame::getNumberofPlayers() {
	int i=0;
	for (auto players : playersList) {
		i++;
	}
	return i;
}
