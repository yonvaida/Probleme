#include "tcpServer.h"

TCPserver::TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer) :acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)),socket(ioService) {
	TCPserver::asyncConnection(snakeGamesServer);
}

void TCPserver::asyncConnection(snakeServer &snakeGamesServer) {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		
		flatbuffers::FlatBufferBuilder builder;
		boost::property_tree::ptree data;
		
		if (!ec) {
			std::vector<char> buf;
			buf.resize(1);
			socket.read_some(boost::asio::buffer(buf),error);
			int direction = buf.at(0);
			direction = direction - 48;
			snakeGamesServer.moveSnakeInGame(direction, socket.remote_endpoint().address().to_string());
			data = snakeGamesServer.getGame(socket.remote_endpoint().address().to_string()).getData();
			serialize(builder,data);
			socket.write_some(boost::asio::buffer(builder.GetCurrentBufferPointer(), builder.GetSize()),error);
			socket.close();
			asyncConnection(snakeGamesServer);
		}
	});
	
}

