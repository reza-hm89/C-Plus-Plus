#include <iostream.h>
#include <conio.h>
int main()
{
  clrscr();
  cout.setf(ios::uppercase | ios::scientific);
  cout << 100.12;
  cout.unsetf(ios::uppercase);
  cout << "\n" << 100.12;
  getch();
  return 0;
}
