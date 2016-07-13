#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
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
#include "tcpServer.h"


int main(int argc, char *argv[])
{
	int result = Catch::Session().run(argc, argv);
		try {
			snakeServer snakeGamesServer;
			boost::asio::io_service ioService;
				TCPserver TCPsnakeServer(ioService, snakeGamesServer);
				ioService.run();	
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what()<<"   --error" << "\n";
		}
	
	return 0;
}

