#include<iostream.h>
#include<conio.h>
int main()
{
	int i,j,n,a[20][20],sum1=0,sum2=0;
	clrscr();
	cout<<"Enter Number Of Array:";
	cin>>n;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			cout<<"Enter A["<<i<<","<<j<<"]:";
			cin>>a[i][j];
		}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			if(i==j)
				sum1+=a[i][j];
			if((i+j)==(n+1))
				sum2+=a[i][j];
		}
	clrscr();
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\nSum of Ghotre Asli: "<<sum1;
	cout<<"\nSum of ghotre farei: "<<sum2;
	getch();
	return 0;
}