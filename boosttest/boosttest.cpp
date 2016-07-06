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
			
			
			std::set<std::string> endpointlist;
			
			
			std::vector<char> reading;
			reading.resize(1024);
			std::unique_ptr<std::vector<boost::asio::ip::tcp::socket>> socketList;
			
			
			int clientsconnected = 0;
			while (true) {
				boost::asio::ip::tcp::endpoint endPoint(boost::asio::ip::tcp::v4(), 35200);
				boost::asio::ip::tcp::acceptor acceptor(ioService);
				//endpointlist.insert(endPoint.address().to_string());
				boost::asio::ip::tcp::socket datasocket(ioService,endPoint);
				boost::system::error_code ec;
				//std::string temp;
				//acceptor.listen();
				//acceptor.open(endPoint.protocol());
				
				acceptor.open(endPoint.protocol());
				//acceptor.listen();
				acceptor.async_accept(datasocket,[&](const boost::system::error_code &ec) {
					std::cout << ec << std::endl;
					if (!ec) {
						//datasocket.read_some(boost::asio::buffer(reading));
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
				ioService.run();
				//return 0;
			}
		}
		catch(int e){
			std::cout << e << std::endl;

		};
		
		
		
		
	}