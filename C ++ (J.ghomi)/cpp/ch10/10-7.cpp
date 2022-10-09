#include <iostream.h>
#include <conio.h>
class base {
  protected:
     int i;
  public:
     base(int x)
     {
       i = x;
       cout << "Constructing base\n";
     }
};
//****************
class derived: public base {
     int j;
  public:
     //derived uses x. y is pased along to base
     derived(int x, int y) : base(y)
     {
       j = x;
       cout << "Constructing derived\n";
     }
     ~derived() { cout << "Destructing derived\n"; }
     void show() { cout << "i = " << i << ", j = " << j << endl; }
};
//*****************
int main()
{
  clrscr();
  derived ob(3, 4);
  ob.show();   //display 4, 3
  getch();
  return 0;
}



