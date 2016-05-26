#include "snakeGUI.h"


int snakeGUI(int argc, char *argv[]){

	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	std::unique_ptr<QGraphicsRectItem> rectangle(new QGraphicsRectItem(0, 0, 5, 5));
	scene->addItem(rectangle.get());
	view->setFixedSize(600, 600);
	view->show();


	return a.exec();
}