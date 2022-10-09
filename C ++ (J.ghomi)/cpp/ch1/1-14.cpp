#include <iostream.h>
#include <conio.h>
int main()
{
  int len, wid, p, s;
  clrscr();
  cout << "Enter length , width :";
  cin >> len >> wid;
  p = (len + wid) * 2;
  s = len * wid;
  gotoxy(20, 10);
  cout << "s = " << s << " p = " << p;
  getch();
  return 0;
}

