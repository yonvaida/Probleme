#include <boost\array.hpp>
#include "snakeclient.h"



clientNetwork::clientNetwork(std::string ip, std::string port):dataSocket(ioService) {
	connectToServer(ip, port);
};

void clientNetwork::connectToServer(std::string ip,std::string port) {
	boost::asio::ip::tcp::resolver resolver(ioService);
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::iterator end;
	boost::asio::ip::tcp::resolver::query query(ip,port);
	endpoint = resolver.resolve(query);
	if (!error) {
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
	buf.resize(1024);
	if (error) {
		dataSocket.close();
		std::cout << "No connection from server" << std::endl;
	}else {
		size_t length = dataSocket.read_some(boost::asio::buffer(buf), error);
		buf.resize(static_cast<int>(length));
		deserialize(buf, data);
	}
		std::string temp;
		for (int i = 0; i < buf.size(); i++) {
			temp += buf.at(0);
		}
		return data;
}

void clientNetwork::send(std::string sentMessage) {
	std::cout << "writing" << std::endl;
	std::cout<<dataSocket.is_open()<<std::endl;
		boost::asio::async_write(dataSocket, boost::asio::buffer(sentMessage), [&](const boost::system::error_code &ec,size_t length) {
			std::cout << ec.message() << std::endl;
			if (!ec) {
				send("123");
				std::cout << ec.message() << std::endl;
			}
			else {
				send("123");
				std::cout << ec.message() << std::endl;
			}
			
		});
	
	
};