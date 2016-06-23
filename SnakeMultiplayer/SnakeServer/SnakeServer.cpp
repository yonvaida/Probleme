#include "snakeServer.h"
#include "main.h"
#include <iostream>
#include "boost\array.hpp"
#include "serialization.h"

std::string  server::sendSnakeData(boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	flatbuffers::FlatBufferBuilder builder;
	
	serialize(builder, data);
	auto getdatafrom = snakedata::Getsnakebodydata(builder.GetBufferPointer());
	auto table = getdatafrom->board()->width();
	std::cout << table << std::endl;
	int length = builder.GetSize();
	std::cout << length << std::endl;

	boost::asio::async_write(socket,boost::asio::buffer(std::to_string(length)), boost::asio::transfer_all());
	boost::asio::async_write(socket, boost::asio::buffer(builder.GetBufferPointer(),builder.GetSize()),boost::asio::transfer_all());
	return dataToSend.str();
};
std::string server::readSnakeMove() {
	std::vector<char> readBuffer(2054);
	
		socket.read_some(boost::asio::buffer(readBuffer));
		return readBuffer.data();
	
};
server::server():socket(io_service) {
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560));
	//boost::asio::ip::tcp::no_delay option(true);
	acceptor.accept(socket);
	socket.set_option(boost::asio::ip::tcp::no_delay(true));
	
};
void server::serverAccept() {
	
}
void server::serverShutdown() {
	socket.close();
}