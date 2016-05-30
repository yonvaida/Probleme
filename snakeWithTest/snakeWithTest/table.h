#pragma once
#include "main.h"

class table {
public:
	table(int w,int h);
	void resizeTable(int scale);
		
private:
	int width;
	int height;
};