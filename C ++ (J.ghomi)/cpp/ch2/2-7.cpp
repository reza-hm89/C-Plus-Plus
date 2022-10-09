#include <iostream.h>
#include <conio.h>
int main()
{
    int count = 0 ;
    clrscr();
    cout << "Type a statement and ENTER to end:";
    while(cin.get() != '\n')
       count ++ ;
    cout << "Length of statement is : " << count ;
    getch();
    return 0;
}

