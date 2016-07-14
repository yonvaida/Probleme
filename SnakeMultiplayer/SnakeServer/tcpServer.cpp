#include "tcpServer.h"

TCPserver::TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer) :acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)),socket(ioService) {
	TCPserver::asyncConnection(snakeGamesServer);
}

void TCPserver::asyncConnection(snakeServer &snakeGamesServer) {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		asyncConnection(snakeGamesServer);	
		flatbuffers::FlatBufferBuilder builder;
		boost::property_tree::ptree data;
		if (!ec) {
			//auto socket1 = std::move(socket);
			std::vector<char> buf;
			buf.resize(1);
			boost::asio::read(socket, boost::asio::buffer(buf), boost::asio::transfer_all(), error);
			int direction = buf.at(0);
			direction = direction - 48;
			snakeGamesServer.moveSnakeInGame(direction, socket.remote_endpoint().address().to_string());
			
			serialize(builder, snakeGamesServer.getGame(socket.remote_endpoint().address().to_string()).getData());
			boost::asio::write(socket, boost::asio::buffer(builder.GetCurrentBufferPointer(), builder.GetSize()), boost::asio::transfer_all(), error);
			if (error) {
							snakeGamesServer.removeGame(socket.remote_endpoint().address().to_string());
						}
					};

		socket.close();
				
			});

			
		}
	

