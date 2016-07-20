#pragma once
#include "snakeGame_session.h"

snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):socket(std::move(newSocket)),game(mainGame) {

}
void snakeGame_session::readSnakeMove() {
	std::vector<char> bufdata;
	size_t length= boost::asio::read(socket, boost::asio::buffer(bufdata));
	//bufdata.resize(length);
	std::cout << length << std::endl;
	//std::cout << buf.data() << std::endl;
}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	readSnakeMove();

};
void snakeGame_session::movesnake(int direction) {};
