#pragma once
#include "boost\asio.hpp"
#include "snakeGame.h"
#include "snakePlayer.h"
#include "boost\enable_shared_from_this.hpp"
#include <conio.h>
#include <Windows.h>
class snakeGame_session :public snakePlayer,public std::enable_shared_from_this<snakeGame_session> {

public:
	snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame);
	void startSession();
	void readSnakeMove();
	void sendSnakeData();
	void initiateSnake();
	void movesnake();
private:
	boost::property_tree::ptree data;
	boost::asio::ip::tcp::socket snakeSocket;
	snakeGame &game;
	std::vector<char>buf;
	Snake playerSnake;
	std::string snakeposition;
	int direction;
};