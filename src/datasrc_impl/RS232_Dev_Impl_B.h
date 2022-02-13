#ifndef __RS232_DEVICE_IMPL_B_H__
#define __RS232_DEVICE_IMPL_B_H__

#include  "Data_Source_Intf.h"
#include <string>

/**
 * this is an implementation for rs232 device. 
 * all code is specific to this data source impl.
 */

class RS232_Dev_Impl_B : public Data_Source_Intf
{
public:
	RS232_Dev_Impl_B(std::string name_in, Connector_Intf* connector_in);
	int read (char* buf, int len);
};

#endif
