#pragma once
#include "snakeGame_session.h"

snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {

}
void snakeGame_session::readSnakeMove() {
	std::vector<char> bufdata;
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		std::cout << "Reading is ok" << std::endl;
		std::cout << length << std::endl;
		if (!ec) {
			std::cout << game.getNumberofPlayers() << std::endl;
			//game.leaveGame(shared_from_this());
			//std::cout << game.getNumberofPlayers() << std::endl;
			//game.leaveGame(shared_from_this());
			//game.getNumberofPlayers();
			readSnakeMove();
		}
		
	});
	
	//size_t length= boost::asio::read(socket, boost::asio::buffer(bufdata));
	//bufdata.resize(length);
	//std::cout << length << std::endl;
	//std::cout << buf.data() << std::endl;
}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	readSnakeMove();

};
void snakeGame_session::movesnake(int direction) {};
