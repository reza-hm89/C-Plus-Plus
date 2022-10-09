#include<iostream.h>
#include<conio.h>
int col[20];
int count;
void queens(int,int);
void print(int);
int check(int,int);
void main()
{
	clrscr();
	queens(1,3);
	cout<<"\nNumber of BackTracking: "<<count;
	getch();
}
void print(int n)
{
	for (int i=1;i<=n;i++)
		cout<<"Rokh "<<i<<"  Col "<<col[i]<<"\n";
	cout<<endl;
}
void queens(int k,int n)
{
	int i;
	for (i=1;i<=n;i++)
	{
		if (check(k,i))
		{
			col[k]=i;
			if (k==n)
				print(n);

			else if (k<n)
				queens(k+1,n);
		}
	}
	count++;
}
int check(int k,int i)
{
	int j;
	for (j=1;j<k;j++)
		if (col[j]==i)
			return 0;
	return 1;
}