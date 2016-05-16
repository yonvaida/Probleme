
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

class Product {
public:
	Product(int prodPrice, std::string prodName) {
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
void main()
{
	std::vector<Product> prod;
	prod.clear();
	prod.push_back({ 10,"produs 1" });
	prod.push_back({ 23,"produs 2" });
	prod.push_back({ 32,"produs 3" });
	prod.push_back({ 78,"produs 4" });
	prod.push_back({ 67,"produs 5" });

	std::vector<Product>::iterator prodIter;
	for (prodIter = prod.begin(); prodIter != prod.end(); prodIter++) {
		std::cout << (*prodIter).getName()<<" ---- "<<(*prodIter).getPrice() << std::endl;
	}
}

