#include <iostream.h>
#include <conio.h>
template <class Type> void bubble(Type *items, const int count)
{
  register int a, b;
  Type temp;
  for(a = 1; a < count; a++)
     for(b = count - 1; b >= a; b --)
	if(items[b - 1] > items[b]) {
	    temp = items[b - 1];
	    items[b -1] = items[b];
	    items[b] = temp;
	}
}
//*****************
int main()
{
   const int SIZE = 7;
   int    iArray[SIZE] = { 7, 5, 4, 3, 9, 8, 6 };
   double dArray[SIZE] = {4.3, 2.5, -0.9, 100.2, 3.0, 1.2, 5.6 };
   int i;
   clrscr();
   cout << "Here is unsorted data :";
   for(i = 0; i < SIZE; i ++)
       cout << iArray[i] << "  ";
   cout << endl;
   for(i = 0; i < SIZE; i ++)
       cout << dArray[i] << "  ";
   cout << endl;
   bubble(iArray, SIZE);
   bubble(dArray, SIZE);
   cout << "Here is sorted data :";
   for(i = 0; i < SIZE; i ++)
       cout << iArray[i] << "  ";
   cout << endl;
   for(i = 0; i < SIZE; i ++)
       cout << dArray[i] << "  ";
   getch();
   return 0;
}
