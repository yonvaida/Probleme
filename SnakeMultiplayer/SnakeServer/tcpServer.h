#pragma once
#include "boost\asio.hpp"
#include <boost\property_tree\ptree.hpp>
#include "flatbuffer\snakedata_generated.h"
#include "serialization.h"
#include <iostream>
#include <memory>
#include "snakeServer.h"
#include "snakeGame.h"

class TCPserver {
public:
	TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer);
	void connectionAccept(snakeServer &snakeGamesServer);
	void setData(boost::property_tree::ptree &getdata);
	void removePlayerfromList(std::string player);
	void find(std::string player);
private:
	void createPlayersList(int snakeMove);
	boost::system::error_code error;
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::endpoint endPoint;
	std::vector<boost::property_tree::ptree> dataListofGames;
	std::vector<char> buf;
	boost::asio::ip::tcp::acceptor acceptor;
	std::vector<std::string> playersList;
	int getGameNumber;
};