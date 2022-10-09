#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int max,min,r;
long int num;
cout<<"Enter your number:";
cin>>num;
r=num%10;
max=r;
min=r;
num=num/10;
while(num !=0)
    {
     r=num%10;
     if(r>max)
	max=r;
     if(r<min)
	min=r;
     num/=10;
    }
cout<<"\nMax digit:"<<max<<"\nMin digit:"<<min;
getch();
return 0;
}
