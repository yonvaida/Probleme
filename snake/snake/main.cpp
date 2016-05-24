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
#include "snakeBody.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsRectItem> grid(new QGraphicsRectItem());
	std::shared_ptr<snakeRect> snakeHead(new snakeRect());
	std::shared_ptr<snakeBodyRect> snake(new snakeBodyRect());
	grid.get()->setRect(-240, -240, 480, 480);
	scene->addItem(grid.get());
	scene->addItem(snakeHead.get());
	snakeHead.get()->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeHead.get()->setFocus();
	randomRect * snakeFood = new randomRect;
	scene.get()->addItem(snakeFood);
	//std::vector<QPoint> snake;
	//snake.push_back(snakeHead->pos());
	std::cout << snakeHead.get()->pos().x()<< std::endl;
	std::vector<QGraphicsRectItem> snakeBody;

	QTimer * timer = new QTimer();
	QObject::connect(timer, &QTimer::timeout, [=]() {
		snakeHead.get()->move();
		//snake.get()->move();
		if (snakeHead.get()->pos().x() == snakeFood->rect().left()&&
			snakeHead.get()->pos().y() == snakeFood->rect().top()) {
			std::cout << "intersect" << std::endl;
			snake.get()->add(snakeBody,snakeHead.get());
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
