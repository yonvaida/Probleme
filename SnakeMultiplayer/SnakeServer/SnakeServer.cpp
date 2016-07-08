#include "snakeServer.h"
#include "main.h"
#include <iostream>
#include "boost\array.hpp"
#include "serialization.h"

TCPserver::TCPserver(boost::asio::io_service &ioService) : acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)), socket(ioService) {
		TCPserver::connectionAccept();
	};
	void TCPserver::connectionAccept() {
		buf.resize(1024);
		boost::asio::ip::tcp::socket tempSocket(acceptor.get_io_service());
		acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
			int gameNumber = -1;
			std::cout << ec.message() << std::endl;
			if (!ec) {
				if (playersList.size() == 0) {
					playersList.push_back(socket.remote_endpoint().address().to_string());
				}
			else {
				for (int index = 0; index < playersList.size(); index++) {
					if (playersList.at(index) == socket.remote_endpoint().address().to_string()) {
						gameNumber = index;
					}
				}
				if (gameNumber == -1) {
					playersList.push_back(socket.remote_endpoint().address().to_string());
				}
				std::cout << gameNumber << std::endl;
			}
}
				system("cls");
				//std::cout << playersList.size() << std::endl;
				socket.read_some(boost::asio::buffer(buf), error);
				//std::string temp = data.get<std::string>("table.width");
				socket.write_some(boost::asio::buffer("snake data"), error);
				std::cout << buf.data()<<std::endl;
				//std::cout << buf.data() << std::endl;
				socket.close();
				connectionAccept();
		});
	}

	void TCPserver::setData(boost::property_tree::ptree &getdata) {
		//data = getdata;
	}












/*
std::string  server::sendSnakeData(boost::property_tree::ptree data) {
	std::ostringstream dataToSend;
	flatbuffers::FlatBufferBuilder builder;
	serialize(builder, data);
	auto getdatafrom = snakedata::Getsnakebodydata(builder.GetBufferPointer());
	int length = builder.GetSize();
	//std::cout << length << std::endl;
	boost::asio::async_write(socket, boost::asio::buffer(builder.GetBufferPointer(), builder.GetSize()), boost::asio::transfer_all(), [] (const boost::system::error_code &error, std::size_t byte_transfered){
		if (!error) {
			std::cout << "Write is ok" << std::endl;
		}
		else {
			std::cout << "Async server write error"<<error << std::endl;

		}
	}			);
	return dataToSend.str();
};
std::string server::readSnakeMove() {
	std::vector<char> readBuffer(2054);
	boost::system::error_code ec;
	boost::asio::async_read(socket, boost::asio::buffer(readBuffer), [](const boost::system::error_code &ec, size_t bytes_transfered) {});
		//std::cout << ec << std::endl;
		return readBuffer.data();
};


server::server(boost::asio::io_service &ioService):socket(ioService), endpoint(boost::asio::ip::tcp::v4(), 32560), acceptor(ioService, endpoint) {


};
void server::serverAccept() {
	//boost::asio::ip::tcp::socket socket(acceptor.get_io_service());
acceptor.async_accept(socket, [&]() {
	readSnakeMove();
	sendSnakeData(data);
	socket.close();
	serverAccept();
});

	

}

void server::setDataPtree(boost::property_tree::ptree &snakeData) {
	data = snakeData;
}



//--------------------------------------------------------------------------------


snakeClient::snakeClient(boost::asio::ip::tcp::socket clientSocket) {

};



//-------------------------------------------------------------------------------
Game::Game() {

}
void Game::joinGame(snakeClient snakePlayer){
}*/




