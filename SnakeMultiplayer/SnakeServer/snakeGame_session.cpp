#pragma once
#include "snakeGame_session.h"

snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {
	
}
void snakeGame_session::readSnakeMove() {
	buf.resize(1);
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		if (!ec) {
		
		}
	});
	
}
void snakeGame_session::sendSnakeData() {
	
	boost::asio::async_write(snakeSocket, boost::asio::buffer(snakeposition), [&](const boost::system::error_code ec, size_t length) {
		if (ec) { snakeSocket.close(); };
		if(!ec){ 		
		//	boost::asio::async_write(snakeSocket, boost::asio::buffer(builder.GetBufferPointer(),builder.GetSize()), [](const boost::system::error_code ec,size_t length) {});
		}
	});

}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	playerSnake.elongate(snakehead, Direction::right);
	direction = 1;
	playerSnake.getData(data);
	snakeFood food;
	food.randomize(50, 50);
	food.getData(data);
	table board(50, 50);
	board.getData(data);
	readSnakeMove();
	data.put("game_status", "plaing");
	data.put("game_score", "1");
	
	
};
void snakeGame_session::movesnake() {
	readSnakeMove();
	
		playerSnake.changeDirection(Direction(direction));
		playerSnake.getData(data);
		serialize(builder, data);
		int val = 55;
		snakeposition.resize(4);
		std::memcpy(&snakeposition[0], &val, 4);
		std::cout << atoi(snakeposition.data()) << std::endl;
		
		sendSnakeData();
};
