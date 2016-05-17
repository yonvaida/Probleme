#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

class Password {
public:
	Password(std::string pass) {
		passwordValue = pass;
		
	
	};
	
		bool PasswordChecked() {
			int countLowerCase = 0, countUpCase = 0, countNumbers = 0, countSymbols = 0;
			for (int i = 0; i < passwordValue.length(); i++) {
				if(unacceptedChar.find(passwordValue[i]) != std::string::npos)return false;
				countLowerCase += islower(passwordValue[i]) ? 1 : 0;
				countUpCase += isupper(passwordValue[i]) ? 1 : 0;
				countNumbers += isdigit(passwordValue[i]) ? 1 : 0;
				countSymbols += isalnum(passwordValue[i]) ? 0 : 1;
		}
			return (lowerCase<=countLowerCase && upCase<=countUpCase && numbers<=countNumbers&& symbols <= countSymbols)?true:false;
	}
private:
	std::string passwordValue;
	int lowerCase=2;
	int upCase=1;
	int numbers=1;
	int symbols=1;
	std::string unacceptedChar = "~{}[]()/\',;.<>";
};

SCENARIO("Check if password is valid") {
	GIVEN("Give password, number of lowercase,number of uppercase,number of numbers and number of symbols") {
		Password pass("Ionut*23");
		WHEN("password given") {
			THEN("check password") {
				CHECK(pass.PasswordChecked() == true);
			}
		}
	}
}