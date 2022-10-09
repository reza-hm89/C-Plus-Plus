#include <iostream.h>
#include <conio.h>
int main()
  {
       int i, sum=0, num ;
       float ave ;
       const int n = 5;
       clrscr();
       for(i = 0 ; i < n; i++) {
       	 cout << "Enter number " << i+1 << ": " ;
	       cin >> num ;
	       sum += num ;
       } //end of for
       ave = (float) sum / n ;
       cout << "The average is: " << ave ;
       getch();
       return 0;
  }

