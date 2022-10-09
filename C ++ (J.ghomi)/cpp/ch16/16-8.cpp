#include <iostream>
#include <string>
using namespace std; 
int main()
{
   string  str1("Alpha");
   string  str2("Beta");
   string  str3("Omega");
   cout << "str1 = " << str1 << endl;
   cout << "str2 = " << str2 << endl;
   cout << "str3 = " << str3 << endl;
   string str4;
   str4 = str1;
   cout << "After assign str1 to str4: " << str4 << "\n";
   str4 = str1 + str2;
   cout << "str4 = str1 + str2: " << str4 << endl;
   if(str3 > str1)
	     cout << "str3 > str1 \n";
   else
	     cout << "str3 <= str1\n";
   //create a string object using another string object
   string str5(str1);
   cout << "Enter a string :";
   cin >> str5;
   cout << "str5 created from str1 :" << str5 << endl;
   str5.insert(6, str1);
   cout << "Insert str1 to str5 from 6 : " << str5 << endl;
   str4.erase(1,4);
   cout << "Erase 4 character from str4 at position 3: " << str4 << endl;
   
   return 0;
}
   