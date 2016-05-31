#include "snakerender.h"
#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <memory>
//#include <boost\property_tree\ptree.hpp>
#include "snakeWithTest\table.h"

int main(int argc, char *argv[])
{
	table board(500,500);
	QApplication a(argc, argv);
	std::unique_ptr<QGraphicsRectItem> boardGui(new QGraphicsRectItem());
	std::unique_ptr<QGraphicsScene> scene(new QGraphicsScene());
	std::unique_ptr<QGraphicsView> view(new QGraphicsView(scene.get()));
	boost::property_tree::ptree data;
	board.getData(data);
	view->setFixedSize(data.get<int>("table.width") + 10, data.get<int>("table.height") + 10);
	boardGui->setRect(0, 0, data.get<int>("table.width"),data.get<int>("table.height"));
	
	scene->addItem(boardGui.get());




	view->show();
	return a.exec();
}
