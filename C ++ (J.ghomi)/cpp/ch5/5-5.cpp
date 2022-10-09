#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
void pInput(int *, int);
void bubble(int *, int);
void median(int *, int, float *);
void pOutput(int *, int);
int main()
{
  int n, *p;
  float mead;
  clrscr();
  cout << "Enter number of items(n):";
  cin >> n;
  p = new int[10];
  if(!p){
       cout << " Allocation failure!";
       getch();
       exit(1);
  }
  pInput(p, n);
  bubble(p, n);
  cout << "\n Sorted data are:";
  pOutput(p, n);
  median(p, n, &mead);
  cout << "\n Median = " << mead;
  delete p;
  getch();
  return 0;
}
//*****************************
void pInput(int  *p, int n)
{
  int i;
  for(i = 0; i < n; i ++){
     cout << "Enter number " <<  (i + 1) << ": ";
       cin >>  *(p + i);
  }
}
//*****************************
void bubble(int  *temp, int len)
{
   int i, j, item;
   for(i = len - 1 ; i > 0; i --)
	for(j = 0; j < i ; j++)
	  if(*(temp + j) > *(temp + j + 1)) {
	     item = *(temp + j);
	     *(temp + j) = *(temp + j + 1);
	     *(temp + j + 1) = item ;
	  }//end of if
}
//*************************
void median(int *x, int n, float *mead)
{
   if(n % 2 == 0)
       *mead =(float) (*(x + ((n - 1) / 2)) + *(x + (n / 2))) / 2;
  else
       *mead = *(x + (n - 1) / 2);
}
//****************
void pOutput(int *p, int n)
{
  for(int i = 0; i < n; i ++){
     cout << *(p + i)  <<  " ";
  }
  cout << endl;
}

