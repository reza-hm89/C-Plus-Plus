#include <iostream.h>
#include <conio.h>
int x;
void func1(void);
void func2(void);
int main()
{
   clrscr();
   x = 100;
   func1();
   func2();
   cout << "\n In main x is : "  << x;
   getch();
   return 0;
}
//*********************
void func1(void)
{
  cout << "\n In func1 x is:" << x;
}
//*********************
void func2(void)
{
  int x ;
  cout << "\n In func2 x changes:";
  for(x = 1; x < 6; x ++)
    cout << "  x=" << x ;
  cout << "\n Global x in func2 is : " << ::x ;
}


