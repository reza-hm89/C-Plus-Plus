#include <strstream>
#include <iostream>
using namespace std;
int main()
{
	char s[] = "10  hello  0x75   42.73  OK";
	istrstream ins(s);
	int i;
	char str[80];
	float f;
	//reading: 10 hello
	ins >> i;
	ins >> str;
	cout << i << "  " << str << endl;
	//reading 0x75  42.73 OK
	ins >> hex >> i;
	ins >> f;
	ins >> str;
	cout << hex << i << "  " << f << "  " << str;
	return 0;
}
	 






		

