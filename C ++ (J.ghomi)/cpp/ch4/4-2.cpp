#include <iostream.h>
#include <conio.h>
void findIterate(float arr[], int k);
int main()
{
   const int k = 10;
   float arr[k] ;
   int i;
   clrscr();
   cout << "\n Enter " << k << " average and press Enter:\n";
   for (i = 0; i < k; i++)
     cin >> arr[i] ;
   findIterate(arr, k);
   return 0;
}
//*************************
void findIterate(float arr[], int k)
{
   int max_count = -1 ;
   float max_value;
   int  i, j , current_count;
   float current_value ;
   for (i = 0; i < k; i ++){
       current_value = arr[i] ;
       current_count = 0 ;
       for(j = 0; j < k; j++)
	  if (arr[j] == current_value)
	     current_count++ ;
       if (current_count > max_count) {
	    max_count = current_count ;
	    max_value = current_value ;
       }//end of if
   }//end of for (i= 0; i < k ...)
   cout << "\n Maximum iteration of ave :" << max_value  << " is " << max_count;
   getch();
}


