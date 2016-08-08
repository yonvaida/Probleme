#pragma once
#include <boost\property_tree\ptree.hpp>
#include <string>
#include "boost\thread.hpp"
#include <mutex>
#include "boost\property_tree\json_parser.hpp"
#include <iostream>
#include <boost\asio.hpp>
#include <functional>
#include "proxyServer.h"

std::ostringstream tempData;
boost::asio::io_service ioService;
std::vector<std::shared_ptr<proxyServer>> serversList;
boost::property_tree::ptree data;
void on_message(websocketpp::server<websocketpp::config::asio>* webServer,websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr clientMessage) {
	tempData.str("");
	serversList.at(0)->getData(data);
	boost::property_tree::write_json(tempData,data);
	std::cout << clientMessage->get_payload() << std::endl;
	serversList.at(0)->setMove(clientMessage->get_payload());
	webServer->send(hdl,tempData.str(), clientMessage->get_opcode());
}

void on_accept(websocketpp::connection_hdl hdl) {
	std::cout << "Connection accepted" << std::endl;
	std::shared_ptr<proxyServer> proxy(new proxyServer(ioService));
	proxy->startConnection();

	serversList.push_back(std::move(proxy));
}


int main() {
	
	websocketpp::server<websocketpp::config::asio> webServer;
	
	webServer.init_asio(&ioService);
	webServer.listen(1080);
	webServer.set_open_handler(&on_accept);
	webServer.set_message_handler(std::bind(&on_message,&webServer,std::placeholders::_1,std::placeholders::_2));
	webServer.start_accept();
	
	std::cout << "new proxy" << std::endl;
	ioService.run();

}







/*

std::string move = "1";
int i = 0;
boost::asio::io_service ioService;
boost::condition_variable cv;
boost::property_tree::ptree data;
boost::mutex serverMutex;
std::ostringstream tempdata;
typedef websocketpp::server<websocketpp::config::asio> server;
server print_server;

void on_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
	tempdata.str("");
	serverMutex.lock();
	boost::property_tree::write_json(tempdata, data);
	move = msg->get_payload();
	std::cout << "MOVE IS" << move << std::endl;
	serverMutex.unlock();
	std::cout <<"message from client:"<< msg->get_payload() << std::endl;

	print_server.send(hdl,tempdata.str(), msg->get_opcode());
}
void on_accepted(websocketpp::connection_hdl hdl) {
	i++;
	std::error_code ec;
	std::cout << "connection accepted" << std::endl;
}

int main() {
	print_server.set_message_handler(&on_message);
	print_server.set_open_handler(&on_accepted);
	print_server.init_asio(&ioService);
	print_server.listen(1080);
	print_server.start_accept();
	std::shared_ptr<networkConnection> connection(new networkConnection(ioService, move));
	connection->startConnection(data);
	print_server.run();
}*/