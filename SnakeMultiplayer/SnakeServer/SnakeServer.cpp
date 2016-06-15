// SnakeServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "boost\asio.hpp"
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

int main()
{
	std::ostringstream result;
	boost::property_tree::ptree data;
	data.put("val1", "value 1");
	data.put("val2", "value 2");
	std::cout << data.get<std::string>("val1") << std::endl;
	boost::property_tree::write_json(result, data);
	//std::cout << result.str() << std::endl;
	
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),1200));
	//std::string buffer_content="Server sent info";
	

	for (;;) {
		system("cls");
		std::cout << "Server is running ..." << std::endl;
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);
		boost::asio::write(socket, boost::asio::buffer(result.str()), boost::asio::transfer_all());
	}


    return 0;
}

