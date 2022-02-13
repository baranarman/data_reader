#ifndef __DATA_SOURCE_INTF_H__
#define __DATA_SOURCE_INTF_H__

#include <string>
#include "Connector_Intf.h"

class Data_Source_Intf
{
public:
	const std::string name;

protected:
	Connector_Intf* connector;

public:
 	virtual ~Data_Source_Intf(){};
	Data_Source_Intf(std::string name_in, Connector_Intf* connector_in) : 
		name(name_in),
		connector(connector_in){}
	virtual int read(char* buf, int len) = 0;
};


#endif
