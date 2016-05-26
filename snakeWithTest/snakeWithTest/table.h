#pragma once
class table {
public:
	table(int w,int h);
	void resizeTable(int w, int h);
	int left();
	int top();
	int right();
	int bottom();
private:
	int width;
	int height;
};