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
	int length = builder.GetSize();
	//std::cout << length << std::endl;
	boost::asio::async_write(socket, boost::asio::buffer(builder.GetBufferPointer(), builder.GetSize()), boost::asio::transfer_all(), [] (const boost::system::error_code &error, std::size_t byte_transfered){
		if (!error) {
			std::cout << "Write is ok" << std::endl;
		}
		else {
			std::cout << "Async server write error"<<error << std::endl;

		}
	}			);
	return dataToSend.str();
};
std::string server::readSnakeMove() {
	std::vector<char> readBuffer(2054);
	boost::system::error_code ec;
	boost::asio::async_read(socket, boost::asio::buffer(readBuffer), [](const boost::system::error_code &ec, size_t bytes_transfered) {});
		//std::cout << ec << std::endl;
		return readBuffer.data();
};
bool server::socketStatus() {
	if (socket.is_open()) {
		return true;
	};
	return false;
};

server::server():socket(io_service),endpoint(boost::asio::ip::tcp::v4(), 32560) {
	boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint);
	acceptor.accept(socket, endpoint);
	
	//boost::asio::ip::tcp::no_delay option(true);
	
	auto search = ipList.find(endpoint.address().to_string());
	size_t length = 0;
	if (ipList.size() == length) {
	ipList.insert(endpoint.address().to_string());
	std::cout << *(ipList.begin()) << " - " << ipList.size() << std::endl;
	
	}
	socket.set_option(boost::asio::ip::tcp::no_delay(true));
	
	

	
};
void server::serverAccept() {}
void server::serverShutdown() {
	socket.close();
}
void server::run() {
	io_service.run();
}
void readHandler(const boost::system::error_code &error, std::size_t byte_transfered) {
	if (!error) {
		std::cout << "connection ok" << std::endl;
	}
}


//--------------------------------------------------------------------------------


snakeClient::snakeClient(boost::asio::ip::tcp::socket clientSocket) {

};



//-------------------------------------------------------------------------------
Game::Game() {

}
void Game::joinGame(snakeClient snakePlayer){


}