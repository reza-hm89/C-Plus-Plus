#include <stdio.h>
#include <conio.h>
int main ()
{
    int arr[4] , i ;
    clrscr();
    for (i=0 ; i < 100 ; i++) {
      if ( i > 4 )
	 #error enter less than 20 ;
      else
	 scanf("%d",&arr[i]) ;
      getch();
      return 0;
}

