#include "table.h"

table::table(int w,int h) {
	width = w;
	height = h;
}
int table::left() {
	return 0-width/2;
}
int table::top() {
	return 0-height/2;
}
int table::bottom() {
	return height / 2;
}
int table::right() {
	return width / 2;
}