#include <iostream.h>
#include <conio.h>
class shared {
    static int a;
    int b;
  public:
    void set(int i, int j) {a = i; b = j;}
    void show();
};
//******************
int shared::a;  //define a

void shared::show()
{
 cout << "This is static a:" << a << endl;
 cout << "This is non-static b:" << b << endl;
}
//*****************
int main()
{
  shared x, y;
  clrscr();
  x.set(1 , 1); //set a to 1
  x.show();
  y.set(2 , 2); //change a to 2
  y.show();
  x.show(); //here, a has been changed for both
	    // x and y, because a is shared by both object
  getch();
  return 0;
}



