#ifndef __RS485_DEVICE_IMPL_A_H__
#define __RS485_DEVICE_IMPL_A_H__

#include  "Data_Source_Intf.h"
#include <string>

/**
 * this is an implementation for rs232 device. 
 * all code is specific to this data source impl.
 */

class RS485_Dev_Impl_A : public Data_Source_Intf
{
public:
	RS485_Dev_Impl_A(std::string name_in, Connector_Intf* connector_in);
	int read (char* buf, int len);
};

#endif
