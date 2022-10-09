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
     int j;
  public:
     //derived uses x. y is pased along to base
     derived(int x, int y, int z) : base1(y), base2(z) {
       j = x;
       cout << "Constructing derived\n";
     }
     ~derived() { cout << "Destructing derived\n"; }
     void show() {
	cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
     }
};
//*****************
int main()
{
  clrscr();
  derived ob(3, 4, 5);
  ob.show();   //display 4, 3, 5
  getch();
  return 0;
}





