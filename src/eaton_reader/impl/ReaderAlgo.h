#ifndef __READER_ALGO_H__
#define __READER_ALGO_H__

#include "Algo_Intf.h"

class ReaderAlgo : public Algo_Intf
{
private:
	static unsigned long long total_num_bytes_read;
	static unsigned long long num_of_read_operations;
public:
	ReaderAlgo();
	~ReaderAlgo();
	
	void execute_algo(char* buf, int len);
	void report_algo();
};

#endif
