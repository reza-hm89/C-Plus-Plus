#include <iostream.h>
#include <conio.h>
int main()
{
  int a;
  int &ref = a; //independent reference
  clrscr();
  a = 10;
  cout << a << "  " << ref << endl;
  ref = 100;
  cout << a << "  " << ref << endl;
  int b = 19;
  ref = b; // this puts b's value into a
  cout << a << "  " << ref << endl;
  ref --; //decrement a . it does not affect what ref refers to
  cout << a << "  " << ref << endl;
  getch();
  return 0;
}


