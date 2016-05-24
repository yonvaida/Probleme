#include "snake_v2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	snake_v2 w;
	w.show();
	return a.exec();
}
