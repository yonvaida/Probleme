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
#include "table.h"
#include "main.h"
#include "snakeServer.h"




int main()
{
	for (;;) {
		try {

			
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