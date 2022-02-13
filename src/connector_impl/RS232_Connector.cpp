#include "RS232_Connector.h"
#include <iostream>
#include <string>
#include <stdarg.h>
#include <assert.h>

using namespace std; 

bool 
RS232_Connector::addDev(
	std::string devId, 
	int argNum, 
	...)
{
	// todo here more than one might work instead of one string list string to xx map shall also be kept 
	// depending on the implementation ... 
	deviceIdList.push_back(devId);

	va_list args;
	va_start(args, argNum);
	for (int i = 0; i < argNum; i++)
	{
		cout << "arg_i: " << va_arg(args, int) << endl;
	}
	va_end(args);
	// some reason might be that it returns false
	return true;
}


/**
 * as rs232 is point to point devNum is not used!
 */
int 
RS232_Connector::read(
	string devId, 
	char* buf, 
	int buflen)
{
	cout << "Read from RS232_Connector is called " <<endl;
	
	for (int i = 0; i < buflen; i++)
	{
		buf[i] = i % 127;
	}

	return buflen;
}

/**
 * not implemented yet!
 */
int 
RS232_Connector::write(
	string devId, 
	char* buf, 
	int buflen)
{
	cout << "Write to RS232 is called" << endl;
	assert(!"not implemented yet");
	return buflen;
}

RS232_Connector::RS232_Connector(
	int portNum_in,
	int baudRate_in,
	bool isEvenParity_in) : portNum(portNum_in), baudRate(baudRate_in), isEvenParity(isEvenParity_in)
{
	cout << "RS232_Connector() + " << endl;
	cout << "RS232_Connector() - " << endl;
}

RS232_Connector::~RS232_Connector(){}

