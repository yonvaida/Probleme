#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "snake.h"
#include "snakeGUI.h"


int main(int argc, char *argv[])
{
	int result = Catch::Session().run(argc, argv);
	
	snakeGUI(argc,argv);


}