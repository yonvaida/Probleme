#include "snakeServer.h"
#include <iostream>
#include "boost\array.hpp"
#include "serialization.h"

TCPserver::TCPserver(boost::asio::io_service &ioService) : acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 32560)), socket(ioService) {
		TCPserver::connectionAccept();
	};
	void TCPserver::connectionAccept() {
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
				connectionAccept();
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

	snakeGame::snakeGame(boost::property_tree::ptree &data,int direction) {
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
			data.put("game_score", "0");
		}
		else {
			if (data.get<std::string>("game_status") != "GAME OVER") {
				point newSnakeFoodPoint;
				auto newSnake = std::make_unique<Snake>(data);
				auto newFood = std::make_unique<snakeFood>(data.get<int>("snakefood.x"), data.get<int>("snakefood.y"));
				auto newTable = std::make_unique<table>(data.get<int>("table.width"), data.get<int>("table.height"));
				newSnakeFoodPoint.x = data.get<int>("snakefood.x");
				newSnakeFoodPoint.y = data.get<int>("snakefood.y");
				newSnake->setFoodPoint(newSnakeFoodPoint);
				if (newSnake->findFood(newSnakeFoodPoint)) {
					newFood->randomize(data.get<int>("table.width"), data.get<int>("table.height"));
					newFood->getData(data);
					auto game_score = data.get<int>("game_score");
					game_score++;
					data.put("game_score", game_score);
				}
				if (!newSnake->onTable(data.get<int>("table.width"), data.get<int>("table.height")) || newSnake->collision()) {
					data.put("game_status", "GAME OVER");
				}
				newSnake->changeDirection(Direction(direction));
				newSnake->getData(data);
			}
			
		}
		


	}

