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

int Total(vector<Product> prod) {
	int totalPrice=0;
	for (int i=0; i<prod.size(); i++) {
		totalPrice += prod[i].getPrice();
	}	
	return totalPrice;	
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
				CHECK(Total(prodTemp) == 240);
			}
			}
	}
}


