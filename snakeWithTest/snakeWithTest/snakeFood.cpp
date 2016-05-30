#include "snakeFood.h"

snakeFood::snakeFood() {
	srand(time(NULL));
}

boost::property_tree::ptree snakeFood::getData() {
	boost::property_tree::ptree data;
	data.put("x", foodPosition.x);
	data.put("y", foodPosition.y);
	return data;
}

void snakeFood::randomize(int tableWidth,int tableHeight){
	foodPosition.x = rand() % tableWidth;
	foodPosition.y = rand() % tableHeight;
}