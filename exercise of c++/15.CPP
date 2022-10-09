# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
void main()
{
clrscr();
float x;
int cnt=0,m,n,pow_10=1;
long int a;
cout<<"Enter X : ";
cin>>x;
a=floor(x);
while(a!=x)
	{
	x*=10;
	cnt++;
	a=floor(x);
	}//While
for(int i=1;i<=cnt;i++)
	pow_10=pow_10*10;
m=a/pow_10;
n=a%pow_10;
cout<<"\nM : "<<m<<"    "<<"N : "<<n;
getch();
}//Main