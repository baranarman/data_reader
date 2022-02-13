#include <iostream>
#include <chrono>
#include <thread>


// system interfaces
#include "Data_Source_Intf.h"
#include "Connector_Intf.h"
#include "Processor_Intf.h"
#include "Subscription_Intf.h"
#include "Algo_Intf.h"

// connector implementation
#include "RS232_Connector.h"
#include "RS485_Connector.h"

// device implementation
#include "RS232_Dev_Impl_A.h"
#include "RS232_Dev_Impl_B.h"
#include "RS485_Dev_Impl_A.h"

// processor impl
#include "DataProcessor.h"

// algorithm impl
#include "ReaderAlgo.h"


using namespace std;

int main(void)
{
	/********************************
	 *     CREATING CONNECTORS      *
	 ********************************/     
	 
	// create an RS232 Connector
	// portNum: 1
	// baudRate: 9600
	// evenParity: false
	RS232_Connector rs232_p1_connector(1, 9600, false);

	// create second RS232 Connector
	// portNum: 2
	// baudRate: 115200
	// evenParity: true
	RS232_Connector rs232_p2_connector(2, 115200, true);

	// create the rs485 connector
	// portNum: 3
	// baudRate: 4800
	// evenParity: false
	RS485_Connector rs485_p3_connector(3, 4800, false);
	
	/**********************************
	*        CREATING DEVICES         *
	***********************************/        

	// rs232 dev-1
	// name: rs232_con1_dev1
	RS232_Dev_Impl_A rs232_dev1("rs232_port1_dev1", &rs232_p1_connector);

	// rs232 dev-2
	// name: rs232_con2_dev2
	RS232_Dev_Impl_B rs232_dev2("rs232_port2_dev2", &rs232_p1_connector);

	// rs485 dev-1
	// name: rs485_con1_dev1
	RS485_Dev_Impl_A rs485_dev1("rs485_port3_dev1", &rs485_p3_connector);

	// rs485 dev-2
	// name: rs485_con1_dev2
	RS485_Dev_Impl_A rs485_dev2("rs485_port3_dev2", &rs485_p3_connector);
	
	// rs485 dev-3
	// name: rs485_con1_dev3
	RS485_Dev_Impl_A rs485_dev3("rs485_port3_dev3", &rs485_p3_connector);

	
	/**********************************
	*        CREATING PROCESSOR       *
	***********************************/        
	ReaderAlgo reader_algorithm; 
	DataProcessor my_reader_processor(&reader_algorithm);

	my_reader_processor.subscribe(&rs232_dev1);
	my_reader_processor.subscribe(&rs232_dev2);
	my_reader_processor.subscribe(&rs485_dev1);
	my_reader_processor.subscribe(&rs485_dev2);
	my_reader_processor.subscribe(&rs485_dev3);
	

	while (true)
	{
		this_thread::sleep_for(1000ms);
		my_reader_processor.processOnce();
	}

	return 0;
}
