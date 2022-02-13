#ifndef __DATA_PROCESSOR_H__
#define __DATA_PROCESSOR_H__

#include "Processor_Intf.h"
#include <unordered_map>

class DataProcessor : public Processor_Intf
{
private:
	std::unordered_map <std::string, Data_Source_Intf*> subscriptionList;
protected:
	Algo_Intf* algo;
public:
	DataProcessor(Algo_Intf* algo_in);
	~DataProcessor();

	void subscribe(Data_Source_Intf* dataSrc);
	void unsubscribe(std::string devId);

	void processOnce();
};

#endif
