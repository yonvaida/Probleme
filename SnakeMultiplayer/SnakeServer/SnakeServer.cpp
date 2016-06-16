#include "snakeServer.h"

std::string sendSnakeData(boost::asio::ip::tcp::socket &socket, boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	boost::property_tree::write_json(dataToSend, data);
	boost::asio::write(socket, boost::asio::buffer(dataToSend.str()), boost::asio::transfer_all());
	return dataToSend.str();
}
std::string readSnakeMove(boost::asio::ip::tcp::socket &socket) {
	std::vector<char> readBuffer(2054);
	boost::asio::read(socket,boost::asio::buffer(readBuffer));
	return readBuffer.data();

}