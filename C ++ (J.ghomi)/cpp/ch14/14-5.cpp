#include <iostream.h>
#include <conio.h>
void xhandler(int test)
{
  try{
      if(test == 0) throw test;
      if(test == 1) throw 'a';
      if(test == 2) throw 123.23;
   }
   catch(int i) {
      cout << "Caught an integer :" << i << "\n";
   }
   catch(...) {
      cout << "Caught one!\n";
   }
}
//*************
int main()
{
   cout << "Start:";
   xhandler(0);
   xhandler(1);
   xhandler(2);
   cout << "End.";
   getch();
   return 0;
}

