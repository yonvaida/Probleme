#pragma once
#include "snakeGame_session.h"
snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {
}
void snakeGame_session::readSnakeMove() {
	buf.resize(1);
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		if (!ec) {
			direction = std::stoi(buf.data());
			if (direction == 5 && gameStatus=="GAME OVER") {
				newGame();
			}else if(direction==5 &&gameStatus=="plaing"){
				direction = 1;
			}
			readSnakeMove();
		}
	});
}
void snakeGame_session::sendSnakeData(std::vector<boost::property_tree::ptree> &data,int playerNumber) {
	builder.Clear();
	serialize(builder, data,playerNumber);
	bufferlength = builder.GetSize();
	std::vector<boost::asio::const_buffer> bufferToSend;
	bufferToSend.push_back(boost::asio::buffer((const char*)&bufferlength, 4));
	bufferToSend.push_back(boost::asio::buffer(builder.GetBufferPointer(),builder.GetSize()));
	boost::asio::async_write(snakeSocket, bufferToSend, [&](const boost::system::error_code ec, size_t length) {
		if (ec) { snakeSocket.close();
		game.leaveGame(shared_from_this());
		};
	});
}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	newGame();
};
void snakeGame_session::newGame() {
	score = 0;
	gameStatus = "plaing";
	data.clear();
	playerSnake.startSnake();
	readSnakeMove();
	bufferlength = builder.GetSize();
}
void snakeGame_session::movesnake() {
	if (gameStatus != "GAME OVER") {
		playerSnake.changeDirection(Direction(direction));
	}
};
void snakeGame_session::getsnake(boost::property_tree::ptree &data) {
	point foodpoint;
	game.food.getData(data);
	foodpoint.x = data.get<int>("snakefood.x");
	foodpoint.y = data.get<int>("snakefood.y");
	playerSnake.setFoodPoint(foodpoint);
	if (playerSnake.findFood(foodpoint)) {
		game.food.randomize(50, 50);
		score++;
	}
	if (!playerSnake.onTable(data.get<int>("table.width"), data.get<int>("table.height")) || playerSnake.collision(game.collisionList())) {
		gameStatus = "GAME OVER";
	};
	data.put("game_status", gameStatus);
	data.put("game_score",std::to_string(score));
	playerSnake.getData(data);
};