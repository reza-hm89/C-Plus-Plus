#include <iostream.h>
#include <conio.h>
class loc{
   int longitude;
   int latitude;
 public:
   loc() { }; //needed to construct temporaries
   loc(int lg, int lt) {
      longitude = lg;
      latitude = lt;
   }
   void  show() {
      cout << longitude << "  ";
      cout << latitude << "\n";
   }
   loc operator+(loc op2);
   loc operator()(int i, int j);
};
//overload () for loc******
loc loc::operator() (int i, int j)
{
  longitude = i;
  latitude = j;
  return *this;
}

//**************
loc loc::operator+(loc op2)
{
   loc temp;
   temp.longitude = op2.longitude + longitude;
   temp.latitude = op2.latitude + latitude;
   return temp;
}
//**************
int main()
{
   clrscr();
   loc ob1(10, 20), ob2(1, 1);
   cout << "ob1 = ";
   ob1.show();
   ob1(7, 8); // can be excuted by itself
   cout << "ob1 = ";
   ob1.show();
   ob1 = ob2 + ob1(10, 10); //can be used in expression
   cout << "ob1 = ";
   ob1.show();
   getch();
   return 0;
}






