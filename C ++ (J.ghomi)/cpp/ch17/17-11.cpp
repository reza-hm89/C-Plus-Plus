#include <iostream>
using namespace std;
int main()
{
	int i;
	char *p = "this is a string";
	i = reinterpret_cast<int> (p); // cast pointer to integer
	cout << "i = " << i;
	return 0;
}









