#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int sum=0,r,i;
long int num;
cout<<"Enter your number:\n";
cin>>num;
for(i=1;i<=(num-1);i++)
  {
   if((num%i)==0)
   sum+=i;
  }
if (sum==num)
   cout<<"\nYour Number is Kamel\n";
else
   cout<<"Your number is not kamel";

getch();
return 0;
}
