#pragma once
#include "boost\asio.hpp"
#include <boost\property_tree\ptree.hpp>
#include "flatbuffer\snakedata_generated.h"
#include "serialization.h"
#include <iostream>
#include <memory>
#include "snakeServer.h"
#include "snakeGame.h"
#include <boost\date_time\posix_time\posix_time.hpp>
/*
class TCPserver {
public:
	TCPserver(boost::asio::io_service &ioService, snakeServer &snakeGamesServer);
	void asyncConnection(snakeServer &snakeGamesServer, boost::asio::io_service &ioService);
private:
	boost::system::error_code error;
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::acceptor acceptor;
	boost::asio::deadline_timer timer;
};


*/