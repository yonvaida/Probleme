#pragma once
#include <iostream>
#include <boost\asio.hpp>

#include <boost\property_tree\ptree.hpp>
#include <websocketpp\config\asio_no_tls.hpp>
#include <websocketpp\server.hpp>
#include <string>
#include "boost\thread.hpp"
#include <snakeclient.h>
#include <mutex>
#include "boost\property_tree\json_parser.hpp"
#include <condition_variable>

std::condition_variable cv;
boost::property_tree::ptree data;
std::mutex serverMutex;
std::ostringstream tempdata;

typedef websocketpp::server<websocketpp::config::asio> server;
server print_server;


void on_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
	tempdata.str("");
	serverMutex.lock();
	boost::property_tree::write_json(tempdata, data);
	serverMutex.unlock();


	std::cout <<"message from client:"<< msg->get_payload() << std::endl;
	if (data.empty()) {
		print_server.send(hdl, "STOP", msg->get_opcode());
		cv.notify_all();
	}
	else {
		print_server.send(hdl, tempdata.str(), msg->get_opcode());
	}
	
}
void serverCommunication() {
	std::unique_lock<std::mutex> locker(serverMutex);
	cv.wait(locker);
	std::string move = "1";
	boost::asio::io_service ioService;
	std::unique_ptr<networkConnection> connection(new networkConnection(ioService, move));
	connection->startConnection(data);
	ioService.run();
}
void webCommunication() {
	print_server.set_message_handler(&on_message);
	print_server.init_asio();
	print_server.listen(1080);
	print_server.start_accept();
	print_server.run();

};


int main() {
	boost::thread web(webCommunication);
	boost::thread serverConnect(&serverCommunication);
	serverConnect.join();
	web.join();
}