#include <iostream.h>
#include <conio.h>
class pwr {
    double b;
    int e;
    double val;
  public:
    pwr() { val = 1; }
    void input();
    void power();
    double get_pwr() { return val ; }
};
//**********************
void pwr::input()
{
   cout << "Enter base, power:";
   cin >> b >> e;
}
//******************
void pwr::power()
{
  for(; e > 0; e --)
      this -> val = this -> val * this -> b;
}
//*****************
int main()
{
   clrscr();
   pwr x;
   x.input();
   x.power();
   cout << "Porwer=" << x.get_pwr() << "  ";
   getch();
   return 0;
}
