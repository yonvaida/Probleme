// catch_example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

double factorial(int a) {
	if (a == 0 || a == 1) return 1;
	double factorialTemp = a*factorial(a - 1);
	return factorialTemp;

}

	SCENARIO("factorial Test","[factorial]"){
		GIVEN("Factorial values") {
			int a = 0;
			int b = 1;
			int c = 10;
			WHEN("factorial 0") {
				double factorialTemp=factorial(a);
				THEN("calcul factorial corect"){
					REQUIRE(factorialTemp == 1);
				}
			}
			WHEN("factorial 1") {
				double factorialTemp = factorial(b);
				THEN("calcul factorial corect") {
					REQUIRE(factorialTemp == 1);
				}
			}
			WHEN("factorial 10") {
				double factorialTemp = factorial(c);
				THEN("calcul factorial corect") {
					REQUIRE(factorialTemp == 3628800);
				}
			}
	}

}

