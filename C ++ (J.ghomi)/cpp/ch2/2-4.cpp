#include <iostream.h>
#include <conio.h>
int main()
{
   int count;
   clrscr();
   cout << "Enter a statement with (.) Enter in end:" << endl ;
   for(count = 0; cin.get() != '.' ; count++);
   cout << "Length of statement is: " << count ;
   getch();
   return 0;
}


