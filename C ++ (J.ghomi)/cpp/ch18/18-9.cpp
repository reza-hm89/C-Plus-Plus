#include <stdio.h>
#include <conio.h>
#define TEN 10
int main()
{
    clrscr();
    #ifdef TEN
      printf("\n TEN defined.");
    #else
      printf("\n TEN not defined.");
    #endif
    #ifndef ALPHA
     printf("\n ALPHA is not defined.");
    #endif
    getch();
    return 0;
}

