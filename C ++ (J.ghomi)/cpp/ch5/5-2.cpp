#include <iostream.h>
#include <conio.h>
void input(int *, int *);
void rect(int, int, int *, int *);
int main()
{
  int len, wid, area, per;
  clrscr();
  input(&len, &wid);
  rect(len, wid, &area, &per);
  cout << " Length = " << len  << " , Width = " <<  wid;
  cout << "\n Area = " << area << " , Perimer = " <<  per;
  getch();
  return 0;
}
//**************************
void input(int *p1, int *p2)
{
  cout << " Enter length, width :";
  cin >> *p1  >> *p2;
}
//***************************
void rect(int x, int y, int *a, int *p)
{
  *a = x * y;
  *p = 2 * (x + y);
}

