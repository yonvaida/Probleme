// SnakeClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "boost\asio.hpp"
#include "boost\array.hpp"
#include <iostream>

int main()


{
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::resolver resolver(io_service);
	for (;;) {
	boost::asio::ip::tcp::resolver::query query("localhost","1200");
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::connect(socket,endpoint_iterator);
	boost::array<char, 128> buf;
	
		size_t len = socket.read_some(boost::asio::buffer(buf));
		
			std::cout << buf.data() << std::endl;
		
	}
	
	

	
	return 0;
}

