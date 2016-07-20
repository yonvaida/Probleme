#define CATCH_CONFIG_RUNNER
#pragma once
#include "boost\asio.hpp"
#include "catch.hpp"
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
#include "tcpServer.h"


int main(int argc, char *argv[])
{
	//int result = Catch::Session().run(argc, argv);
		try {
			//snakeServer snakeGamesServer;
		boost::asio::io_service ioService;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 32560);
		snakeServer gameServer(ioService,endpoint );
			//	TCPserver TCPsnakeServer(ioService, snakeGamesServer);
		ioService.run();	
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what()<<"   --error" << "\n";
		}
	
	return 0;
}

