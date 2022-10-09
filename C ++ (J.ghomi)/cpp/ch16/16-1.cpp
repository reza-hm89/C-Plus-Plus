#include <iostream>
#include <ctype>
#include <vector>
#include <conio>
using namespace std;
int main()
{
   clrscr();
   vector <char> v(10);
   cout << "Size = " << v.size() << endl;
   for (int i = 0; i < 10; i ++)
      v[i] = i + 'a';
   cout <<  "Current contents :" ;
   for (int i = 0; i <v.size(); i ++)
      cout << v[i] << "  ";
   cout << "\n";
   cout << "Expanding vector \n";
   for (int i = 0; i < 10; i ++)
       v.push_back(i  + 10 + 'a');
   cout << "New size = " << v.size() << endl;
   cout << "Current contents:\n";
   for (unsigned int i = 0; i < v.size(); i ++)
      cout << v[i] << "  ";
   cout << "\n";

   for (unsigned int i = 0; i < v.size(); i ++)
       v[i] = toupper(v[i]);
   cout << "Modified contents:\n";
   for (unsigned int i = 0; i < v.size(); i ++)
      cout << v[i] << "  ";
   cout << "\n";
   cout << "Output using poiter:\n";
   vector<char>::iterator p;
   p = v.begin();
   while(p != v.end()) {
      cout << *p << "  ";
      p ++;
   }
   cout << "\n";
   p = v.begin();
   p += 2;   //point to 3rd element
   v.insert(p, 2, 'z');
   cout << "\nNew size after insert = " << v.size();
   cout << "\nInserted contents:\n";
   for (unsigned int i = 0; i < v.size(); i ++)
      cout << v[i] << "  ";
   cout << "\n";
   p = v.begin();
   p += 4;
   v.erase(p, p + 10);
   cout << "\nNew size after delete = " << v.size();
   cout << "\nDeleted contents:\n";
   for (unsigned int i = 0; i < v.size(); i ++)
      cout << v[i] << "  ";
   cout << "\n";
   getch();
   return 0;
}
