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
	
		try {
			
			
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
			//builder.GetBufferPointer();
			//std::cout << board.GetBufferPointer() << std::endl;
			while (true) {
				server snakeServer;
				clientResponse = snakeServer.readSnakeMove();
				 // client response is a string that represent the index of direction value
				table.getData(data);
				snake.getData(data);
				snakefood.getData(data);
				foodpoint.x = data.get<int>("snakefood.x");
				foodpoint.y = data.get<int>("snakefood.y");
				
				snake.setFoodPoint(foodpoint);

				if (snake.findFood(foodpoint)) {
					snakefood.randomize(50, 50);
					score++;
				};
				data.put("game_score", score);
				if (snake.collision() || !snake.onTable(table)) {
					//snakeServer.serverShutdown();
					snake.changeDirection(Direction::stay);
					data.put("game_status","GAME OVER");
					snakeServer.sendSnakeData(data);
					serverResponse = snakeServer.sendSnakeData(data);
				}
				else {
					data.put("game_status", "Plaing");
					snake.changeDirection(Direction(std::stoi(clientResponse)));
					snakeServer.sendSnakeData(data);
					serverResponse = snakeServer.sendSnakeData(data);
				}
				
				//std::cout << "size "<<tabledata.GetCachedSize() << std::endl;
				std::cout << "Server is running ..." << std::endl;
				//std::cout << "Server response : " << serverResponse << std::endl;
				//std::cout << "Client response : " << clientResponse << std::endl;
				serverResponse = snakeServer.sendSnakeData(data);



			}

		}catch(std::exception& e) {
			std::cout << "Exception: " << e.what() << "\n";
		}

	
	
		
	
	return 0;
}

