#include <iostream.h>
#include <conio.h>
//using a friend class
class twoValues {
   int a;
   int b;
  public:
   twoValues(int i, int j)
   {
     a = i;
     b = j;
   }
   friend class min;
};
//**************
class min {
   public:
     int findMin(twoValues x);
};
//**********************
int min::findMin(twoValues x)
{
  return x.a < x.b ? x.a : x.b;
}
//****************
int main()
{
  min m;
  twoValues ob(10, 20);
  clrscr();
  cout << "Min of 10, 20 is : " << m.findMin(ob);
  getch();
  return 0;
}



