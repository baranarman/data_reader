#ifndef __CONNECTOR_INTF_H__
#define __CONNECTOR_INTF_H__

#include <string>
#include <vector>

class Connector_Intf
{
protected:
	std::vector<std::string> deviceIdList;
public:
	virtual ~Connector_Intf(){};
	virtual bool addDev(std::string devId, int argNum = 0, ...) = 0;
	virtual int read(std::string devId, char* buf, int buflen) = 0;
	virtual int write(std::string devId, char* buf, int buflen) = 0;
};

#endif
