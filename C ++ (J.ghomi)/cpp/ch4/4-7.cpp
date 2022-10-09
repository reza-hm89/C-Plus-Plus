#include <iostream.h>
#include <conio.h>
int findMin(int [], int);
int main()
{
   int list[20], num, size=0 ;
   clrscr();
   do{
     cout << "Enter list[" << size << "]:";
     cin >> list[size];
   } while(list[size ++] != 0) ;
   size --;
   num = findMin(list, size) ;
   cout << "\n Minimum is: " << num ;
   getch();
   return 0;
}
//***********************
int findMin(int arr[], int size)
{
     int i, min1 ;
     min1 = arr[0] ;
     for(i = 0 ; i < size; i++)
  	      if(arr[i] < min1)
	          min1 = arr[i] ;
     return(min1) ;
}

