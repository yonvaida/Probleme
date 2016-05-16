#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

class Password {
public:
	Password(std::string pass,int low,int up,int number,int symb) {
		passwordValue = pass;
		upCase = up;
		numbers = number;
		symbols = symb;
	
	};
	
		bool PasswordChecked() {
		for (int i = 0; i < passwordValue.length(); i++) {
			
		}
		if (lowerCase < 1) return true;
		else return false;
	}
private:
	std::string passwordValue;
	int lowerCase;
	int upCase;
	int numbers;
	int symbols;
};

SCENARIO("Check if password is valid") {
	GIVEN("Give password, number of lowercase,number of uppercase,number of numbers and number of symbols") {
		Password pass("ionut", 2, 1, 1, 0);
		WHEN("password given") {
			THEN("check password") {
				CHECK(pass.PasswordChecked() == true);
			}
		}
	}
}