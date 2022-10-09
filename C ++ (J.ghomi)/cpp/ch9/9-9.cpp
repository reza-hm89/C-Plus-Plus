#include <fstream.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct student {
      char name[21];
      int stno;
      float ave;
} st;
int main()
{
   clrscr();
   int no, row = 3;
   ofstream  fp("student.dat", ios::out | ios::binary);
   if(!fp) {
       cout << "Cannot open file.";

       exit(0);
   }
   cout << "Name               "
	<< "Stno      "
	<< "Average";
   cout << "\n-------------------------------";
   while(1) {
       gotoxy(1, row);
       cin.get(st.name, 20);
       if(!st.name[0])
	   break;
       gotoxy(20, row);
       cin >> st.stno ;
       gotoxy(30, row);
       cin >> st.ave ;
       cin.get(); //for discard end of line from keybord buffer
       fp.write((char *) &st, sizeof(struct student));
       row ++;
   }
   fp.close();
   cout << "Press a key to continue..." ;
   getch();
   clrscr();
   ifstream in ("student.dat", ios::in | ios::binary);
   ofstream out("temp.dat", ios::out | ios::binary);
   if(!in && !out) {
       cout << "Cannot open file.";
       getch();
       exit(0);
   }
   cout << "Enter stno to search:";
   cin >> no;
   row = 6;
   while(in.read((char *) &st, sizeof(struct student))) {
       if ( st.stno == no) {
	   cout << "\nEnter new information for this student:\n";
	   cout << "Name               "
		<< "Stno      "
		<< "Average";
	   cout << "\n-------------------------------\n";
      row ++;
	   gotoxy(1, row);
	   cin >> st.name;
	   gotoxy(20, row);
	   cin >> st.stno ;
	   gotoxy(30, row);
	   cin >> st.ave ;
       } //end of if
       out.write((char *) &st, sizeof(struct student));
   }//end of while
   in.close();
   out.close();
   remove("student.dat");
   rename("temp.dat", "student.dat");
   cout << "Press a key to see new content of file ...";
   getch();
   clrscr();
   row = 3;
   ifstream temp("student.dat", ios::out | ios::binary);
      cout << "Name               "
	<< "Stno      "
	<< "Average";
   cout << "\n-------------------------------";
   while(temp.read((char *) &st, sizeof(struct student))) {
       gotoxy(1, row);
       cout << st.name;
       gotoxy(20, row);
       cout << st.stno ;
       gotoxy(30, row);
       cout << st.ave;
       row ++;
   }
   getch();
   return 0;
}
