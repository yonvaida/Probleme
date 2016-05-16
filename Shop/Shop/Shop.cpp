#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>



using namespace std;
class Product {
public:
	Product(int prodPrice,string prodName){
			price = prodPrice;
			name = prodName;
	}
	int getPrice() {
		return price;
	}
	string getName() {
		return name;
	}
private:
	int price;
	string name;

};

double Calculate(vector<Product> prod, string operation) {
	vector<Product>::iterator prodIter;
	int totalPrice = 0;
	int temp=0,i=0;
	int minPrice = prod[0].getPrice();
	int maxPrice = minPrice;
	double averagePrice = 0;
	for (prodIter = prod.begin(); prodIter != prod.end(); prodIter++) {
		totalPrice += (*prodIter).getPrice();
		minPrice = (minPrice > (*prodIter).getPrice()) ? (*prodIter).getPrice() : minPrice;
		if (maxPrice < (*prodIter).getPrice()) {
			maxPrice = (*prodIter).getPrice();
			temp = i;
				}
		i++;
	}	
	if (operation == "total") return totalPrice;
	if (operation == "min") return minPrice;
	if (operation == "average")return totalPrice / prod.size();
	prod.erase(prod.begin() + temp);
	for (int i = 0; i < prod.size(); i++) {
		cout << prod[i].getName() << endl;
	}
	if (operation == "remove") return prod.size();
	return 0;
}

SCENARIO("Products in cart") {
	GIVEN("Shoping cart") {
		vector<Product> prodTemp;
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


