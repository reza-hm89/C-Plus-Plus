#include <iostream.h>
#include <conio.h>
void ginput(int [], int);
void bubble(int [], int);
void goutput(int [], int);
int main()
{
   const int k = 7 ;
   int temp[7];
   clrscr();
   ginput(temp, k);
   bubble (temp, k);
   cout << "The sorted data are :\n" ;
   goutput(temp, k);
   getch();
   return 0;
}
//**************************
void ginput(int temp[], int len)
{
   int i;
   for(i = 0; i < len; i++) {
	cout << "Enter number " << (i + 1) << " :";
	cin >> temp[i];
   }
}
//**********************
void bubble(int temp[], int len)
{
   int i, j, item;
   for(i = len - 1 ; i > 0; i --)
	for(j = 0; j < i ; j++)
	  if(temp[j] > temp[j + 1]) {
	     item = temp[j] ;
	     temp[j] = temp[j + 1];
	     temp[j + 1] = item ;
	  }//end of if
}
//*************************
void goutput(int temp[], int len)
{
   int i;
   for(i=0 ; i < len; i++)
     cout << temp[i] << " " ;
}

