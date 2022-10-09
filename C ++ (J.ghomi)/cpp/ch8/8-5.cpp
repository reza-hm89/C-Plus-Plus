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
   loc operator=(loc op2);
   friend loc operator++(loc &op);
   friend loc operator--(loc &op);
};
//****************
loc loc::operator=(loc op2)
{
   longitude = op2.longitude;
   latitude  = op2.latitude;
   return *this; //return object that generated call
}
//*************
loc operator++(loc &op)
{
   op.longitude ++;
   op.latitude  ++;
   return op;
}
//**************
//*************
loc operator--(loc &op)
{
   op.longitude --;
   op.latitude  --;
   return op;
}
//*****************
int main()
{
   clrscr();
   loc ob1(10, 20), ob2;
   cout << "ob1 = ";
   ob1.show();
   ++ ob1;
   cout << "++ ob1 = ";
   ob1.show();
   ob2 = ++ob1;
   cout << "ob2 = ";
   ob2.show();
   --ob2;
   cout << "-- ob2 = ";
   ob2.show();
   getch();
   return 0;
}






