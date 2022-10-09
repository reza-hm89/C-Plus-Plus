#include <iostream.h>
#include <conio.h>
unsigned long fact(int) ;
int main()
{
    int m ;
    clrscr();
    cout << "\n enter a positive integers number:";
    cin >> m;
    cout << "\n number=" << m << " , fact=" << fact(m);
    getch();
    return 0;
}
//**********************
unsigned long fact(int x)
{
  if(x != 0)
    return(x * fact(x - 1)) ;
  return 1 ;
}

