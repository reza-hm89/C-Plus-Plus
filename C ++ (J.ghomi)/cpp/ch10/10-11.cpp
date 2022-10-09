#include <iostream.h>
#include <conio.h>
class base1 {
  protected:
     int i;
  public:
     base1(int x) {
       i = x;
       cout << "Constructing base1\n";
     }
     ~base1 () { cout << "Destructing base1\n"; }
};
//****************
class base2 {
   protected:
     int k;
   public:
     base2(int x) {
	k = x;
	cout << "Constructing base2\n";
     }
     ~base2 () { cout << "Destructing base2\n"; }
};
//*****************
class derived: public base1 , public base2 {
  public:
     //derived constructor uses no parameter,
     //but still must be declared as taking them to
     //pass them along to base class
     derived(int x, int y) : base1(x), base2(y) {
       cout << "Constructing derived\n";
     }
     ~derived() { cout << "Destructing derived\n"; }
     void show() {
	cout << "i = " << i << ", k = " << k << endl;
     }
};
//*****************
int main()
{
  clrscr();
  derived ob(3, 4);
  ob.show();   //display 3, 4
  getch();
  return 0;
}





