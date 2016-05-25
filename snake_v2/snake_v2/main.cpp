#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include "snakeRect.h"
#include "qtimer.h"
#include <memory>
#include <qobject.h>
#include <vector>
#include <qpoint.h>
#include <QPointF>
#include <iostream>
#include <snakePoints.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	std::unique_ptr<QGraphicsRectItem> gridTable(new QGraphicsRectItem(-250, -250, 500, 500));
	std::shared_ptr<snakeRect> snakeHead(new snakeRect(0, 0, 5, 5));
	std::shared_ptr<snakeRect> snakeFood(new snakeRect(rand()%10*10, rand()%10*10, 5, 5));
	std::vector<std::shared_ptr<snakeRect>> snake ;

	//snakePoint snakeTemp;
	//snakeBody.push_back(snakeRect(0,0,5,5));
	snake.push_back(snakeHead);
	//snakeTemp.setPoint();
	scene->addItem(gridTable.get());
	scene->addItem(snakeHead.get());
	scene->addItem(snakeFood.get());
	snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeHead->setFocus();
	
	std::unique_ptr<QTimer> timer(new QTimer);
	QObject::connect(timer.get(), &QTimer::timeout, [&] (){
		
	snakeHead->move();
	//snake[0].setPoint(snakeHead.get()->pos().toPoint().x(), snakeHead.get()->pos().toPoint().y());
	std::cout << snake[0].get()->pos().x() << std::endl;
	if (snakeHead.get()->pos().x() == snakeFood.get()->rect().left()&& snakeHead.get()->pos().y() == snakeFood.get()->rect().top()) {
		std::cout << "dddddddddd" << std::endl;
		std::shared_ptr<snakeRect> newSnakeRect(new snakeRect(0, 0, 5, 5));
		snakeFood->setPos(rand()%10*10,rand()%10*10);
		std::cout << "Snake food position x= " << snakeFood.get()->rect().left() << " -> y= " << snakeFood.get()->rect().top() << std::endl;
		snake.push_back(newSnakeRect);
		scene->addItem(newSnakeRect.get());
	}
	std::cout << "Snake food position x= " << snakeFood.get()->rect().left() <<" -> y= "<< snakeFood.get()->rect().top() << std::endl;
	});
	timer->start(1000);

	view->setFixedSize(600, 600);
	view->show();
	return a.exec();
}
