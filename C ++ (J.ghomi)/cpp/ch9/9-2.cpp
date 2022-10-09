#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
   char ch;
   clrscr();
   ofstream  fp("test", ios::binary);
   if(!fp) {
       cout << "Cannot open file.";
       exit(0);
   }
   cout << "Enter characters (Enter to end:)\n";
   do {
      cin.get(ch);
      if(ch == '\n')
	  break;
      fp.put(ch);
   } while (1);
   fp.close();
   cout <<"Output from file :\n";
   ifstream fp1("test", ios::binary);
   fp1.get(ch);
   while(!fp1.eof()) {
       cout.put(ch);
       fp1.get(ch);
   }
   fp1.close();
   cout << "Output completed.";
   getch();
   return 0;
}
