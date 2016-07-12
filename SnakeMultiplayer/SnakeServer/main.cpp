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

