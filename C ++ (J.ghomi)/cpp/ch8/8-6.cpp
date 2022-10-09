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
   friend loc operator+(loc op1, int op2); // a friend operator
   friend loc operator+(int op1, loc op2); // a friend operator
};
//* + is overloded for loc + int ******
loc operator+(loc op1, int op2)
{
   loc temp;
   temp.longitude = op1.longitude + op2;
   temp.latitude  = op1.latitude + op2;
   return temp;
}
//***************
loc operator+(int op1, loc op2)
{
   loc temp;
   temp.longitude = op1 + op2.longitude;
   temp.latitude  = op1 + op2.latitude;
   return temp;
}

//****************
int main()
{
   clrscr();
   loc ob1(10, 20), ob2(5, 30), ob3(7, 14);
   cout << "ob1 = ";
   ob1.show();
   cout << "ob2 = ";
   ob2.show();
   cout << "ob3 = ";
   ob3.show();
   ob1 = ob2 + 10;
   ob3 = 10 + ob2;
   cout << "ob1 = ob2 + 10 = ";
   ob1.show();
   cout << "ob3 = 10 + ob2 = ";
   ob3.show();
   getch();
   return 0;
}

