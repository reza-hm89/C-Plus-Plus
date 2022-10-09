#include <iostream.h>
#include <conio.h>
class loc{
   int longitude;
   int latitude;
 public:
   loc() { }; //neded to construct temporaries
   loc(int lg, int lt) {
      longitude = lg;
      latitude = lt;
   }
   void  show() {
      cout << longitude << "  ";
      cout << latitude << "\n";
   }
   friend loc operator+(loc op1, loc op2); // afriend operator
   loc operator-(loc op2);
   loc operator=(loc op2);
   loc operator++();
};
//* + is overloded using friend function ******
loc operator+(loc op1, loc op2)
{
   loc temp;
   temp.longitude = op1.longitude + op2.longitude;
   temp.latitude = op1.latitude + op2.latitude;
   return temp;
}
//** oveload -  for load **************
loc loc::operator-(loc op2)
{
   loc temp;
   temp.longitude = longitude + op2.longitude;
   temp.latitude  = latitude + op2.latitude;
   return temp;
}
//****************
loc loc::operator=(loc op2)
{
   loc temp;
   longitude = op2.longitude;
   latitude  = op2.latitude;
   return *this; //return object that generated call
}
//*************
loc loc::operator++()
{
   loc temp;
   longitude ++;
   latitude  ++;
   return *this;
}
//**************
int main()
{
   clrscr();
   loc ob1(10, 20), ob2(5, 30);
   cout << "bo1 + ob2 = ";
   ob1 = ob1 + ob2;
   ob1.show();
   ++ ob1;
   cout << "++ ob1 = ";
   ob1.show();
   getch();
   return 0;
}






