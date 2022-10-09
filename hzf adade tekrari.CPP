#include<iostream.h>
#include<conio.h>
int main()
{
	int i,j,index=0,x=1,n,num,a[100],b[100];
	clrscr();
	cout<<"Enter Number of Array:\n";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<"Enter Number "<<i<<":";
		cin>>a[i];
	}
	b[1]=a[1];
	for (i=2;i<=n;i++)
	{
		index=0;
		for (j=1;j<i;j++)
			if (a[i]==b[j])
			    index=1;
		if(index==0)
		{
			x++;
			b[x]=a[i];
		}
	}
	for (j=1;j<=x;j++)
		cout<<b[j]<<endl;

	getch();
	return 0;
}