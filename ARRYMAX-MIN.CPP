#include<iostream.h>
#include<conio.h>
int main()
{
int a[100];
int i,num,n,max,min;
clrscr();
cout<<"Enter Numbers of array:\n";
cin>>n;
cout<<"Enter Number 1:\n";
cin>>num;
a[1]=num;
max=a[1];
min=a[1];
for (i=2;i<=n;i++)
  {
   cout<<"Enter Number "<<i<<":\n";
   cin>>num;
   a[i]=num;
   if(a[i]>max)
       max=a[i];
   else if (a[i]<min)
       min=a[i];
  }
clrscr();
cout<<"Max : "<<max<<endl;
cout<<"Min : "<<min;
getch();
return 0;
}

