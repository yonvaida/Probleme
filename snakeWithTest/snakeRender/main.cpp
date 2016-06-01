#include "snakerender.h"
#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <memory>
#include <qtimer.h>
#include <qobject.h>
#include <qvector.h>
#include "snakeWithTest\table.h"
#include "snakeWithTest\snake.h"
#include "snakeWithTest\snakeFood.h"

int main(int argc, char *argv[])
{
	table board(50,50);
	Snake snake;
	snakeFood snakefood;
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	snake.elongate(snakehead, Direction::right);
	QApplication a(argc, argv);
	std::unique_ptr<boardGui> snakeBoardGui(new boardGui());
	std::unique_ptr<QGraphicsRectItem> snakeFoodGui(new QGraphicsRectItem());
	QGraphicsScene * scene=new QGraphicsScene();
	std::shared_ptr<QGraphicsRectItem> snakeGUI(new QGraphicsRectItem());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene));
	//std::vector<std::unique_ptr<QGraphicsRectItem>> snakeBodyGUI;
	QVector<std::shared_ptr<QGraphicsRectItem>> snakeBodyGui;
	snakeBoardGui->setFlag(QGraphicsItem::ItemIsFocusable);
	snakeBoardGui->setFocus();
	boost::property_tree::ptree data;
	board.getData(data);
	snake.getData(data);
	snakefood.randomize(50,50);
	snakefood.getData(data);
	snakeGUI->setRect(data.get<int>("snakebody.point0.x") * 5, data.get<int>("snakebody.point0.y") * 5, 5, 5);
	//snakeBodyGui << new QGraphicsRectItem(data.get<int>("snakebody.point0.x") * 5, data.get<int>("snakebody.point0.y") * 5, 5, 5);
	snakeBodyGui << std::move(snakeGUI);
	view->setFixedSize(data.get<int>("table.width")*5 + 10, data.get<int>("table.height")*5 + 10);
	//snakeGUI->setRect(data.get<int>("snakebody.point0.x")*5, data.get<int>("snakebody.point0.y")*5, 5, 5);
	snakeBoardGui->setRect(0, 0, data.get<int>("table.width")*5,data.get<int>("table.height")*5);
	snakeFoodGui ->setRect(data.get<int>("snakefood.x") * 5, data.get<int>("snakefood.y") * 5, 5, 5);
	scene->addItem(snakeFoodGui.get());
	scene->addItem(snakeBoardGui.get());
	scene->addItem(snakeBodyGui.at(0).get());

	std::unique_ptr<QTimer> timer(new QTimer());
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		snake.changeDirection(snakeBoardGui->direction);
		snake.getData(data);
		snakeBodyGui.at(0).get()->setPos(data.get<int>("snakebody.point0.x") * 5, data.get<int>("snakebody.point0.y") * 5);
		//std::cout << snakeBoardGui->direction << std::endl;
		
	});
	timer->start(1000);


	view->show();
	return a.exec();
}
