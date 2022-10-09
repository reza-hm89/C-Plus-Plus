#include <iostream.h>
class demo {
   mutable int i;
   int j;
   public:
      int getI() const { return i;}
      void setI(int x) const {i = x; }   // not error
      void setJ(int x) const { j = x; }  // error
};
//*******************
int main()
{
  demo ob;
  ob.setI(100);
  cout << ob.getI();
  return 0;
}