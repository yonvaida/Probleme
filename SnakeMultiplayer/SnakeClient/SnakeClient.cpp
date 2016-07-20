#include <boost\array.hpp>
#include "snakeclient.h"



clientNetwork::clientNetwork(boost::asio::io_service &ioService,std::string ip, std::string port):dataSocket(ioService) {
	
	connectToServer(ioService,ip, port);
};

void clientNetwork::connectToServer(boost::asio::io_service &ioService,std::string ip,std::string port) {
	boost::asio::ip::tcp::resolver resolver(ioService);
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::iterator end;
	boost::asio::ip::tcp::resolver::query query(ip,port);
	endpoint = resolver.resolve(query);
	buf.resize(1024);
	if (!error) {
		boost::asio::async_connect(dataSocket, endpoint, [&](const boost::system::error_code &ec,boost::asio::ip::tcp::resolver::iterator iterator) {
			if (!ec) {
				send();
			}
			
		
		});
    	}
	else {
		dataSocket.close();
		std::cout << "no connection" << std::endl;
	}
	
}

void clientNetwork::read() {
	boost::asio::async_read(dataSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		std::cout << ec.message() << std::endl;
		if (!ec) {
			std::cout << buf.data() << std::endl;
			send();
	}
	});
}

void clientNetwork::send() {
	boost::asio::async_write(dataSocket, boost::asio::buffer("2"), [&](const boost::system::error_code ec, size_t length) {
		if (!ec) {
			std::cout << buf.data() << std::endl;
			read();
		}
	});
	
	
};