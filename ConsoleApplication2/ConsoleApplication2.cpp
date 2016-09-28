// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"

class figure {
public:
	 void Draw() {
		std::cout << "Figure draw" << std::endl;
	}
};
class snake :public figure {
public:
	void Draw() {
		std::cout << "Snake draw" << std::endl;
		redraw();
	}
	void redraw() {
		std::cout << "Snake Redraw" << std::endl;
	}
};

int main()
{
	snake snake1;

	snake1.figure::Draw();

    return 0;
}

