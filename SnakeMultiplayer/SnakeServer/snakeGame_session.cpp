#pragma once
#include "snakeGame_session.h"


snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	playerSnake.elongate(snakehead, Direction::right);
	direction = 1;
	playerSnake.getData(data);
	snakeposition = "";
}
void snakeGame_session::readSnakeMove() {
	buf.resize(1);
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		if (!ec) {
		sendSnakeData();
		}
	});
	
}
void snakeGame_session::sendSnakeData() {
	
	
	boost::asio::async_write(snakeSocket, boost::asio::buffer(snakeposition), [&](const boost::system::error_code ec, size_t length) {
		if (ec) { snakeSocket.close(); };
		if(!ec){ 
			readSnakeMove(); 
		}
		
	});

}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	
	readSnakeMove();
	
	
};
void snakeGame_session::movesnake() {
	std::cout << "move player snake" << std::endl;
		playerSnake.changeDirection(Direction(direction));
		playerSnake.getData(data);
		snakeposition = std::to_string(data.get<int>("snakebody.point0.x"));
		
};
