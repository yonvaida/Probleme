
//#include "snakeWithTest\main.h"
#include <iostream>
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <string>
#include "deserialization.h"


class clientNetwork {
public:
	clientNetwork(boost::asio::io_service &ioService,std::string ip, std::string port);
	void read();
	void send();
	boost::system::error_code error;
private:
	
	void connectToServer(boost::asio::io_service &ioService, std::string ip , std::string port);
	boost::asio::ip::tcp::socket dataSocket;
	std::vector<char> buf;
};