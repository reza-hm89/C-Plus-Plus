#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
   char name[21];
   int stno;
   float ave;
   clrscr();
   ofstream  fp("test");
   if(!fp) {
       cout << "cannot open file.";
       getch();
       exit(0);
   }
   cout << "Enter name stno ave (ctrl + z to end:)\n";
   while( cin >> name >> stno >> ave) {
       fp << name <<  ' ' << stno << ' ' << ave << ' ';
   }
   fp.close();
   int row = 3 ;
   float s = 0, c = 0;
   clrscr();
   ifstream  fp1("test");
   if(!fp1) {
       cout << "Cannot open file.";
       getch();
       exit(0);
   }
   cout << "Name               "
	<< "Stno      "
	<< "Average";
   cout << "\n-------------------------------";
   while( fp1 >> name >> stno >> ave) {
       gotoxy(1, row);
       cout << name;
       gotoxy(20, row);
       cout << stno ;
       gotoxy(30, row);
       cout << ave ;
       s += ave;
       c ++;
       row ++;
   }
   fp.close();
   cout << "\n-------------------------------";
   cout << "\nAverage of class is : " << s / c;
   getch();
   return 0;
}
