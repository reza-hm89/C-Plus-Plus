# include<iostream.h>
# include<conio.h>
void fibo(long int a,long int b,int i,int n)
{
if(i==n)
	{
	cout<<"\nYour Selected Number : "<<b;
	return;
	}//If
fibo(b,a+b,++i,n);
}//Fibo
void main()
{
long int x=0,y=1;
int j=1,m;
clrscr();
cout<<"Which Number Do You Want To See : ";
cin>>m;
fibo(x,y,j,m);
getch();
}//Main