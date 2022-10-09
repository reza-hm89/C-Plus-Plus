#include <iostream.h>
#include <conio.h>
#include <string.h>
int main()
{
   union {   //define anonymous union
       long x;
       double d;
       char s[4];
   };
   clrscr();
   //now, reference union elements directly
   x = 100000;
   cout << x << " ";
   d = 123.2342;
   cout << d << "  ";
   strcpy(s, "Hi!");
   cout << s;
   getch();
   return 0;
}
