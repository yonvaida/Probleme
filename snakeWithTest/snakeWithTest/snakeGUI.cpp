#include "snakeGUI.h"

int snakeGUI::startGUI(int argc, char *argv[]) {
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	
	
	view->show();
	return a.exec();
}

void snakeGUI::addRectangle(int x, int y) {
	std::unique_ptr<QGraphicsRectItem> rect(new QGraphicsRectItem(x, y, 10, 10));
	scene->addItem(rect.get());
}