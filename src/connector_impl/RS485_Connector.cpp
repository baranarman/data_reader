#include "RS485_Connector.h"

#include <string>
#include <iostream>
#include <stdarg.h>

#include <assert.h>

using namespace std;

bool 
RS485_Connector::addDev(
	string devId, 
	int argNum, 
	...)
{
	// num of param for each Connector impl might vary so ...
	
	va_list args;
	va_start(args, argNum);
	
	for(int i = 0; i < argNum; i++)
	{
		cout << "arg["<< i <<"]: " << va_arg(args, int) << endl;
	}
	va_end(args);

	deviceIdList.push_back(devId);
	// todo insert new fifo queu for each added device ... 
	
	// may be there can be a reason that cause this to fail [eg: duplication of id ... ]
	return true;
}

int 
RS485_Connector::read(
	string devId,
	char* buf, 
	int buflen)
{
	cout << "Read from RS485 is called" << endl;

	for(int i = 0; i < 128; i++)
	{
		buf[i] = i*2 % 127;
	}
	
	return 128;
}

int 
RS485_Connector::write(
	string devId, 
	char* buf, 
	int buflen)
{
	cout << "Write to RS485 is called" << endl;
	assert(!"RS485_Connector::write() not implemented yet!");
	return buflen;
}

void RS485_Connector::start()
{

}

void RS485_Connector::stop()
{

}

RS485_Connector::RS485_Connector(
	int portNum_in,
	int baudRate_in, 
	bool isEvenParity_in) : portNum(portNum_in), baudRate(baudRate_in), isEvenParity(isEvenParity_in)
{
	cout << "RS485_Connector() + " << endl;
	cout << "RS485_Connector() - " << endl;
}

RS485_Connector::~RS485_Connector(){}
