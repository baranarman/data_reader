#ifndef __PROCESSOR_INTF_H__
#define __PROCESSOR_INTF_H__

#include "Subscription_Intf.h"
#include "Algo_Intf.h"
#include "Data_Source_Intf.h"
#include <string>

class Processor_Intf : public Subscription_Intf
{
protected:
	Algo_Intf* algo;	
public:
	virtual ~Processor_Intf(){}
	virtual void subscribe(Data_Source_Intf* dataSrc) = 0;
	virtual void unsubscribe(std::string devId) = 0;
};

#endif
