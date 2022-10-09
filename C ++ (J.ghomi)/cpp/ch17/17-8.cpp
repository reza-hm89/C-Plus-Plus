#include <strstream>
#include <iostream>
using namespace std;
int main()
{
	char *p;
	ostrstream outs; //dynamically allocate array
	outs << "C++ array- based I/O  ";
	outs << -10 << hex << "  ";
	outs.setf(ios::showbase);
	outs << 100 << ends;
	p = outs.str();
	cout << p;
	return 0;
}
	 






		

