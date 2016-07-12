
//#include "snakeWithTest\main.h"
#include <iostream>
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <string>
#include "deserialization.h"


class clientNetwork {
public:
	clientNetwork(std::string ip, std::string port);
	boost::property_tree::ptree read();
	void send(std::string sentMessage);
	boost::system::error_code error;
private:
	boost::asio::io_service ioService;
	void connectToServer(std::string ip , std::string port);
	boost::asio::ip::tcp::socket dataSocket;
};