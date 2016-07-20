#pragma once
#include "snakeGame_session.h"

snakeGame_session::snakeGame_session(boost::asio::ip::tcp::socket newSocket, snakeGame &mainGame):snakeSocket(std::move(newSocket)),game(mainGame) {
	
}
void snakeGame_session::readSnakeMove() {
	buf.resize(1);
	//Sleep(500);
	boost::asio::async_read(snakeSocket, boost::asio::buffer(buf), [&](const boost::system::error_code ec,size_t length) {
		std::cout << ec.message() << std::endl;
		std::cout << length << std::endl;
		//buf.resize(1);
		//direction = (int)buf.data();
		std::cout <<"data sent by client: "<< buf.at(0) << std::endl;
		if (!ec) {
			//std::cout <<"number of players"<< game.getNumberofPlayers() << std::endl;
		//sendSnakeData();
		readSnakeMove();

		}
		

		
	});
	
}
void snakeGame_session::sendSnakeData() {
	//playerSnake.changeDirection(Direction(direction));
	boost::asio::async_write(snakeSocket, boost::asio::buffer("server response"), [&](const boost::system::error_code ec, size_t length) {
		std::cout << ec.message() << std::endl;
		if (ec) { snakeSocket.close(); };
		if(!ec){ 
			
		
			sendSnakeData(); }
		
	});

}
void snakeGame_session::startSession() {
	game.joinGame(shared_from_this());
	point snakehead;
	snakehead.x = 0;
	snakehead.y = 0;
	playerSnake.elongate(snakehead, Direction::right);
	direction = 1;
	playerSnake.getData(data);
	readSnakeMove();
	sendSnakeData();
	//movesnake();
};
void snakeGame_session::movesnake() {
	//Sleep(500);
		playerSnake.changeDirection(Direction(direction));
		playerSnake.getData(data);
		std::cout << data.get<int>("snakebody.point0.x") << std::endl;
		movesnake();
	


	

};
