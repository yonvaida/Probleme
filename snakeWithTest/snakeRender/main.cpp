#include "snakerender.h"
#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <memory>
#include <qtimer.h>
#include <qobject.h>
#include "snakeWithTest\table.h"
#include "snakeWithTest\snake.h"
#include "snakeWithTest\snakeFood.h"

int main(int argc, char *argv[])
{
	table board(500,500);
	Snake snake;
	snakeFood snakefood;
	point snakehead;
	snakehead.x = 10;
	snakehead.y = 10;
	snake.elongate(snakehead, Direction::right);
	QApplication a(argc, argv);
	std::unique_ptr<boardGui> snakeBoardGui(new boardGui());
	std::unique_ptr<QGraphicsRectItem> snakeFoodGui(new QGraphicsRectItem());
	QGraphicsScene * scene=new QGraphicsScene();
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene));
	std::unique_ptr<QGraphicsRectItem> snakeGUI(new QGraphicsRectItem());
	snakeBoardGui->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeBoardGui->setFocus();
	boost::property_tree::ptree data;
	board.getData(data);
	snake.getData(data);
	snakefood.randomize(500,500);
	snakefood.getData(data);
	view->setFixedSize(data.get<int>("table.width") + 10, data.get<int>("table.height") + 10);
	snakeGUI->setRect(data.get<int>("snakebody.point0.x")*5, data.get<int>("snakebody.point0.y")*5, 5, 5);
	snakeBoardGui->setRect(0, 0, data.get<int>("table.width"),data.get<int>("table.height"));
	snakeFoodGui ->setRect(data.get<int>("snakefood.x") * 5, data.get<int>("snakefood.y") * 5, 5, 5);
	scene->addItem(snakeFoodGui.get());
	scene->addItem(snakeBoardGui.get());
	scene->addItem(snakeGUI.get());
	std::unique_ptr<QTimer> timer(new QTimer());
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		
		snake.getData(data);
		snakeGUI->setPos(data.get<int>("snakebody.point0.x") * 5, data.get<int>("snakebody.point0.y") * 5);
		
		//std::cout << snakeBoardGui->direction << std::endl;
		
		snake.changeDirection(snakeBoardGui->direction);
	});
	timer->start(1000);


	view->show();
	return a.exec();
}
