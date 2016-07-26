#pragma once
#include "snakeGame.h"
void snakeGame::joinGame(std::shared_ptr<snakePlayer> player) {
	playersList.insert(player);
}
void snakeGame::leaveGame(std::shared_ptr<snakePlayer> player) {
	int i = 0;
	for(auto snakeplayer:playersList){
		if (player == snakeplayer) {
			allSnakes.erase(allSnakes.begin()+i);
			std::cout << "Exit player " << i << std::endl;
		}
		else { i++; }
	}
	playersList.erase(player);

}
void snakeGame::newGame(std::shared_ptr<snakePlayer> player) {
	int i = 0;
	for (auto snakeplayer : playersList) {
		if (player == snakeplayer) {
			allSnakes.erase(allSnakes.begin() + i);
			
		}
		else { i++; }
	}
}
void snakeGame::moveSnakes() {
	boost::property_tree::ptree data;
	int i = 0;
	for (auto player : playersList) {
		data.clear();
		player->movesnake();
		if (allSnakes.size() < i + 1) {
			createSnakeBoard(data);
			createSnakeFood(data);
			player->getsnake(data);
			allSnakes.push_back(data);
		}else{
			player->getsnake(allSnakes.at(i));
		}
		i++;
	}
	i = 0;
	for (auto player : playersList) {
			player->sendSnakeData(allSnakes,i);
			i++;	
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
