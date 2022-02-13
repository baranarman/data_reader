#include "DataProcessor.h"
#include <iostream>

using namespace std;

DataProcessor::DataProcessor(Algo_Intf* algo_in) : algo(algo_in)
{
	cout << "DataProcessor() +" << endl;
	cout << "DataProcessor() -" << endl;
}

void DataProcessor::subscribe(Data_Source_Intf* dataSrc)
{
	if ( NULL == dataSrc) return;
	subscriptionList[dataSrc->name] = dataSrc;
}

void DataProcessor::unsubscribe(string deviceId)
{
	auto elem = subscriptionList.find(deviceId);
	if (elem == subscriptionList.end()) return;
	subscriptionList.erase(elem);
}

DataProcessor::~DataProcessor()
{
	cout << "~DataProcessor() +" << endl;
	cout << "~DataProcessor() -" << endl;
}

void DataProcessor::processOnce()
{
	char buf [2048];
	cout << "processOnce for: " << endl;
	for (auto elem : subscriptionList)
	{
		cout << elem.first << endl;
		int read_size = elem.second->read(&(buf[0]), 2048);
		algo->execute_algo(&(buf[0]), read_size);
	}

	algo->report_algo();
}
