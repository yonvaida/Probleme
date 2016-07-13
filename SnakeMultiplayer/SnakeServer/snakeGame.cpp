#include "snakeGame.h"

snakeGame::snakeGame(int direction,std::string ip) {
	gameID = ip;
	
		auto newTable = std::make_unique<table>(50, 50);
		auto newFood = std::make_unique<snakeFood>();
		newFood->randomize(50, 50);
		auto newSnake = std::make_unique<Snake>();
		auto newSnakeHead = std::make_unique<point>();
		newSnakeHead->x = 0;
		newSnakeHead->y = 0;
		newSnake->elongate(*newSnakeHead, Direction::right);
		newSnake->getData(data);
		newFood->getData(data);
		newTable->getData(data);
		data.put("game_status", "plaing");
		data.put("game_score", "0");
}
boost::property_tree::ptree snakeGame::getData() {
	return data;
}
void snakeGame::makeSnakeMove(int direction) {
	if (data.get<std::string>("game_status") != "GAME OVER") {
		point newSnakeFoodPoint;
		auto newSnake = std::make_unique<Snake>(data);
		auto newFood = std::make_unique<snakeFood>(data.get<int>("snakefood.x"), data.get<int>("snakefood.y"));
		auto newTable = std::make_unique<table>(data.get<int>("table.width"), data.get<int>("table.height"));
		newSnakeFoodPoint.x = data.get<int>("snakefood.x");
		newSnakeFoodPoint.y = data.get<int>("snakefood.y");
		newSnake->setFoodPoint(newSnakeFoodPoint);
		if (newSnake->findFood(newSnakeFoodPoint)) {
			newFood->randomize(data.get<int>("table.width"), data.get<int>("table.height"));
			newFood->getData(data);
			auto game_score = data.get<int>("game_score");
			game_score++;
			data.put("game_score", game_score);
		}
		if (!newSnake->onTable(data.get<int>("table.width"), data.get<int>("table.height")) || newSnake->collision()) {
			data.put("game_status", "GAME OVER");
		}
		newSnake->changeDirection(Direction(direction));
		newSnake->getData(data);
	}
}