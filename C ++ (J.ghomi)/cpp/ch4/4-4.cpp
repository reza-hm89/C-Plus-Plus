#include <iostream.h>
#include <conio.h>
void ginput(int [], int);
void bubble(int [], int);
int  lsearch(int[], int, int);
int  bsearch(int [], int, int);
int main()
{
   const int k = 5 ;
   int st[k], no;
   clrscr();
   ginput(st, k);
   cout << "Enter a student # to search:";
   cin >> no;
   cout << "Result of linear search :";
   if(lsearch(st, k, no) == -1)
      cout << " Number " << no << " not exist in list.";
   else
      cout << " Number " << no << " exist in list.";
   bubble(st, k);
   cout << "\nResult of binarry search :";
   if(bsearch(st, k, no) == -1)
      cout << "Number " << no << " not exist in list.";
   else
      cout << "Number " << no << " exist in list.";
   getch();
   return 0;
}
//**************************
void ginput(int st[], int len)
{
   int i;
   for(i = 0; i < len; i++) {
     cout << "Enter student number " << (i + 1) << " :";
     cin >> st[i];
   }//end of for
}
//**********************
int bsearch(int st[], int len, int no)
{
  int mid, low = 0, high = len - 1;
  while(low <= high){
     mid = (low + high) / 2;
     if(no < st[mid])
	  high = mid - 1;
     else if(no > st[mid])
	  low = mid + 1;
     else return mid;
  }
  return -1;
}
//**********************
void bubble(int st[], int len)
{
   int i, j, item;
   for(i = len - 1 ; i > 0; i --)
	for(j = 0; j < i ; j++)
	  if(st[j] > st[j + 1]) {
	     item = st[j] ;
	     st[j] = st[j + 1];
	     st[j + 1] = item ;
	  }//end of if
}
//*************************
int lsearch(int st[], int len, int no)
{
  int i;
  for(i = 0; i < len; i++)
    if(st[i] == no)
       return i;
  return -1;
}

