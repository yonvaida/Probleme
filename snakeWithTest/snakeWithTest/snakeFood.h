#include "main.h"
#include <stdlib.h>
#include <time.h>


class snakeFood {

public:
	snakeFood();
	void randomize(int tableWidth, int tableHeight);
	//boost::property_tree::ptree getData();
private:
	point foodPosition;
};