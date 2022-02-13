#include "RS485_Dev_Impl_A.h"
#include <string>
#include <iostream>

using namespace std;

RS485_Dev_Impl_A::RS485_Dev_Impl_A(
	string name_in,
	Connector_Intf* connector_in ) : Data_Source_Intf(name_in, connector_in)
{
	cout << "RS485_Dev_Impl_A constructor called!" << endl;
}

int 
RS485_Dev_Impl_A::read(
	char* buf,
	int len )
{
	cout << "RS485_Dev_Impl_A::read() +" << endl;

	int result = connector->read(name, buf, len);
	
	cout << "RS485_Dev_Impl_A::read() -" << endl;

	return result;
}

