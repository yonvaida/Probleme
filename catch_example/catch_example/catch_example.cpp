// catch_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

	SCENARIO("factorial Test","[factorial]"){
		GIVEN("Factorial values") {
			WHEN("factorial 0") {
				THEN("calcul factorial corect"){
					REQUIRE(factorial(0) == 1);
				}
			}
			WHEN("factorial 1") {
				THEN("calcul factorial corect") {
					REQUIRE(factorial(1) == 1);
				}
			}
			WHEN("factorial 10") {
				THEN("calcul factorial corect") {
					REQUIRE(factorial(10) == 3628800);
				}
			}
	}
	}

