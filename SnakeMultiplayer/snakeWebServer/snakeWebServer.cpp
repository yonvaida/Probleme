#pragma once
#include <iostream>
#include <boost\asio.hpp>
#include <boost\property_tree\ptree.hpp>
#include <websocketpp\config\asio_no_tls.hpp>
#include <websocketpp\server.hpp>
#include <string>
#include "boost\thread.hpp"
#include <snakeclient.h>
boost::property_tree::ptree data;
int i = 0;
typedef websocketpp::server<websocketpp::config::asio> server;
server print_server;
void on_message(websocketpp::connection_hdl hdl, server::message_ptr msg) {
	i++;
	std::cout <<"message from client:"<< msg->get_payload() << std::endl;
	print_server.send(hdl,std::to_string(i), msg->get_opcode());
	
}

void webCommunication() {
	//std::string lastmove;
	
	print_server.set_message_handler(&on_message);
	print_server.init_asio();
	print_server.listen(1080);
	print_server.start_accept();
	print_server.run();

};

void serverCommunication() {
	std::string move = "1";
	boost::asio::io_service ioService;
	std::unique_ptr<networkConnection> connection(new networkConnection(ioService, move));
	connection->startConnection(data);
	ioService.run();
}
int main() {
	//boost::thread web(webCommunication);
	boost::thread serverConnect(&serverCommunication);
	serverConnect.join();
	//web.join();
}