#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
template <class arType, int size> class aType {
      arType a[size];
    public:
       aType();
       arType &operator[](int i);
};
//*****************

template <class arType, int size>
aType <arType, size>::aType()
{
	  register int i;
	  for(i = 0; i < 10; i++)
	       a[i] = i;
}
//*********************
//provide range checking for aType
template <class arType, int size>
arType &aType<arType, size>::operator[](int i)
{
   if(i < 0 || i > size - 1) {
      cout << "\nIndex value of " << i << " is out of range.\n";
      getch();
      exit(1);
   }
   return a[i];
}
//****************
int main()
{
   clrscr();
   aType <int, 10> intOb;        //int array of size 10
   aType <double, 15> doubleOb;  //double array of size 15
   int i;
   cout << "Integer array: ";
   for(i = 0; i < 10; i++)
      intOb[i] = i;
   for(i = 0; i < 10; i++)
      cout << intOb[i] << " ";
   cout << endl;
   cout << "Double array: ";
   for(i = 0; i < 15; i++)
      doubleOb[i] = (double)i / 2;
   for(i = 0; i < 15; i++)
      cout << doubleOb[i] << " ";
   cout << endl;
   intOb[12] = 100;
   getch();
   return 0;
}
