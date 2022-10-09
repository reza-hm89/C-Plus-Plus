#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5
int   menu();
int   findSlot();
void  search();
void  del();
void  findMax();
void  report();
class student {
     char  name[21];
     int   stno;
     float ave;
   public:
     student() { name[0] = '\0'; }
     void  enter();
     char  getState();
     int   getStno() { return stno; }
     void  print(int &);
     void  seNul() { name[0] = '\0'; }
     float getAve() { return ave; }
};
//*************************
student st[SIZE];
char student::getState()
{
  return name[0];
}
//********************
void student::enter()
{
  clrscr();
  cout << "Name               " << " Stno " << "   Average" << endl;
  cin >> name;
  gotoxy(22, 2);
  cin >> stno;
  gotoxy(30, 2);
  cin >> ave;
}
//*****************
void student::print(int& row)
{
   gotoxy(1, row);
   cout << name;
   gotoxy(22, row);
   cout << stno;
   gotoxy(30, row);
   cout << ave;
   row ++;
}
//******************
int main()
{
   int i, c;
   for(;;) {
      clrscr();
      c = menu();
      switch (c) {
	     case 1 :
	        i = findSlot();
	        if(i == -1) {
		        cout << "\n List is full. press a key...";
		        getch();
	        } //end of if
	        else
		        st[i].enter();
	        break;
	     case 2 :
	        findMax();
	        break;
	     case 3 :
	        del();
	        break;
	     case 4 :
	        search();
	        break;
	     case 5 :
	        report();
	        break;
	     case 6 :
	        exit(0) ;
      } // end of switch
   } //end of for(;;)
}
//*************************
int menu()
{
  int c;
  gotoxy(5, 5);
  cout << "1) Enter a student.";
  gotoxy(5, 6);
  cout << "2) Find best student.";
  gotoxy(5, 7);
  cout << "3) Delete a student.";
  gotoxy(5, 8);
  cout << "4) Search a student.";
  gotoxy(5, 9);
  cout << "5) Report list.";
  gotoxy(5, 10);
  cout << "6) Exit.";
  do {
     gotoxy(5, 12);
     cout << "Enter your select(1-6) : ";
     cin >> c;
  } while (c < 1 && c > 6);
  return c;
}
//********************
int findSlot()
{
  int slot;
  for(slot = 0; slot < SIZE && st[slot].getState(); slot ++);
  if(slot == SIZE)
     return -1;
  return slot;
}
//**********************************
void findMax()
{
   int i, p = 0, row = 2;
   float mAve = st[0].getAve();
   for(i = 1; i < SIZE; i++)
     if(st[i].getAve() > mAve) {
	  mAve =  st[i].getAve();
	  p = i;
     }
    gotoxy(1, 1);
    cout << "name               " << " stno "
	      << "   average" << endl;
    st[p].print(row);
    getch();
}
//************************
void del()
{
   int i, no;
   cout << "\nEnter stno to delete :";
   cin >> no;
   for(i = 0; i < SIZE && st[i].getStno() != no  ; i ++);
   if(i == SIZE || !st[i].getState()) {
	 cout << "Student " << no << " not exist."
	      << "Press a key to continue...";
   }
   else {
       st[i].seNul();
       cout << "student " << no << " dleted.";
   }
   getch();
}
//****************
void search()
{
   int i, no, row = 2;
   cout << "\nEnter stno to search :";
   cin >> no;
   for(i = 0; i < SIZE && st[i].getStno() != no ; i ++);
   if(i == SIZE) {
	 cout << "Student " << no << " not exist."
	      << "Press a key to continue...";
   }
   else {
      gotoxy(1, 1);
      cout << "Name               " << " Stno "
	   << "   Average" << endl;
      st[i].print(row);
   }
   getch();
}
//********************
void report()
{
  int i, row = 2;
  clrscr();
  cout << "Name               " << " Stno "
      << "   Average" << endl;
  for(i = 0; i < SIZE; i ++) {
    if(st[i].getState())
       st[i].print(row);
  }
  getch();
}




