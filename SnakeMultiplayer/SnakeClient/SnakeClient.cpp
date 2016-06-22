#include <boost\array.hpp>
#include "snakeclient.h"



void convertToPtree(std::string bufferValue,std::size_t length, boost::property_tree::ptree &data) {
	std::stringstream temp;
	temp.str(bufferValue.substr(0,length));
	boost::property_tree::read_json(temp, data);
};