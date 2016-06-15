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
QPixmap* pixmap = new QPixmap(data.get<int>("table.width")*10+50, data.get<int>("table.height") * 10);
QPainter * painter = new QPainter(pixmap);
QPainter * gameResults = new QPainter(pixmap);
painter->HighQualityAntialiasing;
painter->setBrush(Qt::cyan);
Snake snake;
snakeFood snakefood;
point snakehead;
point foodpoint;
snakehead.x = 0;
snakehead.y = 0;
snake.elongate(snakehead, Direction::right);
snake.getData(data);
snakefood.randomize(50, 50);
int score=0;
int speed = 200;
std::unique_ptr<QTimer> timer(new QTimer());
QObject::connect(timer.get(), &QTimer::timeout, [&]() {
	snakefood.getData(data);
	foodpoint.x = data.get<int>("snakefood.x");
	foodpoint.y = data.get<int>("snakefood.y");
	snake.setFoodPoint(foodpoint);
	painter->fillRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10,Qt::gray);
	snake.changeDirection(l->direction);
	snake.getData(data);
	painter->drawPixmap(data.get<int>("snakefood.x") * 10, data.get<int>("snakefood.y") * 10, 10, 10,QPixmap("strawberry.png"));
	//gameResults->drawText(20, 20, "5555");
	for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
		painter->fillRect(data.get<int>("snakebody.point"+std::to_string(i)+".x") * 10, data.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10,10,10,Qt::Dense2Pattern);
	}
	painter->fillRect(data.get<int>("table.width") * 10, 0,50, data.get<int>("table.height") * 10,Qt::lightGray);
	painter->drawText(data.get<int>("table.width") * 10+5, 10, "SCORE:");
	painter->drawText(data.get<int>("table.width") * 10+20, 10+20, QString::number(score));
	if (snake.findFood(foodpoint)) { 
		score++;
		snakefood.randomize(50, 50);
	};
	if (snake.collision() || !snake.onTable(board)) {
		QFont font;
		font.setPixelSize(50);
		font.setBold(true);
		painter->setFont(font);	
		painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "GAME OVER");
		painter->drawText(data.get<int>("table.width") * 2+60, data.get<int>("table.height") * 2+50, "SCORE:");
		painter->drawText(data.get<int>("table.width") * 2+130, data.get<int>("table.height") * 2+100, QString::number(score));
		timer->stop();
	}
	l->setPixmap(*pixmap);
	if(speed>10) speed = 500 - (score*2);
	timer->setInterval(speed);
});
timer->start(speed);
l->setGeometry(300, 300, data.get<int>("table.width") * 10+50, data.get<int>("table.height") * 10);
l->show();
	return a.exec();
}
