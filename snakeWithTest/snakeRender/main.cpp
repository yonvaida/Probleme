#include "snakerender.h"
#include <QtWidgets/QApplication>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <QGraphicsRectItem>
#include <memory>
#include <qtimer.h>
#include <qobject.h>
#include <qvector.h>
#include <string>
#include "snakeWithTest\table.h"
#include "snakeWithTest\snake.h"
#include "snakeWithTest\snakeFood.h"
#include <QLabel>
#include <QPicture>
#include <QPainter>


int main(int argc, char *argv[])
{	QApplication a(argc, argv);
boost::property_tree::ptree data;
table board(50, 50);
board.getData(data);
label* l=new label;
QPixmap* pixmap = new QPixmap(data.get<int>("table.width")*5, data.get<int>("table.height") * 5);
QPainter * painter = new QPainter(pixmap);
	painter->setPen(*(new QColor(255, 34, 255, 255)));
//painter->drawRect(15, 15, 100, 100);


Snake snake;
snakeFood snakefood;
point snakehead;
point foodpoint;
snakehead.x = 0;
snakehead.y = 0;
snake.elongate(snakehead, Direction::right);
snake.getData(data);
snakefood.randomize(50, 50);

int i = 1;
std::unique_ptr<QTimer> timer(new QTimer());
QObject::connect(timer.get(), &QTimer::timeout, [&]() {
	snakefood.getData(data);
	foodpoint.x = data.get<int>("snakefood.x");
	foodpoint.y = data.get<int>("snakefood.y");
	snake.setFoodPoint(foodpoint);
	painter->eraseRect(0, 0, data.get<int>("table.width") * 5, data.get<int>("table.height") * 5);
	snake.changeDirection(l->direction);
	snake.getData(data);
	painter->drawRect(data.get<int>("snakefood.x") * 5, data.get<int>("snakefood.y") * 5, 5, 5);
	for (int temp = 0; temp < data.get<int>("snakebody.length"); temp++) {
		painter->drawRect(data.get<int>("snakebody.point"+std::to_string(temp)+".x") * 5, data.get<int>("snakebody.point" + std::to_string(temp) + ".y") * 5, 5, 5);
	}
	if (snake.findFood(foodpoint)) {
		snakefood.randomize(50, 50);
	}
	l->setPixmap(*pixmap);
});
timer->start(200);
l->setGeometry(300, 300, data.get<int>("table.width") * 5, data.get<int>("table.height") * 5);
l->show();



	return a.exec();
}
