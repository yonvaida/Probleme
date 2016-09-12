// sort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <iostream>




int main()
{
	int n = 63894916;
	std::cout << n << std::endl;
	int max = 0;
	int maxCount = 0;
	while (n > 0) {
		if (n % 10 > max) { 
			max = n % 10;
			maxCount = 0;
		}
		if (n % 10 == max)maxCount++;
		n = n / 10;
	}
	std::cout << n << std::endl;
	std::cout << "Max figure: " << max << std::endl;
	std::cout << "Nr of count: " << maxCount << std::endl;
    return 0;
}

