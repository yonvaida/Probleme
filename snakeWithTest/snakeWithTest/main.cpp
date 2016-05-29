#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "snake.h"
#include <qapplication.h>
#include <snakeGUI.h>


int main(int argc, char *argv[])
{
	int result = Catch::Session().run(argc, argv);
	snakeGUI game;
	game.startGUI(argc, argv);
	game.addRectangle(10, 10);



	return 0;


}