#include <iostream.h>
#include <conio.h>
//first version of f() template
template <class X> void f(X a)
{
  cout << "Inside f(X a), a is " << a <<  "\n";
}
//***************
//second version of f() template
template <class X, class Y> void f(X a, Y b)
{
   cout << "Inside f(X a, Y b) , a is " << a << ", b is " << b << "\n";
}
//************
int main()
{
  clrscr();
  f(10);       //calls f(X)
  f(10, 20);   //calls f(X, Y)
  getch();
  return 0;
}
