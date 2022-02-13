#include "RS232_Dev_Impl_B.h"
#include <string>
#include <iostream>

using namespace std;

RS232_Dev_Impl_B::RS232_Dev_Impl_B(
	string name_in,
	Connector_Intf* connector_in ) : Data_Source_Intf(name_in, connector_in)
{
	cout << "RS232_Dev_Impl_B constructor called!" << endl;
}

int 
RS232_Dev_Impl_B::read(
	char* buf,
	int len )
{
	cout << "RS232_Dev_Impl_B::read() +" << endl;

	int result = connector->read(name, buf, len);
	
	cout << "RS232_Dev_Impl_B::read() -" << endl;

	return result;
}

