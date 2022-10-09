#include <iostream.h>
#include <conio.h>
void f1(int, int);
int main()
{
  int x, y;
  clrscr();
  cout << "Enter two integer numbers:";
  cin >> x >> y;
  cout << "You entered : x=" << x << ", y=" << y;
  f1(x, y);
  cout << "\nAfter return from f1 : x=" << x << ", y=" << y;
  getch();
  return 0;
}
//*********************
void f1(int x, int y)
{
  cout <<"\nf1 recieves : x=" << x << " , y=" << y;
  x ++;
  y ++;
  cout << "\nNew values in f1 : x=" << x << ", y=" << y;
}
