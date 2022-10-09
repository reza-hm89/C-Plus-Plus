#include<conio.h>
#include<iostream.h>
void main()
{
	int i,j,x,k,a[10][10];
	clrscr();
	cout<<"Enter X: ";
	cin>>x;
	for (i=1;i<=x;i++)
	{
		k=1;
		for (j=i;j<=x;j++)
		{
			a[i][j]=k;
			a[j][i]=k;
			k++;
		}
	}
	for (i=1;i<=x;i++)
	       {
		for (j=1;j<=x;j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	       }
	getch();
}