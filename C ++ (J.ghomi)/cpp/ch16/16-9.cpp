#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	map<string, string> directory;
    directory.insert(pair<string, string>("ali", "0111-3260772")); 
    directory.insert(pair<string, string>("ahmad", "0111-3260773")); 
    directory.insert(pair<string, string>("reza", "0111-3260774")); 
    directory.insert(pair<string, string>("mohsen", "0111-3260777")); 
    string name;
	cout << "Enter name to search : ";
	cin >> name;
	map<string, string>::iterator p;
	p = directory.find(name);
	if(p != directory.end())
		 cout << "Phone number is: " << p ->second;
	else
		 cout << "Name not in directory.";
	return 0;
}






		

