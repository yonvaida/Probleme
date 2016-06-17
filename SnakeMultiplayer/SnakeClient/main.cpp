// SnakeClient.cpp : Defines the entry point for the console application.
//


#include "boost\asio.hpp"
#include <iostream>
#include <vector>
#include <string.h>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\json_parser.hpp>
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
//#include "qabstracteventdispatcher.h"
#include <QTcpSocket>





int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	//QByteArray data;
	std::string temp;
	std::istringstream readvar;
	boost::property_tree::ptree data;
	label* l = new label;
	QPixmap* pixmap = new QPixmap(500,500);
	QPainter * painter = new QPainter(pixmap);
	QTcpSocket* socket = new QTcpSocket();
	std::unique_ptr<QTimer> timer(new QTimer());
	QByteArray moveSnake;
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		socket->connectToHost("localhost", 1200);
		if (!socket->waitForConnected(3000))
		{
			qDebug() << "Error: " << socket->errorString();
		}
		else {
			system("cls");
			std::cout << "Connection is ok" << std::endl;

		}
		if (socket->waitForReadyRead(3000)) {
			temp = socket->readAll();
			readvar.str(temp);
			boost::property_tree::read_json(readvar, data);  
			switch (l->direction) {
			case Direction::left:
				moveSnake = "left";
				break;
			case Direction::right:
				moveSnake = "right";
				break;
			case Direction::up:
				moveSnake = "up";
				break;
			case Direction::down:
				moveSnake = "down";
				break;
			}





			socket->write(moveSnake);
		}
		painter->fillRect(0, 0, 500, 500, Qt::lightGray);
		for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
			painter->fillRect(data.get<int>("snakebody.point" + std::to_string(i) + ".x") * 10, data.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10, 10, 10, Qt::Dense2Pattern);
		};
		l->setPixmap(*pixmap);
	});
	timer->start(100);
	
	
	//std::cout << data.at(0) << std::endl;
	//painter->HighQualityAntialiasing;
	//painter->setBrush(Qt::cyan);
	/*boost::property_tree::ptree data;
	std::istringstream dataReceived;
	


	boost::asio::io_service io_service;
	//QApplication::setEventDispatcher(new QAbstractEventDispatcher(io_service));


	boost::asio::ip::tcp::resolver resolver(io_service);
	for (;;) {
		dataReceived.str("");
		boost::asio::ip::tcp::resolver::query query("localhost", "1200");
		boost::asio::ip::tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		boost::asio::ip::tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);
		std::vector<char> buf(2054);
		socket.read_some(boost::asio::buffer(buf));
		system("cls");
		dataReceived.str(buf.data());
		boost::property_tree::read_json(dataReceived, data);
		std::cout << data.get<int>("snakebody.point0.x") << std::endl;
		socket.write_some(boost::asio::buffer("merge"));

		//buf.erase(buf.begin(), buf.end());
		//painter->drawText(data.get<int>("table.width") * 2, data.get<int>("table.height") * 2, "GAME OVER");
		//l->show();
	}
	//painter->drawText(20, 20, "GAME OVER");
	//painter->fillRect(10, 10, 10, 10, Qt::darkCyan);*/
	l->setPixmap(*pixmap);
	l->setGeometry(300, 300, 50 * 10, 50 * 10);
	l->show();
	return a.exec();
}