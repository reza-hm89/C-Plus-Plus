#include <iostream.h>
#include <conio.h>
int main()
{
  cout << "Start\n";
  try {
     cout << "Inside the try block\n";
     throw 100;   //throw an error
     cout << "This will not execute";
  }
  catch(double i) { // won't work for an int exception
     cout << "Caught an exception -- value is :";
     cout << i << "\n";
  }
  cout << "end.";
  getch();
  return 0;
}

