#pragma once
#include "boost\asio.hpp"
class player {
public:
	player(std::shared_ptr<boost::asio::ip::tcp::socket> playerSocket);
	std::shared_ptr<boost::asio::ip::tcp::socket> socket;
};