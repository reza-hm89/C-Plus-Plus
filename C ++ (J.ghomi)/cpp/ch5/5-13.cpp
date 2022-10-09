#include <iostream.h>
#include <conio.h>
int main()
{
    int s[80], y[80] ;
    int *p1, *p2 ;
    clrscr();
    p1 = s ;
    p2 = y ;
    cout << "\n p1 is" << p1 << ", p2 is" << p2 ;
    cout << "\n p1 points to lower address?" ;
    getch();
    return 0 ;
}

