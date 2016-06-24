#pragma once
#include <iostream>
class networkInterface {
public:
	networkInterface();
	void networkDown();
	void networkLatency(int latency);

private:
	std::string status;
};