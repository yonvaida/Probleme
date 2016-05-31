#define CATCH_CONFIG_RUNNER
#include "main.h"
#include "catch.hpp"
#include "snake.h"
#include "snakeFood.h"
#include <boost\property_tree\ptree.hpp>
#include <qtimer.h>
#include <qobject.h>
#include <qapplication.h>


int main(int argc, char *argv[])
{
	
	int result = Catch::Session().run(argc, argv);
	
	


	
	return result;

}