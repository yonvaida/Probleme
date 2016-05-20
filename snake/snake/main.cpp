#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include "snake.h"
#include <QTimer>
#include <memory>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QGraphicsScene * scene = new QGraphicsScene();
	//snakeRect * snake = new snakeRect;
	snakeRect *snake = new snakeRect;
	scene->addItem(snake);
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();
	randomRect * random = new randomRect;
	scene->addItem(random);
	QTimer * timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()),snake,SLOT(move()));
	timer->start(1000);
	QGraphicsView * view = new QGraphicsView(scene);
	view->setFixedSize(500, 500);
	view->show();
	return a.exec();
}
