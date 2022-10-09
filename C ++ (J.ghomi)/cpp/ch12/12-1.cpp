#include <iostream.h>
#include <conio.h>
//this is a function template.
template <class X> void swapArgs(X &a, X &b)
{
   X temp;
   temp = a;
   a = b;
   b = temp;
}
//***************
int main()
{
   int i = 10, j = 20;
   double x = 10.1,  y = 23.3;
   char a = 'x', b = 'z';
   clrscr();
   cout << "Original i, j : " << i << " , " << j << "\n";
   cout << "Original x, y : " << x << " , " << y << "\n";
   cout << "Original a, b : " << a << " , " << b << "\n";
   swapArgs(i, j); //swap integers
   swapArgs(x, y); //swap doubles
   swapArgs(a, b); //swap characters
   cout << "Swaped i, j : " << i << " , " << j << "\n";
   cout << "Swaped x, y : " << x << " , " << y << "\n";
   cout << "Swaped a, b : " << a << " , " << b << "\n";
   getch();
   return 0;
}



