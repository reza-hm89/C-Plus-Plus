#include <iostream>
using namespace std;
extern "C" void myfunc();
int main()
{
	myfunc();
	return 0;
}
//***************
void myfunc()
{
	cout << "This links as a C function.";
}

	 






		

