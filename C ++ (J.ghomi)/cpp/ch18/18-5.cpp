#include<stdio.h>
#include <conio.h>
#include "ar.h"
int main()
{
   int base, height;
   float s;
   clrscr();
   base = 10;
   height = 15;
   s = AREA_TRIANGLE(base, height);
   printf("%6.2f",s);
   getch();
   return 0;
}

