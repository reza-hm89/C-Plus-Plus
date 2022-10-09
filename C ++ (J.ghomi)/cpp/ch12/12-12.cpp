#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
//here, artype defaults to int and size defaults to 10
template <class artype = int, int size = 10> class atype {
      artype a[size];
    public:
      atype();

      artype &operator[](int i);
};
//*****************
template <class artype, int size>
atype<artype, size>::atype()
{
	  register int i;
	  for(i = 0; i < size; i++)
	       a[i] = i;

}
//provide range checking for atype
template <class artype, int size>
artype &atype<artype, size>::operator[](int i)
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
   atype <int, 100> intArray;     //int array of size 100
   atype <double> doubleArray;  //double array default size
   atype<> defArray;            //default to int of size 10
   int i;
   cout << "Integer array: ";
   for(i = 0; i < 100; i++)
      intArray[i] = i;
   for(i = 0; i < 100; i++)
      cout << intArray[i] << " ";
   cout << endl;
   cout << "Ddouble array: ";
   for(i = 0; i < 10; i++)
      doubleArray[i] = (double)i / 2;
   for(i = 0; i < 10; i++)
      cout << doubleArray[i] << " ";
   cout << endl;
   cout << "Default array: ";
   for(i = 0; i < 10; i++)
      doubleArray[i] = i ;
   for(i = 0; i < 10; i++)
      cout << defArray[i] << " ";
   cout << endl;
   getch();
   return 0;
}
