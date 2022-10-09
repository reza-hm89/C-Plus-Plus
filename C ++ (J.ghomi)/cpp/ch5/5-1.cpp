#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
int main()
{
  int *x, *y, s;
  clrscr();
  x = new int;
  if(!x) {
     cout << "\n Allocation failure.";
     exit(1);
  }
  y = new int;
  if(!y){
     cout << "\n Allocation failure.";
     exit(1);
  }
  cout << "\n Enter two integers:";
  cin >> *x >>  *y;
  s = *x * *x + *y * *y;
  cout << "\n Sum of square is:" << s;
  delete x;
  delete y;
  getch();
  return 0;
}

