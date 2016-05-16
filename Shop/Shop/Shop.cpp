#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>


class Product {
public:
	Product(int prodPrice,std::string prodName){
			price = prodPrice;
			name = prodName;
	}
	int getPrice() {
		return price;
	}
	std::string getName() {
		return name;
	}
private:
	int price;
	std::string name;

};

double Calculate(std::vector<Product> prod, std::string operation) {
	std::vector<Product>::iterator prodIter;
	int totalPrice = 0, temp = 0, i = 0, minPrice = prod[0].getPrice(), maxPrice = prod[0].getPrice();
	double averagePrice = 0;
	for (prodIter = prod.begin(); prodIter != prod.end(); prodIter++) {
		totalPrice += (*prodIter).getPrice();
		minPrice = (minPrice > (*prodIter).getPrice()) ? (*prodIter).getPrice() : minPrice;
		maxPrice = (maxPrice < (*prodIter).getPrice()) ? (*prodIter).getPrice() : maxPrice;
		temp = (maxPrice < (*prodIter).getPrice()) ? i : temp;	
		i++;
	}	
	if (operation == "total") return totalPrice;
	if (operation == "min") return minPrice;
	if (operation == "average")return totalPrice / prod.size();
	prod.erase(prod.begin() + temp);
	for (int i = 0; i < prod.size(); i++) {
		std::cout << prod[i].getName() << std::endl;
	}
	if (operation == "remove") return prod.size();
	return 0;
}

SCENARIO("Products in cart") {
	GIVEN("Shoping cart") {
		std::vector<Product> prodTemp;
		prodTemp.push_back(Product{ 13, "Product 1" });
		prodTemp.push_back(Product{ 32, "Product 2" });
		prodTemp.push_back(Product{ 54, "Product 3" });
		prodTemp.push_back(Product{ 63, "Product 4" });
		prodTemp.push_back(Product{ 78, "Product 5" });
		WHEN("Shopping finished") {
			THEN("Calculate"){
				CHECK(Calculate(prodTemp,"total") == 240);
				CHECK(Calculate(prodTemp,"min") == 13);
				CHECK(Calculate(prodTemp,"remove") == 4);
				CHECK(Calculate(prodTemp,"average") == 48);
			}
			}
	}
}


