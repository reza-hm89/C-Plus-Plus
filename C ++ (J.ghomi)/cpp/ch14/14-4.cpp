#include <iostream.h>
#include <conio.h>
class b
{
};
//***************
class d : public b
{
};
//***************
int main()
{
   d derived;
   try {
      throw derived;
   }
   catch (b b1) {
       cout << "Caught a base class.\n";
   }
   catch (d d1) {
      cout << "This won't excecute.\n";
   }
   getch();
   return 0;
}

