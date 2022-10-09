#include <iostream.h>
#include <conio.h>
class rect {
      int  len;
      int  width;
    public:
      int  area;
      int  perime;
      void input();
      void calculate();
};
//*************
void rect::calculate()
{
    area = len * width ;
    perime = 2 * (len + width);
}
//**************
void rect::input()
{
  cout << "Enter length, width :";
  cin  >> len >> width ;
}
//*****************
int main()
{
  clrscr();
  rect rAngle;
  rAngle.input();
  rAngle.calculate();
  cout << "Area = " << rAngle.area << " , Perime = " << rAngle.perime;
  getch();
  return 0;
}

