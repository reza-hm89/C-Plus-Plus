#include <iostream.h>
#include <conio.h>
int main()
{
  int i;
  char ch;
  clrscr();
  for(i = 41; i <= 120; i++) {
     ch = i;
     cout << i << " = " << " " << ch << "  ";
     if(i % 5 == 0)
	 cout << "\n";
  }//end of for
  getch();
  return 0;
}
