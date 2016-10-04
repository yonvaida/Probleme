#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "avlTree.h"




int main(int argc, char *argv[])
{

	int result = Catch::Session().run(argc, argv);
	

	return result;

}