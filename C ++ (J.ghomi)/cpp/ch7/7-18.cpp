#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class emp {
    char name[21];
    int h;
    int hp;
 public:
    void input();
    void output();
};
//**************
void emp::input()
{
   static int row = 3;
   gotoxy(1, row);
   cin >> name;
   gotoxy(23, row);
   cin >> h;
   gotoxy(30, row);
   cin >> hp;
   row ++;
}
//*************************
void emp::output()
{
   static int row = 2;
   gotoxy(1, row);
   cout << name;
   gotoxy(20, row);
   cout << h * hp;
   row ++;
}
//*************************
int main()
{
   int n, i;
   clrscr();
   cout << "Enter number of employees:";
   cin >> n;
   emp *p;
   p = new emp[n];
   if(!p) {
	cout << "Allocation failure. press a key...";
	getch();
	exit(0);
   }
  cout << "Name                  Hour"  << "  Hourpay ";
   for(i = 0; i < n; i ++)
      p[i].input();
  cout << "Press a key to continue..";
  getch();
  clrscr();
  cout << "Name              Salary";
  for(i = 0; i < n; i++)
      p[i].output();
  getch();
  return 0;
}

