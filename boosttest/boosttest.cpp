#include <boost\asio.hpp>
#include <boost\asio\write.hpp>
#include <boost\asio\buffer.hpp>
#include <boost\asio\ip\tcp.hpp>
#include <boost\array.hpp>
#include <boost\bind.hpp>
#include <iostream>
#include <vector>
#include <set>

class server {
public:
	server(boost::asio::io_service &ioService): acceptor(ioService,boost::asio::ip::tcp::endpoint( boost::asio::ip::tcp::v4(), 31250)),socket(ioService) {
			
		std::cout << "Constructor" << std::endl;
		
		server::connectionAccept();
	};
	void connectionAccept() {
		buf.resize(1024);
		
		acceptor.async_accept(socket, [&](const boost::system::error_code &ec) {
			std::cout << ec.message() << std::endl;
			if (!ec) {
				socket.read_some(boost::asio::buffer(buf));
				socket.write_some(boost::asio::buffer("server serponse"));
				std::cout << buf.data() << std::endl;
				connectionAccept();
			}
			
		});
	}


	void runServer() {
		//ioService.run();
	}
	void closeSocket() {

	};

private:
	void read_handler() {
	
	};
	void connectionHandler(const boost::system::error_code &ec) {
		server::connectionAccept();

	}
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::endpoint endPoint;
	std::vector<char> buf;
	boost::asio::ip::tcp::acceptor acceptor;
};


	int main() {
		try {
			boost::asio::io_service ioService;
		//	while (true) {
server testServer(ioService);
		//	}
			
			
			ioService.run();
		}
		catch(int e){
			std::cout << e << std::endl;

		};
		
		
		
		
	}

