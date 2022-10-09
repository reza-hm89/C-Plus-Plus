#include <iostream.h>
#include <conio.h>
int main()
{
   const int n = 10;
   int arr[n], i, c1 = 0, c2 = 0 ;
   clrscr();
   cout << "\n Enter " << n << " numbers and press ENTER:\n";
   for(i = 0; i < n; i++)
     cin >> arr[i];
   cout << "\n Negavives are:";
   for(i = 0 ; i < n ; i++)
      if(arr[i] < 0) {
	     cout << "  " << arr[i];
	     c1 ++;
      } //end of if
      cout << "\n Positives are:";
   for(i = 0 ; i < n ; i++)
      if(arr[i] > 0){
	     cout <<"  " << arr[i];
	     c2 ++;
      }//end of if
   cout << "\n Number of negatives = " << c1;
   cout << "\n Number of positives = " << c2;
   getch();
   return 0;
}

