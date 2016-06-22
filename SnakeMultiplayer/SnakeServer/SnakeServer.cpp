#include "snakeServer.h"
#include "main.h"
#include <iostream>

std::string  server::sendSnakeData(boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	flatbuffers::FlatBufferBuilder builder;
	auto board = snakedata::Createboarddata(builder,data.get<int>("table.width"),data.get<int>("table.height"));
	snakedata::snakebodydataBuilder snake_data(builder);
	snake_data.add_board(board);
	snake_data.Finish();

	uint8_t * bufferdata = builder.GetCurrentBufferPointer();
	std::cout << builder.GetSize() << std::endl;

	boost::property_tree::write_json(dataToSend, data);
	//data.put("size", dataToSend.str().size());
	//dataToSend.str("");
	//boost::property_tree::write_json(dataToSend, data);
	std::cout << dataToSend.str().length() << std::endl;
	boost::asio::async_write(socket,boost::asio::buffer(builder.GetCurrentBufferPointer(),builder.GetSize()), boost::asio::transfer_all());
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