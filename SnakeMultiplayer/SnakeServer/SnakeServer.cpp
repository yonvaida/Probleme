#pragma once
#include "snakeServer.h"

snakeServer::snakeServer(boost::asio::io_service &ioService, boost::asio::ip::tcp::endpoint &endpoint) :acceptor(ioService, endpoint), socket(ioService),serverTimer(ioService) {
	acceptConnection();
	movePlayersSnake();
};
void snakeServer::acceptConnection() {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		
		if (!ec) {
			std::make_shared<snakeGame_session>(std::move(socket), game)->startSession();
			
		}
		
		acceptConnection();
	});
	
}

void snakeServer::movePlayersSnake() {
	std::cout << "making moves" << std::endl;
	game.makeMove();
	std::cout<<game.getNumberofPlayers() << std::endl;
	serverTimer.expires_from_now(boost::posix_time::seconds(2));
	serverTimer.async_wait([&](const boost::system::error_code ec) {
	
		
		movePlayersSnake();
	});
}