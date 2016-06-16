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

	table table(100, 100);
	snakeFood snakefood;
	Snake snake;
	point head;
	head.x = 0;
	head.y = 0;
	snake.elongate(head, Direction::right);

	
	boost::property_tree::ptree data;
	

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1200));
	std::vector<char> buf(2054);
	std::string serverResponse;
	std::string clientResponse;
	
	//acceptor.accept(socket);

	for (;;) {
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);
		snake.move();
		snakefood.randomize(100, 100);
		table.getData(data);
		snake.getData(data);
		system("cls");
		std::cout << "Server is running ..." << std::endl;
		std::cout <<"Server : " <<serverResponse << std::endl;
		std::cout <<"Client : "<< clientResponse << std::endl;
		
		//clientResponse = readSnakeMove(socket);

		serverResponse=sendSnakeData(socket,data);

	}


	return 0;
}

