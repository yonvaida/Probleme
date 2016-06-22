#pragma once
#include "boost\property_tree\ptree.hpp"
#include "flatbuffer\snakedata_generated.h"


enum class Direction { left, right, up, down,stay };
struct point {
	int x;
	int y;
};

