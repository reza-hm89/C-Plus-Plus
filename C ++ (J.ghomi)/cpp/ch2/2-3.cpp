#include <iostream.h>
#include <conio.h>
int main()
{
   char ch;
   int code;
   clrscr();
   for(ch = 'a'; ch <= 'f'; ch ++) {
      code = ch;
      cout  << "ch = " << ch << "  code = " << code << endl;
   }
   getch();
   return 0;
}


