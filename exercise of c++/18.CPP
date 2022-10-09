# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
void main()
{
int i,cnt=0,fcnt=0;
long int a,rev=0;
double x, result;
clrscr();
cout<<"Enter X : ";
cin>>x;
a=floor(x);
while(a!=x)
	{
	x*=10;
	fcnt++;
	a=floor(x);
	}//While
while(a>0)
	{
	rev=rev*10+a%10;
	a=a/10;
	cnt++;
	}//While
result=rev;
for(i=1;i<=cnt-fcnt;i++)
	result=result/10;
cout<<"\nResult : "<<result;
getch();
}//Main