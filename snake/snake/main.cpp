#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include <qscopedpointer.h>
#include "snakeHead.h"
#include <QTimer>
#include <qstring.h>
#include <memory>
#include <qdebug.h>
#include <snakeFood.h>
#include <vector>
#include <iostream>
#include "main.h"
#include "snake.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsRectItem> layout(new QGraphicsRectItem());
	layout.get()->setRect(-200, -200, 400, 400);
	scene->addItem(layout.get());
	snakeRect *snakeHead = new snakeRect;
	//std::vector<QPoint> snake;
	//snake.push_back(snakeHead->pos());
	scene->addItem(snakeHead);
	snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeHead->setFocus();
	randomRect * snakeFood = new randomRect;
	scene->addItem(snakeFood);
	QTimer * timer = new QTimer();
	QObject::connect(timer, &QTimer::timeout, [=]() {
		snakeHead->move();
		int temp=1;
		//snake->at(0) = snakeHead->pos();
		if (snakeHead->pos().x() == snakeFood->rect().left()&&
			snakeHead->pos().y() == snakeFood->rect().top()) {
			//std::cout << snakeBody->elongate(snakeHead) << std::endl;
			//snake.push_back(snakeHead->pos());
			std::cout << "intersect" << std::endl;
		}
		else {
			qDebug("diferent");
		}
	});
	timer->start(500);
	std::shared_ptr<QGraphicsView> view (new QGraphicsView(scene.get()));
	view.get()->setFixedSize(500, 500);
	view.get()->show();
	return a.exec();
}
