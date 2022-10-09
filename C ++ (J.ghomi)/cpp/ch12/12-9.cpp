#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
const int SIZE = 10;
template <class arType> class aType {
      arType a[SIZE];
    public:
      aType();
        arType &operator[](int i);
};
template <class arType>
aType<arType>::aType()
{
     register int i;
     for(i = 0; i < SIZE; i++)
        a[i] = i;
}
//*****************
//provide range checking for aType
template <class arType> arType &aType<arType>::operator[](int i)
{
   if(i < 0 || i > SIZE - 1) {
      cout << "Index value of " << i << " is out of range.\n";
      getch();
      exit(1);
   }
   return a[i];
}
//****************
int main()
{
   clrscr();
   aType <int> intOb;         //int array
   aType <double> doubleOb;  //double array
   int i;
   cout << "Integer array: ";
   for(i = 0; i < SIZE; i++)
      intOb[i] = i;
   for(i = 0; i < SIZE; i++)
      cout << intOb[i] << " ";
   cout << endl;
   cout << "Double array: ";
   for(i = 0; i < SIZE; i++)
      doubleOb[i] = (double)i / 2;
   for(i = 0; i < SIZE; i++)
      cout << doubleOb[i] << " ";
   cout << endl;
   intOb[12] = 100;
   getch();
   return 0;
}
