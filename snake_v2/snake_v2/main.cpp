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
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	std::unique_ptr<QGraphicsRectItem> gridTable(new QGraphicsRectItem(-250, -250, 500, 500));
	std::shared_ptr<snakeRect> snakeHead(new snakeRect(0, 0, 5, 5));
	std::vector<QPointF> snakeBody;
	snakeBody.push_back(snakeHead.get->pos());
	scene->addItem(gridTable.get());
	scene->addItem(snakeHead.get());
	snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeHead->setFocus();
	
	std::unique_ptr<QTimer> timer(new QTimer);
	QObject::connect(timer.get(), &QTimer::timeout, [=] (){
		//snakeBody[0].setPos(snakeHead.get()->pos().x(), snakeHead.get()->pos().y());
		snakeHead->move();
		
		auto temp = snakeHead.get()->pos();
		
		
		//snakeBody->add(temp);

		std::cout << temp.x()<<"----"<< temp.y() << std::endl;

	});
	timer->start(1000);

	view->setFixedSize(600, 600);
	view->show();
	return a.exec();
}
