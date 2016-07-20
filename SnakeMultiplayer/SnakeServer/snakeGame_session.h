#pragma once
#include "boost\asio.hpp"
#include "snakeGame.h"
#include "snakePlayer.h"
#include "boost\enable_shared_from_this.hpp"

class snakeGame_session :public snakePlayer,public std::enable_shared_from_this<snakeGame_session> {

public:
	snakeGame_session(boost::asio::ip::tcp::socket socket, snakeGame &mainGame);
	void startSession();
	void readSnakeMove();
	void movesnake(int direction);
private:
	boost::asio::ip::tcp::socket snakeSocket;
	snakeGame &game;
	std::vector<char>buf;
};