#include <strstream>
#include <iostream>
using namespace std;
int main()
{
	char iostr[80];
	strstream strio(iostr, sizeof(iostr), ios::in | ios::out);
	int a, b;
	char str[80];
	strio << "10  20  testing \n";
	strio >> a >> b >> str;
	cout << a << "  " << b << "  " << str << endl;
	return 0;
}
	 






		

