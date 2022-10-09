#include <iostream.h>
#include <conio.h>
#define tab '\t'
struct data {
   char name[20];
   int age;
   double height;
};
//************
ostream &operator <<(ostream &str_out, data &q)
{
  str_out << q.name << tab;
  str_out << q.age  << tab;
  str_out << q.height << endl;
  return str_out;
}
//***********
template <class T>
class TnotSimple {
    private:
	 T d;
    public:
	 TnotSimple(T n);
	 void show();
};
//*************
template <class T>
TnotSimple<T>::TnotSimple(T n)
{
  d = n;
}
//***********
template <class T>
void TnotSimple<T>::show()
{
   cout << d << endl;
}
//**************
int main()
{
   clrscr();
   struct data man = {"ali", 25, 175};
   TnotSimple <data> x(man);
   x.show();
   getch();
   return 0;
}

