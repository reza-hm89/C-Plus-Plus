#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int max=0,num;
cout<<"Enter number:\n";
cin>>num;
max=num;
while(num !=0)
    {
     cout<<"Enter Nnmber(n=0 exit):\n";
     cin>>num;
     if (num>max)
	max=num;
    }
cout<<"Max is: "<<max;
getch();
return 0;
}
