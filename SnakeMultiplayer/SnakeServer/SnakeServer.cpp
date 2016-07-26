#pragma once
#include "snakeServer.h"

snakeServer::snakeServer(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint &endpoint) :acceptor(ioService, endpoint), socket(ioService),snakeTimer(ioService) {
	acceptConnection();
	makemoves();
};
void snakeServer::acceptConnection() {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		
		if (!ec) {
			std::make_shared<snakeGame_session>(std::move(socket), game)->startSession();
		}
		
		acceptConnection();
	});
}
void snakeServer::makemoves() {
	snakeTimer.expires_from_now(boost::posix_time::milliseconds(1000));
	snakeTimer.async_wait([&](const boost::system::error_code ec) {
		std::cout << "timer expire" << std::endl;
		game.moveSnakes();
		makemoves();
	});
}