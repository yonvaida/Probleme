#pragma once
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
#include "boost\thread.hpp"
#include "boost\date_time\posix_time\posix_time.hpp"
boost::mutex mutex;
boost::property_tree::ptree data;
std::string lastmove="";
std::string move;
int buf;
std::vector<uint8_t> dataBuffer;
int draw(int argc, char * argv[]) {
	boost::property_tree::ptree snakeData;
	QApplication a(argc, argv);
	std::unique_ptr<label> l(new label);
	std::unique_ptr<QPixmap> pixmap(new QPixmap(550, 500));
	std::unique_ptr<QPainter> painter(new QPainter(pixmap.get()));
	std::unique_ptr<QTimer> timer(new QTimer);
	move = moveSnake(l->direction);;
	QObject::connect(timer.get(), &QTimer::timeout, [&]() {
		
		mutex.lock();
		snakeData = data;
		move = moveSnake(l->direction);
		//std::cout << move << std::endl;
		mutex.unlock();
	if (snakeData.empty()) {
			painter->fillRect(500, 0, 50, 500, Qt::darkGray);
		}
		else {
			if (snakeData.get<std::string>("game_status") == "GAME OVER") {
				QFont font;
				font.setPixelSize(50);
				font.setBold(true);
				painter->setFont(font);
				painter->drawText(snakeData.get<int>("table.width") * 2, snakeData.get<int>("table.height") * 2, "GAME OVER");
				painter->drawText(snakeData.get<int>("table.width") * 2 + 60, snakeData.get<int>("table.height") * 2 + 50, "SCORE:");
				painter->drawText(snakeData.get<int>("table.width") * 2 + 130, snakeData.get<int>("table.height") * 2 + 100, QString::number(snakeData.get<int>("game_score")));
				painter->drawText(snakeData.get<int>("table.width") * 2, snakeData.get<int>("table.height") * 2 + 150, "F5 - New Game");
			}
			else {
				if (l->direction == Direction::newGame)l->direction = Direction::right;
				QFont font;
				font.setPixelSize(10);
				font.setBold(true);
				painter->setFont(font);
				painter->fillRect(0, 0, snakeData.get<int>("table.width") * 10, snakeData.get<int>("table.height") * 10, Qt::gray);
				painter->drawPixmap(snakeData.get<int>("snakefood.x") * 10, snakeData.get<int>("snakefood.y") * 10, 10, 10, QPixmap("strawberry.png"));
				painter->fillRect(snakeData.get<int>("table.width") * 10, 0, 50, snakeData.get<int>("table.height") * 10, Qt::darkGray);
				painter->drawText(snakeData.get<int>("table.width") * 10 + 5, 10, "SCORE:");
				painter->drawText(snakeData.get<int>("table.width") * 10 + 20, 10 + 20, QString::number(snakeData.get<int>("game_score")));
				for (int i = 0; i < snakeData.get<int>("snakebody.length"); i++) {
					painter->fillRect(snakeData.get<int>("snakebody.point" + std::to_string(i) + ".x") * 10, snakeData.get<int>("snakebody.point" + std::to_string(i) + ".y") * 10, 10, 10, Qt::Dense2Pattern);
				};
			}
		}
	l->setPixmap(*pixmap);
	});
	timer->start();	
	l->setGeometry(300, 300, 50 * 11, 50 * 10);
	l->show();
	return a.exec();
}
void write_async(boost::asio::ip::tcp::socket &tempsocket) {
	//mutex.lock();
	//lastmove = move;
	//if (lastmove != move) {
	
	std::cout << "Current move: " << move << std::endl;
		boost::asio::async_write(tempsocket, boost::asio::buffer(move), [&](const boost::system::error_code &ec, size_t length) {
			if (!ec) {
				write_async(tempsocket);
		//		lastmove = move;
			}
		});
	//}
	
	//mutex.unlock();	
}

void read_async(boost::asio::ip::tcp::socket &tempsocket) {
	boost::asio::async_read(tempsocket, boost::asio::buffer(&buf,4),  [&](const boost::system::error_code &ec, size_t length) {
		if (!ec) {
			mutex.lock();
			int readbuffer = buf;
			mutex.unlock();
				dataBuffer.resize(readbuffer);
				boost::asio::async_read(tempsocket, boost::asio::buffer(dataBuffer,readbuffer), [&](const boost::system::error_code ec, size_t length) {
					mutex.lock();
					deserialize(dataBuffer, data);
					mutex.unlock();
					read_async(tempsocket);
				});				
		}
	});
}
void networkConection() {
	std::string lastmove;
	boost::asio::io_service ioService;
	boost::asio::ip::tcp::socket datasocket(ioService);
	boost::asio::ip::tcp::resolver resolver(ioService);
	boost::asio::ip::tcp::resolver::iterator endpoint;
	boost::asio::ip::tcp::resolver::iterator end;
	boost::asio::ip::tcp::resolver::query query("127.0.0.1", "32560");
	endpoint = resolver.resolve(query);
	//buf.resize(4);
	boost::asio::async_connect(datasocket, endpoint, [&](const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator iterator) {
		if (!ec) {
			std::cout << "Connect succes" << std::endl;

			write_async(datasocket);
			read_async(datasocket);
		}
	});
	ioService.run();
}
int main(int argc, char * argv[])
{
	boost::thread drawThread(boost::bind(draw,argc, argv));
	boost::thread communication(boost::bind(&networkConection));
	communication.join();
	drawThread.join();
}