#include <iostream.h>
#include <conio.h>
class convert {
  protected:
    double val1;  //initial value
    double val2;  //converted value
  public:
    convert(double i) {
       val1 = i;
    }
    double getConv() { return val2; }
    double getInit()  { return val1; }
    virtual void compute () = 0;
};
//**************
class kToG : public convert {
   public:
   kToG(double i) : convert(i) {}
   void compute() {
      val2 = val1 * 1000;
   }
};
//farenheit to celsius
class change : public convert {
  public:
     change(double i) : convert(i) {}
     void compute() {
       val2 = (val1 - 32) / 1.8;
     }
};
//**************
int main()
{
   convert *p;   //pointer to base class
   clrscr();
   kToG    p1(4);
   change  p2(73);
   //use virtual function mechanism to convert
   p = &p2;
   cout << p -> getInit() << " in farenheit is " ;
   p -> compute();
   cout << p -> getConv() << " celsius\n";
   p = &p1;
   cout << p -> getInit()  << " kilo is ";
   p -> compute();
   cout << p -> getConv() << " grams \n";
   getch();
   return 0;
}
