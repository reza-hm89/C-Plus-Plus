#include <iostream>
#include <map>
#include <string>
using namespace std; 
class name {
	 char str [21];
public:
	name() { strcpy(str, ""); }
	name (char *s) { strcpy(str, s);}
	char *get() { return str;}
};

//************
bool operator<(name a, name b)
{
	 return strcmp(a.get(), b.get()) < 0;
}
//***********
class phonenum {
	  char str[21];
public:
	   phonenum() { strcpy(str, ""); }
	   phonenum(char *s) { strcpy(str, s); }
	   char *get() { return str ; }
};
//*********

int main()
{
   map <name, phonenum> directory;
   directory.insert(pair<name, phonenum>(name("ALI"), phonenum("0111-3260772")));
   directory.insert(pair<name, phonenum>(name("AHMAD"), phonenum("0111-3260773")));
   directory.insert(pair<name, phonenum>(name("REZA"), phonenum("0111-3260774")));
   directory.insert(pair<name, phonenum>(name("MOHSEN"), phonenum("0111-3260775")));
   char st[21];
   cout << "Enter name: ";
   cin >> st;
   map<name, phonenum>::iterator p;
   p = directory.find(name(st));

   if(p != directory.end())
	      cout << "Phone number: " << p -> second.get();
   else
	       cout << "Name not in directory.";
   
   return 0;
}
   