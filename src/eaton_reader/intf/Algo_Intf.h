#ifndef __ALGO_INTF_H__
#define __ALGO_INTF_H__

class Algo_Intf
{
public:
	virtual ~Algo_Intf(){};
	virtual void execute_algo(char * buf, int len) = 0;
	virtual void report_algo() = 0;
};

#endif
