#include <iostream.h>
#include <conio.h>
void neg(int &i); // i is a reference
int main()
{
  int x;
  clrscr();
  x = 10;
  cout << x << " negated is ";
  neg(x); // no longer need the & operator
  cout << x << endl;
  getch();
  return 0;
}
//*************
void neg(int &i)
{
  i = -i; // i is now a reference, don't need *
}


