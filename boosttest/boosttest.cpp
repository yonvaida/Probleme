#include <boost\asio.hpp>
#include <boost\asio\write.hpp>
#include <boost\asio\buffer.hpp>
#include <boost\asio\ip\tcp.hpp>
#include <boost\array.hpp>
#include <boost\bind.hpp>
#include <iostream>
#include <vector>
#include <set>
void read_handler(const boost::system::error_code &ec, std::size_t bytes_transfered) {
	if (!ec) {
		std::cout << ec << std::endl;
		std::cout << "read is ok" << std::endl;
	}
}

	int main() {
		try {
			int clients = 0;
			boost::asio::io_service ioService;
			boost::asio::io_service::work work(ioService);
			
			std::set<std::string> endpointlist;
			
			
			std::vector<char> reading;
			reading.resize(1024);
			std::unique_ptr<std::vector<boost::asio::ip::tcp::socket>> socketList;
			
			
				boost::system::error_code ec;
				//std::string temp;
				//acceptor.listen();
				//acceptor.open(endPoint.protocol());
				boost::asio::ip::tcp::endpoint endPoint(boost::asio::ip::tcp::v4(), 35200);
				boost::asio::ip::tcp::acceptor acceptor(ioService, endPoint);
				boost::asio::ip::tcp::socket datasocket(ioService);
			int clientsconnected = 0;
			//while (true) {
				
				//acceptor.open(endPoint.protocol());
				//acceptor.bind(endPoint);
				//acceptor.listen();
				

				//endpointlist.insert(endPoint.address().to_string());

				std::cout << "while enter" << std::endl;

				acceptor.async_accept(datasocket, [&](const boost::system::error_code& ec) {
					std::cout << ec.message() << std::endl;
					std::cout << "in async_accept" << std::endl;
					if (!ec) {
						datasocket.read_some(boost::asio::buffer(reading));
						std::cout << reading.data() << std::endl;
					}

					//std::cout << "First read" << reading.at(0) << std::endl;
					//std::cout << endPoint.address() << std::endl;
					//boost::asio::async_write(datasocket, boost::asio::buffer("dddddd"), boost::asio::transfer_all());
					//std::cout << ec << std::endl;
				});
				//std::cout << endPoint.address() << std::endl;
				//std::cout << endpointlist.size() << std::endl;

				//system("cls");

				//datasocket.close();

				//return 0;
				//datasocket.close();
				ioService.run();
			//}
				
		}
		catch(int e){
			std::cout << e << std::endl;

		};
		
		
		
		
	}