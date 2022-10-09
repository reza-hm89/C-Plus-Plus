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
	i=2; j=1;
	Result=Matrix(a,n,i,j);
	if (Result!=-1)
		cout<<"A[i][j]= "<<Result;
	getch();
}
int Matrix(int a[][20],int n,int x,int y)
{
	int m[20][3],i,j,cnt=0;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (i<=j)
			{
				m[cnt][0]=i;
				m[cnt][1]=j;
				m[cnt++][2]=a[i][j];
			}
	for (i=0;i<cnt;i++)
		if (y==m[i][1])
			return m[x][2];
	return -1;
}