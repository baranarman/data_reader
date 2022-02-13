#include "ReaderAlgo.h"
#include <iostream> 

using namespace std;

unsigned long long ReaderAlgo::total_num_bytes_read = 0;
unsigned long long ReaderAlgo::num_of_read_operations = 0;


ReaderAlgo::ReaderAlgo()
{
	cout << "ReaderAlgo() + " << endl;
	cout << "ReaderAlgo() - " << endl;
}

ReaderAlgo::~ReaderAlgo()
{

	cout << "~ReaderAlgo() + " << endl;
	cout << "~ReaderAlgo() - " << endl;
}

void 
ReaderAlgo::execute_algo(
	char* buf,
	int len)
{
	cout << "execute_algo() + " << endl;
	num_of_read_operations ++;
	total_num_bytes_read += len;
	cout << "execute_algo() - " << endl;
}

void 
ReaderAlgo::report_algo()
{
	cout << "report_algo() + " << endl;
	
	cout << "total num of bytes read: " << total_num_bytes_read << endl;
	cout << "total read op. count   : " << num_of_read_operations << endl;

	cout << "report_algo() - " << endl;
}
