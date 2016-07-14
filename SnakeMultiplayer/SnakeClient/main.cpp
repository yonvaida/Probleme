#include "boost\asio.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <boost\property_tree\ptree.hpp>
#include <stdlib.h>
#include <QLabel>
#include <QPicture>
#include <QPainter>
#include <qapplication.h>
#include "QtCore\qobject.h"
#include <qtimer.h>
#include <memory>
#include <qdebug.h>
#include "snakeclient.h"
#include "qabstracteventdispatcher.h"
#include "snakeclientGUI.h"
#include "deserialization.h"

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	std::unique_ptr<label> l(new label);
	std::unique_ptr<QPixmap> pixmap(new QPixmap(550, 500));
	std::unique_ptr<QPainter> painter(new QPainter(pixmap.get()));
	boost::property_tree::ptree data;
	l->setGeometry(300, 300, 50 * 11, 50 * 10);

	std::unique_ptr<QTimer> timer(new QTimer());
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		try {
			clientNetwork network("10.60.17.19", "32560");
			std::string sentmove;
			sentmove = moveSnake(l->direction);
			if(l->direction==Direction::newGame)l->direction = Direction::right;
			if (!network.error) {
				network.send(sentmove);
				data = network.read();
			}
			if (data.get<std::string>("game_status") == "GAME OVER") {
				QFont font;
				font.setPixelSize(50);
				font.setBold(true);
				painter->setFont(font);
				painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "GAME OVER");
				painter->drawText(data.get<int>("table.width") * 2 + 60, data.get<int>("table.height") * 2 + 50, "SCORE:");
				painter->drawText(data.get<int>("table.width") * 2 + 130, data.get<int>("table.height") * 2 + 100, QString::number(data.get<int>("game_score")));
				painter->drawText(data.get<int>("table.width") * 2 , data.get<int>("table.height") * 2 + 150, "F5 - New Game");
			}
			else {
				QFont font;
				font.setPixelSize(10);
				font.setBold(true);
				painter->setFont(font);
				painter->fillRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10, Qt::gray);
				painter->drawPixmap(data.get<int>("snakefood.x") * 10, data.get<int>("snakefood.y") * 10, 10, 10, QPixmap("strawberry.png"));
				painter->fillRect(data.get<int>("table.width") * 10, 0, 50, data.get<int>("table.height") * 10, Qt::darkGray);
				painter->drawText(data.get<int>("table.width") * 10 + 5, 10, "SCORE:");
				painter->drawText(data.get<int>("table.width") * 10 + 20, 10 + 20, QString::number(data.get<int>("game_score")));

				for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
					painter->fillRect(data.get<int>("snakebody.point" + std::to_string(i) + ".x") * 10, data.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10, 10, 10, Qt::Dense2Pattern);
				};
			}
			l->setPixmap(*pixmap);
		}
		catch (std::exception &ec) {
			std::cout << ec.what() << std::endl;
			painter->fillRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10, Qt::gray);
			painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "No Connection");
			l->setPixmap(*pixmap);
		}
	}			);
	timer->start(100);
	//l->setPixmap(*pixmap);
	
	l->show();
	return a.exec();
}