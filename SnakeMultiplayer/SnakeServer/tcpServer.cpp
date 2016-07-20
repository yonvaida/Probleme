#include "tcpServer.h"
/*
TCPserver::TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer) :acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)),socket(ioService),timer(ioService,boost::posix_time::milliseconds(100)) {
	TCPserver::asyncConnection(snakeGamesServer,ioService);
}

void TCPserver::asyncConnection(snakeServer &snakeGamesServer, boost::asio::io_service &ioService) {
	
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		asyncConnection(snakeGamesServer, ioService);
		boost::property_tree::ptree data;

		if (!ec) {
					
					//auto socket1 = std::move(socket);
					
					timer.async_wait([&](const boost::system::error_code &ec) {
						std::vector<char> buf;
						buf.resize(1);
						boost::asio::read(socket, boost::asio::buffer(buf), boost::asio::transfer_all(), error);
						int direction = buf.at(0);
						direction = direction - 48;
						flatbuffers::FlatBufferBuilder builder;
						std::cout << "true" << std::endl;
						//snakeGamesServer.moveSnakeInGame(1, socket.remote_endpoint().address().to_string());
						//	}

						snakeGamesServer.moveSnakeInGame(direction, socket.remote_endpoint().address().to_string());
						serialize(builder, snakeGamesServer.getGame(socket.remote_endpoint().address().to_string()).getData());
						boost::asio::write(socket, boost::asio::buffer(builder.GetCurrentBufferPointer(), builder.GetSize()), boost::asio::transfer_all(), error);
						socket.close();
						
					});

					//if (snakeGamesServer.getGame(socket.remote_endpoint().address().to_string()).getData().empty()) {
					
					
		
			
			std::cout << "move" << std::endl;
			
			
			if (error) {
							snakeGamesServer.removeGame(socket.remote_endpoint().address().to_string());
						}
					};

		
			});

			
		}
	

	*/