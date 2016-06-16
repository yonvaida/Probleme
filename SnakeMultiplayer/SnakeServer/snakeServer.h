#pragma once
#include <string.h>
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
std::string sendSnakeData(boost::asio::ip::tcp::socket &socket, boost::property_tree::ptree data);
std::string readSnakeMove(boost::asio::ip::tcp::socket &socket);