#define CATCH_CONFIG_RUNNER
#include "main.h"
#include "catch.hpp"
#include "snake.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>


int main(int argc, char *argv[])
{
	int result = Catch::Session().run(argc, argv);
	boost::property_tree::ptree dataStoreVariable;
	
	return result;

}