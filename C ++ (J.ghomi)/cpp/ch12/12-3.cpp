#include <iostream.h>
#include <conio.h>
//overriding a template function.
template <class X> void swapArgs(X &a, X &b)
{
   X temp;
   temp = a;
   a = b;
   b = temp;
   cout << "Inside template swapArgs\n";
}
//this overrides the generic version of swapargs()
void swapArgs(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
   cout << "Inside swapArgs specialization\n";
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
   swapArgs(i, j); //calls explicity overloaded swapArgs()
   swapArgs(x, y); //calls generic swapaegs
   swapArgs(a, b); //calls generic swapargs
   cout << "Swaped i, j : " << i << " , " << j << "\n";
   cout << "Swaped x, y : " << x << " , " << y << "\n";
   cout << "Swaped a, b : " << a << " , " << b << "\n";
   getch();
   return 0;
}




