#include <iostream.h>
#include <conio.h>
int main()
{
       int i,j ;
       clrscr();
       for(i = 1 ; i <= 10 ; i++) {
      	 for(j = 1 ; j <= 10 ; j++)
	          cout << i*j << "\t" ;
	       cout << endl ;
       }
       getch();
       return 0;
}