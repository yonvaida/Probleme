#include "snakeServer.h"
#include "main.h"

std::string  server::sendSnakeData(boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	boost::property_tree::write_json(dataToSend, data);
	boost::asio::async_write(socket, boost::asio::buffer(dataToSend.str()), boost::asio::transfer_all());
	return dataToSend.str();
};
std::string server::readSnakeMove() {
	std::vector<char> readBuffer(2054);
	socket.read_some(boost::asio::buffer(readBuffer));
	return readBuffer.data();
};
server::server():socket(io_service) {
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1200));
	acceptor.accept(socket);
};
void server::serverAccept() {
	
}