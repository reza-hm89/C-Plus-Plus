#include <iostream.h>
#include <conio.h>
class loc {
    int longitude;
    int latitude;
  public:
    loc() {}    //needed to construct temporaries
    loc(int lg, int lt) {
  	     longitude = lg;
	     latitude = lt;
    }
    void show() {
	     cout << longitude << "\t";
	     cout << latitude <<  endl;
    }
    loc operator+(loc op2);
    loc operator-(loc op2);
    loc operator=(loc op2);
    loc operator++();
};
//******************
//overload + for loc
loc loc::operator+(loc op2)
{
  loc temp;
  temp.longitude = op2.longitude + longitude;
  temp.latitude =  op2.latitude  + latitude;
  return temp;
}
//********** overload - for loc ***********
loc loc::operator-(loc op2)
{
  loc temp;
  //notice order of operand
  temp.longitude = longitude - op2.longitude;
  temp.latitude =  latitude -  op2.latitude ;
  return temp;
}
// overload assign for loc
loc loc::operator=(loc op2)
{
  longitude = op2.longitude;
  latitude =  op2.latitude ;
  return *this;  // return object that generated call
}
//******* overload prefix ++ for loc
loc loc::operator++()
{
  longitude ++;
  latitude  ++ ;
  return *this;     //return object that generated call
}
//**********************
int main()
{
  clrscr();
  loc ob1(10, 20), ob2(5, 30), ob3(90, 90);
  cout << "ob1=";
  ob1.show();       //display 10 , 20
  cout << "ob2=";
  ob2.show();       //display 5, 30
  ++ob1;
  cout << "ob1=";
  ob1.show();       //display 11 , 21
  ob2 = ++ob1;
  cout << "ob1=";
  ob1.show();       //display 12 , 22
  cout << "ob2=";
  ob2.show();       //display 12, 22
  ob1 = ob2 = ob3;  //multiple assignment
  cout << "ob1=";
  ob1.show();       //display 90, 90
  cout << "ob2=";
  ob2.show();       //display 90, 90
  getch();
  return 0;
}

