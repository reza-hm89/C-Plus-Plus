#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
   char ch;
   clrscr();
   ofstream  fp("test.dat");
   if(!fp) {
       cout << "Cannot open file.";
       exit(0);
   }
   cout << "Enter characters ($ and Enter to end:)\n";
   do {
      cin.get(ch);
      fp.put(ch);
   } while (ch != '$');
   fp.close();
   cout <<"Output from file :\n";
   ifstream fp1("test.dat");
   fp1.get(ch);
   while(!fp1.eof()) {
       cout.put(ch);
       fp1.get(ch);
   }
   fp1.close();
   cout << "\nOutput completed";
   getch();
   return 0;
}
