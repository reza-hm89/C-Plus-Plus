#include <iostream.h>
#include <conio.h>
void write_v(int);
int main()
{
  int x;
  clrscr();
  cout << "enter an integer number:";
  cin >> x;
  write_v(x);
  getch();
  return 0;
}
//*****************
void write_v(int x)
{
  if (x < 10)
     cout << x << endl;
  else {
     write_v(x / 10);
     cout << x % 10 << endl;
  }
}




