#include "snakePlayer.h"
player::player(std::shared_ptr<boost::asio::ip::tcp::socket> playerSocket) {
	socket = std::move(playerSocket);
}