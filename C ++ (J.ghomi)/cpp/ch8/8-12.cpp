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
   loc operator,(loc op2);
};
// + is overloded for loc ******
loc loc::operator+(loc op2)
{
   loc temp;
   temp.longitude = op2.longitude +longitude;
   temp.latitude =  op2.latitude + latitude;
   return temp;
}
//** oveload ,  for loc **************
loc loc::operator,(loc op2)
{
   loc temp;
   temp.longitude = op2.longitude;
   temp.latitude  = op2.latitude;
   cout << op2.longitude << "  " << op2.latitude << endl;
   return temp;
}
//****************
int main()
{
   clrscr();
   loc ob1(10, 20), ob2(5, 30), ob3(1, 1);
   cout << "ob1 = ";
   ob1.show();
   cout << "ob2 = ";
   ob2.show();
   cout << "ob3 = ";
   ob3.show();
   ob1 = (ob1, ob2 + ob2, ob3);
   cout << "ob1 = ";
   ob1.show();     //display 1  1 , the value of ob3
   getch();
   return 0;
}
