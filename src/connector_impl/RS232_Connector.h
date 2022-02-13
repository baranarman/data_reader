#ifndef __RS232_CONNECTOR_H__
#define __RS232_CONNECTOR_H__

#include "Connector_Intf.h"

class RS232_Connector : public Connector_Intf
{
private:
	int portNum;
	int baudRate;
	bool isEvenParity;
public:
	~RS232_Connector();
	RS232_Connector(int portNum_in, int baudRate_in, bool isEvenParity_in );
	
	bool addDev(std::string devId, int argNum = 0, ...);
	int read(std::string devId, char* buf, int buflen);
	int write(std::string devId, char* buf, int buflen);
};

#endif
