#pragma once
#include "boost/asio.hpp"
#include "snakeGame.h"
#include "snakeGame_session.h"
#include <string>

class snakeServer {
public:
	snakeServer(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint &endpoint) ;
	void acceptConnection();
	void movePlayersSnake();
private:
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::ip::tcp::socket socket;
	boost::asio::deadline_timer serverTimer;
	snakeGame game;
};

