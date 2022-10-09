#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class arrayType {
     int a[3];
  public:
     arrayType(int i, int j, int k)
     {
	    a[0] = i;
	    a[1] = j;
	    a[2] = k;
     }
     int &operator [](int i) ;
};
// provide range checking for atype
int &arrayType::operator[](int i)
{
   if (i < 0 || i > 2) {
      cout << "\nBoundray error\n";
      exit(1);
   }
   return a[i];
}
//**********
int main ()
{
   int i;
   clrscr();
   arrayType ob(1,2, 3);
   cout << "Initial ob[0] = " << ob[0] << endl;
   ob[0] = 25; // [] on the leftof =
   cout << "New ob[0] is: " << ob[0] << endl;
   for(i = 1; i < 3; i++)
      cout << "ob[" << i << "]= " << ob[i] << "  ";
   getch();
   return 0;
}



