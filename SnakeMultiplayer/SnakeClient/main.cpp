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
//#include <QLabel>
//#include <QPicture>
//#include <QPainter>
//#include <qapplication.h>
//#include <QtNetwork\qtcpsocket.h>
//#include "QtCore\qobject.h"
//#include <qtimer.h>
#include <memory>
//#include <qdebug.h>
//#include "snakeclient.h"
//#include "qabstracteventdispatcher.h"
//#include <QTcpSocket>
//#include "snakeclientGUI.h"
#include "deserialization.h"
#include <exception>

int main(int argc, char * argv[])
{
		try {
			std::vector<char> buf;
			buf.resize(3000);
			std::string connectionStatus = "initial";
			boost::asio::io_service ioService;
			int i = 0;
			boost::asio::ip::tcp::resolver::query query("192.168.1.66", "32560");
			boost::system::error_code error;
			boost::asio::ip::tcp::resolver resolver(ioService);
			boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);
			while (true) {
				boost::asio::ip::tcp::socket socket(ioService);
				socket.connect(*iterator, error);
				std::cout << error.message() << std::endl;
				if (!error) {
					system("cls");
					std::cout << "merge" << std::endl;
					std::cout << socket.remote_endpoint().address();
					socket.write_some(boost::asio::buffer("1"), error);
					socket.read_some(boost::asio::buffer(buf), error);
					i++;
					if (!error) {
						socket.close();
					}
					std::cout << buf.data() << std::endl;
					std::cout << error.message() << std::endl;
				}


				//system("cls");


			}
			ioService.run();
		}

		catch (int e) {
			std::cout << e << std::endl;
		}




	}



	/*
	QApplication a(argc, argv);
	std::unique_ptr<label> l (new label);
	std::unique_ptr<QPixmap> pixmap (new QPixmap(500, 500));
	std::unique_ptr<QPainter> painter (new QPainter(pixmap.get()));
	std::unique_ptr<QTimer> timer(new QTimer());
	std::string initialConnection="true";
	//bject::connect(timer.get(), &QTimer::timeout, [&]() {
		try {
			while (true) {

				clientNetwork network("127.0.0.1", "31250");
				std::cout << network.error << std::endl;
				std::cout << network.read() << std::endl;
			}
			
			//std::string sentmove;
			//sentmove = moveSnake(l->direction);
			//if (initialConnection == "true") { 
			//	network.send("n"); 
		//		initialConnection = "false";
			//}else network.send(sentmove);
			
			//if (network.error) {
		//		std::cout << "no connection" << std::endl;
			//}
		/*	else {
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
			}

		}catch (std::exception& e) {
			std::cout << "error " << e.what() << std::endl;
			painter->fillRect(0, 0,500,500, Qt::gray);
			painter->drawText(100,100, "NO CONNECTION");
			l->setPixmap(*pixmap);
		}
	;
timer->start(500);
	l->setGeometry(300, 300, 50 * 11, 50 * 10);
	l->show();
	turn a.exec();*/
