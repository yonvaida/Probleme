// SnakeClient.cpp : Defines the entry point for the console application.
//


#include "boost\asio.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
#include <boost\array.hpp>
#include <stdlib.h>
#include <QLabel>
#include <QPicture>
#include <QPainter>
#include <qapplication.h>
#include <QtNetwork\qtcpsocket.h>
#include "QtCore\qobject.h"
#include <qtimer.h>
#include <memory>
#include <qdebug.h>
#include "snakeclient.h"
#include "qabstracteventdispatcher.h"
#include <QTcpSocket>
#include "snakeclientGUI.h"




int main(int argc, char * argv[])
{
	QApplication a(argc, argv);
	boost::asio::io_service ioService;
	boost::asio::ip::tcp::resolver resolver(ioService);
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::query query("127.0.0.1", "32560");
	endpoint = resolver.resolve(query);
	boost::system::error_code error;
	std::unique_ptr<label> l (new label);
	std::unique_ptr<QPixmap> pixmap (new QPixmap(500, 500));
	std::unique_ptr<QPainter> painter (new QPainter(pixmap.get()));
	//QPainter * gameResults = new QPainter(pixmap);
	boost::property_tree::ptree data;
	std::unique_ptr<QTimer> timer(new QTimer());
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		boost::array<char, 3000> buf;
		system("cls");
		boost::asio::ip::tcp::socket dataSocket(ioService);
		boost::asio::connect(dataSocket, endpoint);
		boost::array<char, 1> sentmove;
		sentmove.at(0)=	moveSnake(l->direction);
		dataSocket.write_some(boost::asio::buffer(sentmove));
		size_t length= dataSocket.read_some(boost::asio::buffer(buf),error);
		if (error == 0) {
			convertToPtree(buf.data(),length, data);
		}
		if (data.get<std::string>("game_status") == "GAME OVER") {
			QFont font;
			font.setPixelSize(50);
			font.setBold(true);
			painter->setFont(font);
			painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "GAME OVER");
			painter->drawText(data.get<int>("table.width") * 2 + 60, data.get<int>("table.height") * 2 + 50, "SCORE:");
			painter->drawText(data.get<int>("table.width") * 2 + 130, data.get<int>("table.height") * 2 + 100, QString::number(data.get<int>("game_score")));
			timer->stop();
		}
		else {
			painter->fillRect(0, 0, data.get<int>("table.width") * 10, data.get<int>("table.height") * 10, Qt::gray);
			painter->drawPixmap(data.get<int>("snakefood.x") * 10, data.get<int>("snakefood.y") * 10, 10, 10, QPixmap("strawberry.png"));
			painter->fillRect(data.get<int>("table.width") * 10, 0, 50, data.get<int>("table.height") * 10, Qt::darkCyan);
			painter->drawText(data.get<int>("table.width") * 10 + 5, 10, "SCORE:");
			painter->drawText(data.get<int>("table.width") * 10 + 20, 10 + 20, QString::number(data.get<int>("game_score")));
			for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
				painter->fillRect(data.get<int>("snakebody.point" + std::to_string(i) + ".x") * 10, data.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10, 10, 10, Qt::Dense2Pattern);
			};
		}
		l->setPixmap(*pixmap);
	});
	timer->start(100);
	l->setPixmap(*pixmap);
	l->setGeometry(300, 300, 50 * 11, 50 * 10);
	l->show();

	return a.exec();




}