#include "snakeServer.h"
#include <iostream>
#include "boost\array.hpp"
#include "serialization.h"

TCPserver::TCPserver(boost::asio::io_service &ioService) : acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)), socket(ioService) {
		TCPserver::connectionAccept();
	};
	void TCPserver::connectionAccept() {
		
		
		boost::asio::ip::tcp::socket tempSocket(acceptor.get_io_service());
		acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
			boost::property_tree::ptree tempData;
			flatbuffers::FlatBufferBuilder builder;
			int gameNumber = -1;
			std::cout << ec.message() << std::endl;
			if (!ec) {
				buf.resize(1);
				socket.read_some(boost::asio::buffer(buf), error);

				if (playersList.size() == 0) {
					playersList.push_back(socket.remote_endpoint().address().to_string());
					auto newGameServer = std::make_unique<GameServer>(tempData,buf.data());
					dataListofGames.push_back(tempData);
					gameNumber = 0;
				}
			else {
				for (int index = 0; index < playersList.size(); index++) {
					if (playersList.at(index) == socket.remote_endpoint().address().to_string()) {
						gameNumber = index;
					}
				}
				if (gameNumber == -1) {
					playersList.push_back(socket.remote_endpoint().address().to_string());
					auto newGameServer = std::make_unique<GameServer>(tempData , buf.data());
					dataListofGames.push_back(tempData);
					gameNumber = playersList.size()-1;
				}else{
					auto newGameServer = std::make_unique<GameServer>(dataListofGames.at(gameNumber), buf.data());
					//dataListofGames.push_back(tempData);
				}
				std::cout << gameNumber << std::endl;
			}

			

}			
			serialize(builder, dataListofGames.at(gameNumber));
			
			int length = builder.GetSize();
			socket.write_some(boost::asio::buffer(builder.GetCurrentBufferPointer(),builder.GetSize()), error);
				std::cout << buf.data()<<std::endl;
			
				socket.close();
				connectionAccept();
		});
	}

	void TCPserver::setData(boost::property_tree::ptree &getdata) {
		//data = getdata;
	}
	void TCPserver::createPlayersList() {

	}

	GameServer::GameServer(boost::property_tree::ptree &data,std::string direction) {
		if (data.empty()) {
			auto newTable = std::make_unique<table>(50, 50);
			auto newFood = std::make_unique<snakeFood>();
			newFood->randomize(50, 50);
			auto newSnake = std::make_unique<Snake>();
			auto newSnakeHead = std::make_unique<point>();
			newSnakeHead->x = 0;
			newSnakeHead->y = 0;
			newSnake->elongate(*newSnakeHead, Direction::right);
			newSnake->getData(data);
			newFood->getData(data);
			newTable->getData(data);
			data.put("game_status", "plaing");
			data.put("game_score", "5");
		}
		else {
			auto newSnake = std::make_unique<Snake>(data);
			auto newFood = std::make_unique<snakeFood>(data.get<int>("snakefood.x"),data.get<int>("snakefood.y"));
			auto newTable = std::make_unique<table>(data.get<int>("table.width"), data.get<int>("table.height"));
			newSnake->changeDirection(Direction(std::stoi(direction)));
			newSnake->getData(data);
			std::cout << "Snake created from ptree" << std::endl;
		}
		


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




