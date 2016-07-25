#pragma once
#include "snakeGame_session.h"
snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {
}
void snakeGame_session::readSnakeMove() {
	buf.resize(1);
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		if (!ec) {
			direction = std::stoi(buf.data());
			readSnakeMove();
		}
	});
}
void snakeGame_session::sendSnakeData() {
	boost::asio::async_write(snakeSocket, boost::asio::buffer((const char*)&bufferlength,4), [&](const boost::system::error_code ec, size_t length) {
		if (ec) { snakeSocket.close(); };
		if(!ec){ 	
			std::cout << builder.GetSize() << std::endl;
			boost::asio::async_write(snakeSocket, boost::asio::buffer(builder.GetBufferPointer(),builder.GetSize()), [&](const boost::system::error_code ec,size_t length) {
				if (!ec) {
				}
			});
		}
	});
}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	newGame();
};
void snakeGame_session::newGame() {
	data.clear();
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	playerSnake.elongate(snakehead, Direction::right);
	playerSnake.getData(data);
	game.createSnakeBoard(data);
	game.createSnakeFood(data);
	data.put("game_status", "plaing");
	data.put("game_score", "0");
	readSnakeMove();
	playerSnake.getData(data);
	serialize(builder, data);
	bufferlength = builder.GetSize();
	sendSnakeData();
}
void snakeGame_session::movesnake() {
	point foodpoint;
		playerSnake.changeDirection(Direction(direction));
		playerSnake.getData(data);
		game.food.getData(data);
		foodpoint.x = data.get<int>("snakefood.x");
		foodpoint.y = data.get<int>("snakefood.y");
		playerSnake.setFoodPoint(foodpoint);
		if (playerSnake.findFood(foodpoint)) {
			game.food.randomize(50, 50);
			game.food.getData(data);
			data.put("game_score", std::to_string(data.get<int>("game_score") + 1));
		}
		if (!playerSnake.onTable(data.get<int>("table.width"),data.get<int>("table.height")) || playerSnake.collision()) {
			data.put("game_status", "GAME OVER");
		}
			builder.Clear();
			serialize(builder, data);
			bufferlength = builder.GetSize();
			sendSnakeData();

		
};
