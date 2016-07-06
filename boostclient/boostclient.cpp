#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <stdio.h>
void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) {
	std::cout << ec << std::endl;
}

int main()
{
	try {
		std::vector<char> buf;
		buf.resize(3000);
		std::string connectionStatus = "initial";
		boost::asio::io_service ioService;
		int i = 0;
		
		boost::asio::ip::tcp::resolver::query query("192.168.1.66", "31250");
		boost::system::error_code error;
		boost::asio::ip::tcp::resolver resolver(ioService);
		boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);
	
		
		while (true) {
		boost::asio::ip::tcp::socket socket(ioService);
		socket.connect(*iterator,error);
		std::cout << error.message() << std::endl;
		if (!error) {
			system("cls");
			std::cout << "merge" << std::endl;
			std::cout << socket.remote_endpoint().address();
			socket.write_some(boost::asio::buffer("client 2"),error);
			socket.read_some(boost::asio::buffer(buf),error);
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


