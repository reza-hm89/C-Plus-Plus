#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
struct employee {
      char name[21];
      int hour;
      int hp;
} emp;

int main()
{
   clrscr();
   int row = 3;
   ofstream  fp("emp.dat", ios::out | ios::binary);
   if(!fp) {
       cout << "Cannot open file.";
       exit(0);
   }
   cout << "Name               "
	<< "Hour      "
	<< "Hour pay";
   cout << "\n-------------------------------";
   while(1) {
       gotoxy(1, row);
       cin >> emp.name;
       if(!emp.name[0])
	   break;
       gotoxy(20, row);
       cin >> emp.hour ;
       gotoxy(30, row);
       cin >> emp.hp ;
       fp.write((char *) &emp, sizeof(struct employee));
       row ++;
   }
   fp.close();
   cout << "Press a key to see output..." ;
   getch();
   ifstream  fp1("emp.dat", ios::in | ios::binary);
   if(!fp1) {
       cout << "Cannot open file.";
       getch();
       exit(0);
   }
   clrscr();
   cout << "Name               "
	<< "Hour      "
	<< "Hour pay     Salary";
   cout << "\n--------------------------------------------";
   row = 3;
   while(fp1.read((char *) &emp, sizeof(struct employee))) {
       gotoxy(1, row);
       cout << emp.name;
       gotoxy(20, row);
       cout << emp.hour;
       gotoxy(30, row);
       cout << emp.hp ;
       gotoxy(45, row);
       cout << emp.hour * emp.hp;
       row ++;
   }
   fp1.close();
   getch();
   return 0;
}
