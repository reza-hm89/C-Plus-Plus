#include <iostream.h>
#include <conio.h>
template <class T>
void printArray(class T *array, const int count)
{
   for(int i = 0; i < count; i ++)
      cout << array[i] << "  ";
   cout << endl;
}
//*************8
int main()
{
   clrscr();
   const int acount = 5, bcount = 7,ccount = 6;
   int a[acount] = {1, 2, 3, 4, 5};
   double b[bcount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
   char c[ccount] = "HELLO";
   cout << "Array a is : \n";
   printArray(a, acount);  //integer template funcion
   cout << "Array b is : \n";
   printArray(b, bcount);  //double template funcion
   cout << "Array c is : \n";
   printArray(c, ccount);  //character template funcion
   getch();
   return 0;
}
