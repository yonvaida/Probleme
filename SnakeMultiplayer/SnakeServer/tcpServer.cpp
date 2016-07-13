#include "tcpServer.h"

TCPserver::TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer) :acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)),socket(ioService) {
	TCPserver::asyncConnection(snakeGamesServer);
}

void TCPserver::asyncConnection(snakeServer &snakeGamesServer) {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		std::vector<char> buf;
		flatbuffers::FlatBufferBuilder builder;
		buf.resize(1);
		if (!ec) {
			boost::asio::read(socket, boost::asio::buffer(buf));
			int direction = (int)buf.data();
			snakeGamesServer.moveSnakeInGame(direction, socket.remote_endpoint().address().to_string());
			serialize(builder,snakeGamesServer.getGame().getData());
			boost::asio::write(socket, boost::asio::buffer(builder.GetCurrentBufferPointer(), builder.GetSize()));
		}
		TCPserver::asyncConnection(snakeGamesServer);
	});
}

