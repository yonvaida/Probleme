#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include "snakeHead.h"
#include "qtimer.h"
#include <memory>
#include <qobject.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	std::unique_ptr<QGraphicsRectItem> gridTable(new QGraphicsRectItem(-250, -250, 500, 500));
	std::shared_ptr<snakeHeadRect> snakeHead(new snakeHeadRect(0, 0, 5, 5));
	scene->addItem(gridTable.get());
	scene->addItem(snakeHead.get());
	snakeHead->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeHead->setFocus();
	std::unique_ptr<QTimer> timer(new QTimer);
	QObject::connect(timer.get(), &QTimer::timeout, [=] (){
	
	});
	timer->start(1000);

	view->setFixedSize(600, 600);
	view->show();
	return a.exec();
}
