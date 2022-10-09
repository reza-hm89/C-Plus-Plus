#include <iostream.h>
#include <conio.h>
const int TABWIDTH = 8;
//display data at specific tab position
template <class X> void tabOut(X data, int tab)
{
   for(; tab; tab --)
      for(int i= 0; i < TABWIDTH; i ++)
	   cout << ' ';
      cout << data << "\n";
}
//************
int main()
{
  clrscr();
  tabOut("This is a test", 0);
  tabOut(100, 1);
  tabOut('x', 2);
  tabOut(10/3, 3);
  getch();
  return 0;
}
