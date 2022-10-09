#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
   int disp, count ;
   clrscr();
   if(argc <= 2) {
      cout << "Number of parameter is wrong. usage: number display";
      getch();
      exit(0);
   }
   if(argc == 3 && !strcmp(argv[2], "display"))
     disp=1 ;
   else
     disp=0 ;
   for(count = atoi(argv[1]); count ; --count)
     if(disp)
	 cout << count << endl ;
   getch();
   return 0;
}


