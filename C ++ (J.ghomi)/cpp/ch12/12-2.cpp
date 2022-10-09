#include <iostream.h>
#include <conio.h>
template <class type1, class type2>
void myFunc(type1 x, type2 y)
{
  cout << "x = " << x << " , y = " << y << endl;
}
//***********
int main()
{
   clrscr();
   myFunc(10, "I like C++");
   myFunc(89.25, 19L);
   getch();
   return 0;
}
