#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
template <class T>
class Tsimple {
    private:
      T data;
    public:
	   Tsimple(T n);
	void show();
};
//*************
template <class  T>
Tsimple<T>::Tsimple(T n)
{
   data = n;
}
//******************
template <class  T>
void Tsimple<T>::show()
{
   cout << data << endl;
}
//***************
int main()
{
   clrscr();
   Tsimple<int> x(25);
   cout << "x = ";
   x.show();
   Tsimple<char> y('p');
   cout << "y = ";
   y.show();
   Tsimple<double> z(1.25);
   cout << "z = ";
   z.show();
   getch();
   return 0;
}



