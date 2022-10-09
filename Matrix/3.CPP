#include<iostream.h>
#include<conio.h>
int Matrix(int [20][20],int,int,int);
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
	i=1; j=1;
	Result=Matrix(a,n,i,j);
	if (Result!=-1)
		cout<<"A[i][j]= "<<Result;
	getch();
}
int Matrix(int a[][20],int n,int x,int y)
{
	int m[10][20],i,j,cnt=0;
	for (i=0;i<n;i+=2)
	{
		for (j=0;j<n;j++)
			m[cnt][j]=a[i][j];
		cnt++;
	}
	for (i=0;i<cnt;i++)
		if (i==x)
			return m[i][y];
	return -1;
}