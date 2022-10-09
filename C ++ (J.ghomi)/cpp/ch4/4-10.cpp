#include <iostream.h>
#include <conio.h>
#include <string.h>
int main()
{
   char string[81] ;
   int position ;
   clrscr();
   cout << "Type a string :" ;
   cin.get(string, 80) ;
   cout << "Enter position for delete character :" ;
   cin >> position ;
   strcpy(&string[position], &string[position + 1]) ;
   cout << "The result string is: " << string ;
   getch();
   return 0;
}

