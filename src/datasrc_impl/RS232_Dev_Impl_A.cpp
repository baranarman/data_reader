#include "RS232_Dev_Impl_A.h"
#include <string>
#include <iostream>

using namespace std;

RS232_Dev_Impl_A::RS232_Dev_Impl_A(
	string name_in,
	Connector_Intf* connector_in ) : Data_Source_Intf(name_in, connector_in)
{
	cout << "RS232_Dev_Impl_A constructor called!" << endl;
}

int 
RS232_Dev_Impl_A::read(
	char* buf,
	int len )
{
	cout << "RS232_Dev_Impl_A::read() +" << endl;

	int result = connector->read(name, buf, len);
	preprocess_data(buf, result);
	
	cout << "RS232_Dev_Impl_A::read() -" << endl;

	return result;
}

void 
RS232_Dev_Impl_A::preprocess_data(
	char* buf,
	int len)
{
	cout << "RS232_Dev_Impl_A::preprocess_data +" << endl;

	for (int i = 0; i < len; i++)
	{
		buf[i]++;
	}
	
	cout << "RS232_Dev_Impl_A::preprocess_data -" << endl;
}
