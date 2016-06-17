#include "snakeServer.h"
#include "main.h"

std::string sendSnakeData(boost::asio::ip::tcp::socket &socket, boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	boost::property_tree::write_json(dataToSend, data);
	boost::asio::async_write(socket, boost::asio::buffer(dataToSend.str()), boost::asio::transfer_all());
	return dataToSend.str();
}
std::string readSnakeMove(boost::asio::ip::tcp::socket &socket) {
	std::vector<char> readBuffer(2054);
	socket.read_some(boost::asio::buffer(readBuffer));
	


	return readBuffer.data();

}