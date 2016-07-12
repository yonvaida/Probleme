#pragma once
#include <string.h>
#include "snake.h"
#include "snakeFood.h"
#include "table.h" 
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include "flatbuffer\snakedata_generated.h"
#include <vector>

class TCPserver {
public:
	TCPserver(boost::asio::io_service &ioService);
	void connectionAccept();
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



class snakeGame {
public:
	snakeGame(boost::property_tree::ptree &data,int direction);
	void makeSnakeMove();
};