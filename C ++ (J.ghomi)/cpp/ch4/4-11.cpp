#include <iostream.h>
#include <conio.h>
#include <string.h>
void bubble(char [][21], int);
int bsearch(char [][21], char [], int);
int main()
{
    const int n = 5;
    int i;
    char name[21], arr [n][21];
    clrscr();
    for(i = 0; i < n; i ++){
       cout << "Enter name " << (i + 1) << " :" ;
       cin.get(arr[i], 20);
       cin.get();
    }
    bubble(arr, n);
    cout << "Enter one name for search :" ;
    cin.get(name, 20) ;
    if(bsearch(arr, name, n) == -1)
  	    cout << "Name " << name << " not exist in table." ;
     else
	    cout << "Name " << name << " exist in table." ;
     getch();
     return 0;
}
//********************
void bubble(char arr[5][21], int n)
{
  int i, j;
  char temp[21];
  for(i = n - 1; i > 0; i --)
     for(j = 0; j < i; j++)
       if(strcmp(arr[j], arr[j + 1]) > 0){
	       strcpy(temp, arr[j]);
	       strcpy(arr[j], arr[j + 1]);
	       strcpy(arr[j + 1], temp);
       }
}
//*******************
int bsearch(char arr[5][21], char name[21], int n)
{
  int mid, low = 0, high = n - 1;
  while(low <= high){
     mid = (low + high) / 2;
     if(strcmp(name, arr[mid]) < 0)
	     high = mid - 1;
     else if(strcmp(name, arr[mid]) > 0)
	     low = mid + 1;
     else return mid;
  }
  return -1;
}






