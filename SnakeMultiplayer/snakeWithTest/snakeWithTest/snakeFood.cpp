#include "snakeFood.h"

snakeFood::snakeFood() {
	srand(time(NULL));
	foodPosition.x = rand() % 50;
	foodPosition.y = rand() % 50;
}

void snakeFood::getData(boost::property_tree::ptree &data) {
	data.put("snakefood.x", foodPosition.x);
	data.put("snakefood.y", foodPosition.y);
	
}

void snakeFood::randomize(int tableWidth,int tableHeight){
	foodPosition.x = rand() % tableWidth;
	foodPosition.y = rand() % tableHeight;
}