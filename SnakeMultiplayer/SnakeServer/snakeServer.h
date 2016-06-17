#pragma once
#include <string.h>
#include "main.h"
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>

class server{
public:
	server();
	std::string sendSnakeData(boost::property_tree::ptree data);
	std::string readSnakeMove();
	void serverAccept();
private:
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::socket socket;
};
