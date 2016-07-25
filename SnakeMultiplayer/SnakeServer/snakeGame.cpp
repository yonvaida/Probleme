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
void snakeGame::moveSnakes() {
	for (auto player : playersList) {
		player->movesnake();
	}
}
void snakeGame::createSnakeBoard(boost::property_tree::ptree &data) {
	table board(50, 50);
	board.getData(data);
}
void snakeGame::createSnakeFood(boost::property_tree::ptree &data) {
	food.randomize(50, 50);
	food.getData(data);
}
