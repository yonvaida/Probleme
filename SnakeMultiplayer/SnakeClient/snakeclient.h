
//#include "snakeWithTest\main.h"
#include <iostream>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <string>

void convertToPtree(std::string bufferValue, std::size_t length, boost::property_tree::ptree &data);
