#include "snakeFood.h"

snakeFood::snakeFood() {
	srand(time(NULL));
	foodPosition.x = rand() % 100;
	foodPosition.y = rand() % 100;
}

void snakeFood::getData(boost::property_tree::ptree &data) {
	data.put("snakefood.x", foodPosition.x);
	data.put("snakefood.y", foodPosition.y);
	
}

void snakeFood::randomize(int tableWidth,int tableHeight){
	foodPosition.x = rand() % 100;
	foodPosition.y = rand() % 100;
}