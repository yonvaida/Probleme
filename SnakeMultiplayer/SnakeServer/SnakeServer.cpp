#pragma once
#include "snakeServer.h"

snakeServer::snakeServer(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint &endpoint) :acceptor(ioService, endpoint), socket(ioService) {
	acceptConnection();
};
void snakeServer::acceptConnection() {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		std::cout << "connection accepted" << std::endl;
		if (!ec) {
			std::make_shared<snakeGame_session>(std::move(socket), game)->startSession();
		}
		
		acceptConnection();
	});
	
}
