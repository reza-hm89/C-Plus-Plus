#include<iostream.h>
#include<conio.h>
int main()
{
	clrscr();
	int n,j,i,a[100],temp,index=0,num;
	cout<<"Enter Number of Array:\n";
	cin>>n;
	for (i=1;i<=n;i++)
	 {
		cout<<"Enter Number "<<i<<":";
		cin>>a[i];
	 }
	for (i=1;i<n;i++)
	{
		for (j=1;j<=n;j++)
			if (a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	}
	clrscr();
	cout<<"Enter Your Number:";
	cin>>num;
	for (i=1;i<=n;i++)
		if (num==a[i])
			index=1;
	if (index==0)
	{       n++;
		a[n]=num;
		for (i=1;i<n;i++)
		{
			for (j=1;j<=n;j++)
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
	}
	else
		cout<<"Adad Tekrari bod!\n";
	for (i=1;i<=n;i++)
		cout<<a[i]<<"\t";
	getch();
	return 0;
}
