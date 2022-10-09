#include <iostream.h>
#include <conio.h>
class test {
    public:
       test(int x) { val = x; }
       int sumVal() { return val + val; }
       int val;
};
//*****************
int main()
{
  int test::*data;       //data menber pointer
  int (test::*func)();  //function member pointer
  clrscr();
  test ob1(5), ob2(16);        //create object
  data = &test::val;    //get offset of val
  func = &test::sumVal;//get offset of sumval()
  cout << "Here are values: ";
  cout << ob1.*data << " " << ob2.*data << "\n";
  cout << "Here are thier sum :";
  cout << (ob1.*func)() << " ";
  cout << (ob2.*func)() << "\n";
  getch();
  return 0;
}


