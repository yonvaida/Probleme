#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

std::string ReversedString(std::string sentence,int first,int last)
{
	if (first < last) {
		char temp;
		temp = sentence[first];
		sentence[first] = sentence[last];
		sentence[last] = temp;

		sentence = ReversedString(sentence, first + 1, last - 1);
	}
	return sentence;
}

SCENARIO("Inverse string") {
	GIVEN("input string") {
		std::string stringVar = "ionut are mere";
		WHEN("inversing string") {
			THEN("result string"){
				CHECK(ReversedString(stringVar, 0, 13) == "erem era tunoi");
			}
		}
	}
}