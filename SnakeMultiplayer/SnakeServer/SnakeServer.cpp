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

int main()
{
	
	table table(100, 100);
	snakeFood snakefood;
	Snake snake;
	point head;
	head.x = 0;
	head.y = 0;
	snake.elongate(head, Direction::right);

	std::ostringstream result;
	boost::property_tree::ptree data;
	//std::cout << result.str() << std::endl;
	
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),1200));
	//std::string buffer_content="Server sent info";
	

	for (;;) {
		std::vector<char> buf(2054);
		snake.move();
		result.str("");
		snakefood.randomize(100, 100);
		//data.erase("snakebody");
		table.getData(data);
		snake.getData(data);
		//std::string temp = data.get<std::string>("snakebody.point0.x");
		boost::property_tree::write_json(result, data);
		system("cls");
		std::cout << "Server is running ..." << std::endl;
		std::cout << result.str() << std::endl;
		std::cout << "Buffer data" << buf.data() << std::endl;
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);
		boost::asio::write(socket, boost::asio::buffer(result.str()), boost::asio::transfer_all());
		
	}


    return 0;
}

