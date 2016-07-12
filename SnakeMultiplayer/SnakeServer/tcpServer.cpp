#include "tcpServer.h"


TCPserver::TCPserver(boost::asio::io_service &ioService,snakeServer &snakeGamesServer) : acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)), socket(ioService) {
	TCPserver::connectionAccept(snakeGamesServer);
};
void TCPserver::connectionAccept(snakeServer &snakeGamesServer) {
	acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
		flatbuffers::FlatBufferBuilder builder;
		if (!ec) {
			int snakeMove;
			buf.resize(1);
			socket.read_some(boost::asio::buffer(buf), error);


			snakeMove = std::stoi(buf.data());
			createPlayersList(snakeMove);
			serialize(builder, dataListofGames.at(getGameNumber));
			int length = builder.GetSize();
			socket.write_some(boost::asio::buffer(builder.GetCurrentBufferPointer(), builder.GetSize()), error);
			
			socket.close();
		}
		connectionAccept(snakeGamesServer);
	});
}

void TCPserver::createPlayersList(int snakeMove) {
	boost::property_tree::ptree tempData;
	int gameNumber = -1;
	for (int index = 0; index < playersList.size(); index++) {
		if (playersList.at(index) == socket.remote_endpoint().address().to_string()) {
			gameNumber = index;
		}
	}
	if (gameNumber == -1) {
		playersList.push_back(socket.remote_endpoint().address().to_string());
		auto newsnakeGame = std::make_unique<snakeGame>(tempData, snakeMove);
		dataListofGames.push_back(tempData);
		gameNumber = playersList.size() - 1;
	}
	else {
		auto newsnakeGame = std::make_unique<snakeGame>(dataListofGames.at(gameNumber), snakeMove);
	}
	getGameNumber = gameNumber;
	
}
