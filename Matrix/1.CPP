#include<iostream.h>
#include<conio.h>
int Matrix(int [20][20],int,int);
void main()
{
	int a[20][20],n,i,j;
	int Result;
	clrscr();
	cout<<"Enter n: ";
	cin>>n;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	i=2; j=1;
	Result=Matrix(a,n,a[i][j]);
	if (Result==1)
		cout<<"Down Traingle & A[i][j]= "<<a[i][j];
	else if (Result==-1)
		cout<<"Up Traingle";
	else
		cout<<"NO...";
	getch();
}
int Matrix(int a[][20],int n,int x)
{
	int sw1=0,sw2=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]!=0 && i<j)
				sw1=1;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (a[i][j]!=0 && i>j)
				sw2=1;
	if (sw1==0)
		return 1;
	if (sw2==0)
		return -1;
	else
		return 0;
}