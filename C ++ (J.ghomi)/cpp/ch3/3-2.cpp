#include <iostream.h>
#include <conio.h>
void findMax(int, int, int);
int main()
{
  int x, y, m;
  clrscr();
  cout << "\nEnter three integer numbers:";
  cin >> x >> y >> m;
  findMax(x, y, m);
  return 0;
}
//*********************
void findMax(int p1, int p2, int p3)
{
  int maxp;
  maxp = (p1 > p2) ? p1 : p2;
  maxp = (p3 > maxp) ? p3 : maxp;
  cout << "\maximum=" << maxp;
  getch();
}

