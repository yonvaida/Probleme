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

		boost::asio::ip::tcp::socket socket(ioService);
		
		boost::asio::ip::tcp::resolver::query query("10.60.17.19", "35200");
		boost::system::error_code error;
		boost::asio::ip::tcp::resolver resolver(ioService);
		boost::asio::ip::tcp::resolver::iterator iterator= resolver.resolve(query);
		
		while (true) {
		
		socket.connect(*iterator,error);
		std::cout << error << std::endl;
		if (!error) {
			//socket.write_some(boost::asio::buffer("ddd"));
			//std::cout << buf.data() << std::endl;
		}
		
			
		//system("cls");
			
			ioService.run();
		}
	}

		catch (int e) {
			std::cout << e << std::endl;
		}




	}


