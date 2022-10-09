#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int x,i,n,a[100],j=0,num;
cout<<"Enter Number of Array:\n";
cin>>n;
for (i=1;i<=n;i++)
   { cout<<"Enter Number "<<i<<":";
     cin>>num;
     a[i]=num;
   }
clrscr();
cout<<"Enter Your Number:\n";
cin>>x;
for (i=0;i<=n;i++)
     if (x==a[i])
	 j++;
if(j!=0)
  cout<<"Number "<<x<<" is "<<j<<" time Repeated.";
else
   cout<<"This Number is no exist!";
getch();
return 0;
}

