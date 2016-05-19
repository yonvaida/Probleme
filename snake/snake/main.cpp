#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include "snake.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGraphicsScene * scene = new QGraphicsScene();
	snakeRect * snake = new snakeRect;
	scene->addItem(snake);
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();
	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(500, 500);
	view->show();
	return a.exec();
}
