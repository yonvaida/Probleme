// SnakeServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "boost\asio.hpp"
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),1200));
	
	for (;;) {
		int i = rand();
		std::string message = std::to_string(i);
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);
		boost::asio::write(socket, boost::asio::buffer(message), boost::asio::transfer_all());
	}


    return 0;
}

