#ifndef __SUBSCRIPTION_INTF_H__
#define __SUBSCRIPTION_INTF_H__

#include "Data_Source_Intf.h" 
#include <string>

class Subscription_Intf
{
public:
	virtual ~Subscription_Intf(){};
	virtual void subscribe(Data_Source_Intf* inSrc) = 0;
	virtual void unsubscribe(std::string devId) = 0;
};

#endif
