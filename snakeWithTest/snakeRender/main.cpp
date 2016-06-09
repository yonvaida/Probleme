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
QPixmap* pixmap = new QPixmap(data.get<int>("table.width")*10, data.get<int>("table.height") * 10);
QPainter * painter = new QPainter(pixmap);
painter->HighQualityAntialiasing;
painter->setBrush(Qt::cyan);
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

std::unique_ptr<QTimer> timer(new QTimer());
QObject::connect(timer.get(), &QTimer::timeout, [&]() {
	snakefood.getData(data);
	foodpoint.x = data.get<int>("snakefood.x");
	foodpoint.y = data.get<int>("snakefood.y");
	snake.setFoodPoint(foodpoint);
	//painter->eraseRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10);
	painter->fillRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10, Qt::lightGray);
	snake.changeDirection(l->direction);
	snake.getData(data);
	//painter->drawPixmap(0,0,250,250,QPixmap("background.jpg"));
	painter->drawPixmap(data.get<int>("snakefood.x") * 10, data.get<int>("snakefood.y") * 10, 10, 10,QPixmap("strawberry.png"));
	//painter->drawEllipse(data.get<int>("snakebody.point0.x") * 10, data.get<int>("snakebody.point0.y") * 10, 10, 10);
	for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
		painter->fillRect(data.get<int>("snakebody.point"+std::to_string(i)+".x") * 10, data.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10,10,10,Qt::Dense2Pattern);
	}
	if (snake.findFood(foodpoint)) snakefood.randomize(50, 50);
	if (snake.collision() || !snake.onTable(board)) {
		QFont font;
		font.setPixelSize(50);
		font.setBold(true);
		painter->setFont(font);	
		painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "GAME OVER");
		timer->stop();
	}
	l->setPixmap(*pixmap);
});
timer->start(100);
l->setGeometry(300, 300, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10);
l->show();
	return a.exec();
}
