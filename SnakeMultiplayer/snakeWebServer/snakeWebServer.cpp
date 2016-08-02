// snakeWebServer.cpp : Defines the entry point for the console application.
//
#include "boost\asio.hpp"
#include <iostream>
#include <vector>
#include <string>
int i = 0;
std::vector<char> buf;

void readwrite(boost::asio::ip::tcp::socket &socket) {
	buf.resize(1024);
	boost::asio::async_read(socket, boost::asio::buffer(buf), [&](const boost::system::error_code ec, size_t length) {
		std::cout << buf.data() << std::endl;
		boost::asio::async_write(socket, boost::asio::buffer("<html>MERGE</html>"), [&](const boost::system::error_code ec, size_t length) {
			readwrite(socket);

		});

	});


	std::cout << buf.data() << std::endl;
}


void acceptConnection(boost::asio::ip::tcp::socket &serverSocket, boost::asio::ip::tcp::endpoint &serverEndpoint,boost::asio::ip::tcp::acceptor &serverAcceptor) {
	serverAcceptor.async_accept(serverSocket, serverEndpoint, [&](const boost::system::error_code &ec) {
		i++;
		std::vector<char> buf;
		buf.resize(1);
		std::cout << "Connection accepted" << std::endl;
		
		readwrite(serverSocket);
		
	});
}


int main()
{
	try {
		boost::asio::io_service ioService;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 1080);
		boost::asio::ip::tcp::socket serverSocket(ioService);
		boost::asio::ip::tcp::acceptor serverAcceptor(ioService, endpoint);

		acceptConnection(serverSocket, endpoint, serverAcceptor);






		ioService.run();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

