
#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
using namespace std;

int Fibonacci(int k) {
	int fibonacciVar = 0;
	if (k == 1) return 0;
	if (k == 2)return 1;
	fibonacciVar = Fibonacci(k-1)+Fibonacci(k-2);
	return fibonacciVar;
}

SCENARIO("Pascal triangle") {
	GIVEN("Number of lines") {
		WHEN("triangle 0") {
			THEN("result is ok") {
				CHECK(Fibonacci(7)== 8);
			}
		}
	}
}



