
//#include "snakeWithTest\main.h"
#include <iostream>
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <string>
#include "deserialization.h"

void convertToPtree(std::string bufferValue, std::size_t length, boost::property_tree::ptree &data);
class clientNetwork {
public:
	clientNetwork(std::string ip, std::string port);
	std::string read();
	void send(std::string sentMessage);
	boost::system::error_code error;
private:
	boost::asio::io_service ioService;
	void connectToServer(std::string ip , std::string port);
	boost::asio::ip::tcp::socket dataSocket;
};