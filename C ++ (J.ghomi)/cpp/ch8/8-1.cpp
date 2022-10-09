#include <iostream.h>
#include <conio.h>
class loc {
    int longitude;
    int latitude;
  public:
    loc() {}
    loc(int lg, int lt) {
	longitude = lg;
	latitude = lt;
    }
    void show() {
	 cout << longitude << "\t";
	 cout << latitude <<  endl;
    }
    loc operator+(loc op2);
};
//******************
loc loc::operator+(loc op2)
{
  loc temp;
  temp.longitude = op2.longitude + longitude;
  temp.latitude =  op2.latitude  + latitude;
  return temp;
}
//**********************
int main()
{
  clrscr();
  loc ob1(10, 20), ob2(5, 30);
  cout << "ob1=";
  ob1.show();   //display 10 , 20
  cout << "ob2=";
  ob2.show();   //display 5, 30
  ob1 = ob1 + ob2;
  cout << "ob1 + ob2=";
  ob1.show(); // display 15 50
  getch();
  return 0;
}

