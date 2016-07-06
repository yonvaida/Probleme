#pragma once
#include <string.h>
#include "main.h"
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include "flatbuffer\snakedata_generated.h"

class server{
public:
	server();
	std::string sendSnakeData(boost::property_tree::ptree data);
	std::string readSnakeMove();
	void serverAccept();
	void serverShutdown();
	bool socketStatus();
	void run();
private:
	std::set<std::string> ipList;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::endpoint endpoint;
};

class snakeClient {
public:
	snakeClient(boost::asio::ip::tcp::socket clientSocket);
};

void readHandler(const boost::system::error_code &error, std::size_t byte_transfered);


class Game {
public:
	Game();
	void joinGame(snakeClient snakePlayer);
};