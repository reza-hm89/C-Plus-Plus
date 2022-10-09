#include <iostream.h>
#include <conio.h>
void xhandler(int test) throw (int, char, double)
{
  if(test == 0) throw test;
  if(test == 1) throw 'a';
  if(test == 2) throw 123.23;
}
//*************
int main()
{
   cout << "Start:\n";
   try {
      xhandler(2);
   }
   catch(int i) {
      cout << "Caught an integer : " << i << "\n";
   }
   catch(char c) {
      cout << "Caught  char :" << c << "\n";
   }
   catch(double d) {
      cout << "Caught  double : " << d << "\n";
   }
   cout << "End.";
   getch();
   return 0;
}

