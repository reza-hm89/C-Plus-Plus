#include <stdio.h>
#include <conio.h>
#define LEN 100
#define WIDTH 100
int main()
{
    char array[LEN][WIDTH];
    clrscr();
    #undef LEN
    #undef WIDTH
    #ifndef LEN
      printf("LEN deleted.");
    #endif
    getch();
    return 0;
}

