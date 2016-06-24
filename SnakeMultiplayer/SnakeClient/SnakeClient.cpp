#include <boost\array.hpp>
#include "snakeclient.h"

void convertToPtree(std::string bufferValue,std::size_t length, boost::property_tree::ptree &data) {
	std::stringstream temp;
	temp.str(bufferValue.substr(0,length));
	boost::property_tree::read_json(temp, data);
};

clientNetwork::clientNetwork(std::string ip, std::string port):dataSocket(ioService) {
	connectToServer(ip, port);
};
void clientNetwork::connectToServer(std::string ip,std::string port) {
	boost::asio::ip::tcp::resolver resolver(ioService);
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::iterator end;
	boost::asio::ip::tcp::resolver::query query(ip,port);
	endpoint = resolver.resolve(query,error);
	if (endpoint != end) {
		boost::asio::connect(dataSocket, endpoint);

	}
	else {
		dataSocket.close();
		std::cout << "no connection" << std::endl;
	}
	
}
boost::property_tree::ptree clientNetwork::read() {
	boost::property_tree::ptree data;
	std::vector<uint8_t> buf;
	std::vector<char> length;
	length.resize(40);
	if (error) {
		dataSocket.close();
		std::cout << "No connection from server" << std::endl;
	}else {
		dataSocket.read_some(boost::asio::buffer(length), error);
		buf.resize(std::stoi(length.data()));
		dataSocket.read_some(boost::asio::buffer(buf), error);
		deserialize(buf, data);
	}
	
	return data;
}
void clientNetwork::send(std::string sentMessage) {
	if (error) {
		dataSocket.close();
		std::cout << "No connection from server" << std::endl;
	}
	else {
		dataSocket.write_some(boost::asio::buffer(sentMessage), error);
	}
	
};