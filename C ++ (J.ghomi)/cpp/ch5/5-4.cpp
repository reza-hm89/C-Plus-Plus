#include <iostream.h>
#include <conio.h>
int main()
{
     int arr[5] ,i ;
     clrscr();
     cout << "\n Enter five value :" ;
     for(i=0 ; i<5 ; i++)
       cin >> arr[i] ;
     cout << "\n The reverse output is :";
     for(i=4 ; i>=0 ; i -- )
	    cout << *(arr + i) << "  ";
     getch();
     return 0;
}



