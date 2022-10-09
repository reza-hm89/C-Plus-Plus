#include "stdio.h"
#include <conio.h>
#define MAX 100
int main()
{
   #if MAX > 90
     printf("compiled for array greater than 99\n");
   #endif
   getch();
   return 0;
}
