#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
   char name[21];
   clrscr();
   ofstream  fp("test");
   if(!fp) {
       cout << "Cannot open file.";
       exit(0);
   }
   cout << "Enter names and ctrl + z to end:\n";
   while(1) {
       cin >> name;
       if(!name[0])
	   break;
       fp << name <<  ' ';
   }
   fp.close();
   ifstream fp1("test");    
   cout << "\nOutput from file is:\n";
   fp1 >> name;
   while(!fp1.eof()) {
       cout << name << endl;
       fp1 >> name;
   }
   fp1.close();
   getch();
   return 0;
}
