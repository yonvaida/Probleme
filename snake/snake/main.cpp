#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include <qscopedpointer.h>
#include "snake.h"
#include <QTimer>
#include <qstring.h>
#include <memory>
#include <qdebug.h>
#include <snakeFood.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::shared_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::shared_ptr<QGraphicsRectItem> layout(new QGraphicsRectItem());
	layout.get()->setRect(-200, -200, 400, 400);
	scene->addItem(layout.get());
	snakeRect *snake = new snakeRect;
	scene->addItem(snake);
	snake->setFlag(QGraphicsItem::ItemIsFocusable);
	snake->setFocus();
	randomRect * random = new randomRect;
	scene->addItem(random);
	QTimer * timer = new QTimer();
	QObject::connect(timer, &QTimer::timeout, [=]() {
		if (snake->pos() == random->pos()) {
			qDebug("kkkkkk");	
		}
		else {
			qDebug("ccccccc");
		}
		snake->move();
	});
	timer->start(1000);
	std::shared_ptr<QGraphicsView> view (new QGraphicsView(scene.get()));
	view.get()->setFixedSize(500, 500);
	view.get()->show();
	return a.exec();
}
