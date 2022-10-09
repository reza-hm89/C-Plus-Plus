#include <iostream.h>
#include <conio.h>
void xhandler(int test)
{
  try {
     if(test) throw test;
     else  throw "Value is zero";
  }
  catch (int i) {
      cout << "\nCaught exception #: " << i << "\n";
  }
  catch(const char *str) {
     cout << "Caught a string: ";
     cout << str << "\n";
  }
}
//*************
int main()
{
  cout << "Strat:";
  xhandler(1);
  xhandler(2);
  xhandler(0);
  xhandler(3);
  cout << "End.";
  getch();
  return 0;
}
