#ifndef __RS485_CONNECTOR_H__
#define __RS485_CONNECTOR_H__

#include "Connector_Intf.h"
#include <queue>
#include <iostream>
#include <unordered_map>

class RS485_Connector : public Connector_Intf
{
private: 
	int portNum;
	int baudRate;
	int isEvenParity;
	std::unordered_map < std::string, std::queue<char>> deviceFIFOs;
	
	static bool started;

public :

	~RS485_Connector();
	// RS485 constructor
	RS485_Connector(
		int portNum_in,
		int baudRate_in, 
		bool isEvenParity_in);

	bool addDev(std::string devId, int argNum = 0, ...);
	int read(std::string devId, char* buf, int buflen);
	int write(std::string devId, char* buf, int buflen);

	// rs485 specific implementations => this class will run a thread to read from the RS485 port!
	void start();
	void stop();
};

#endif

