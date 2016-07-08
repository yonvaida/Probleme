// SnakeServer.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "boost\asio.hpp"
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <boost\asio\basic_stream_socket.hpp>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "snake.h"
#include "snakeFood.h"
#include "table.h"
#include "main.h"
#include "snakeServer.h"




int main()
{
	for (;;) {
		try {

			/*boost::property_tree::ptree data;
			table table(50, 50);
			snakeFood snakefood;
			Snake snake;
			point head;
			head.x = 0;
			head.y = 0;
			snake.elongate(head, Direction::right);
			point foodpoint;
			std::string serverResponse;
			std::string clientResponse;
			snakefood.randomize(50, 50);
			int score = 0;
			int connectedClients = 0;
			boost::asio::io_service io_service;
				server snakeServer(io_service);
				//clientResponse = snakeServer.readSnakeMove();
				//if (clientResponse == "n") { std::cout << clientResponse << std::endl; connectedClients++; clientResponse = "1"; }
				// client response is a string that represent the index of direction value
				table.getData(data);
				snake.getData(data);
				snakefood.getData(data);
				snakeServer.setDataPtree(data);
				foodpoint.x = data.get<int>("snakefood.x");
				foodpoint.y = data.get<int>("snakefood.y");
				snake.setFoodPoint(foodpoint);
				if (snake.findFood(foodpoint)) {
					snakefood.randomize(50, 50);
					score++;
				};
				data.put("game_score", score);
			/*	if (snake.collision() || !snake.onTable(table)) {
					snake.changeDirection(Direction::stay);
					data.put("game_status", "GAME OVER");
					snakeServer.sendSnakeData(data);
					serverResponse = snakeServer.sendSnakeData(data);
				}
				else {
					data.put("game_status", "Plaing");
					snake.changeDirection(Direction(std::stoi(clientResponse)));
					//snake.changeDirection(Direction(1));
					snakeServer.sendSnakeData(data);
					serverResponse = snakeServer.sendSnakeData(data);
				}*/
				//system("cls");
				//std::cout << snakeServer.socketStatus() << std::endl;
				//std::cout << "Server is running ..." << std::endl;
				//std::cout << "Server response : " << serverResponse << std::endl;
				//std::cout << "Client response : " << clientResponse << std::endl;
				//std::cout << connectedClients << std::endl;
				//serverResponse = snakeServer.sendSnakeData(data);
			boost::asio::io_service ioService;
			TCPserver snakeServer(ioService);
			
			ioService.run();
			

		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
	}
		

	
	
		
	
	return 0;
}

/*
boost::property_tree::ptree data;
table table(50, 50);
snakeFood snakefood;
Snake snake;
point head;
head.x = 0;
head.y = 0;
snake.elongate(head, Direction::right);
point foodpoint;
std::string serverResponse;
std::string clientResponse;
snakefood.randomize(50, 50);
int score = 0;
int connectedClients = 0;
table.getData(data);
snake.getData(data);
snakefood.getData(data);
snakeServer.setData(data);
*/