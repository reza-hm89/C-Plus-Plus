#include <iostream.h>
#include <conio.h>
int main()
{
     int x , *p , **q ;
     clrscr();
     x = 10 ;
     p = &x ;
     q = &p ;
     cout << "\n The q points to value:" << **q ;
     getch();
     return 0;
}







