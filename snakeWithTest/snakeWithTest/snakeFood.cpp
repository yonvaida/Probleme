#include "snakeFood.h"

snakeFood::snakeFood() {
	srand(time(NULL));
}

boost::property_tree::ptree snakeFood::getData() {
	boost::property_tree::ptree dataStoreVariable;
	dataStoreVariable.put("snakefood.x", "foodPosition.x");
	dataStoreVariable.put("snakefood.y", "foodPosition.y");
	return dataStoreVariable;
}

void snakeFood::randomize(int tableWidth,int tableHeight){
	foodPosition.x = rand() % 100;
	foodPosition.y = rand() % 100;
}