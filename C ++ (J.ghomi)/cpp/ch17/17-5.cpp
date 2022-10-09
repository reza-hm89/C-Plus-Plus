#include <strstream>
#include <iostream>
using namespace std;
int main()
{
	char str[80];
	ostrstream outs(str, sizeof(str));
	outs << "C++ array-based I/O.";
	outs << 1024 << hex << "  ";
	outs.setf(ios::showbase);
	outs << 100 << "  " << 99.789 << endl;
	cout << str;
	return 0;
}
	 






		

