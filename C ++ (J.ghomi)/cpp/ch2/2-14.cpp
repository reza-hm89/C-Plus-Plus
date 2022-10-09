#include <iostream.h>
#include <conio.h>
int main()
{
  int num, count = 0, n = 0;
  clrscr();
  while(1){
     cout << "Enter a number:";
     cin >> num;
     if(num == 0)
     	 break;
     n ++;
     if(num % 2 == 0)
	    count ++;
  }
  cout << "\n events=" << count << " odds = " << (n - count);
  getch();
  return 0;
}





