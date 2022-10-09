#include<conio.h>
#include<iostream.h>
int main()
{
	clrscr();
	int n,i,j,max,maxcntr=0,k,a[100];
	cout<<"Enter Number of array:";
	cin>>n;
	for (i=1;i<=n;i++)
	       {
		cout<<"Enter number "<<i<<":";
		cin>>a[i];
	       }
	for (i=1;i<=n;i++)
	{
		k=0;
		max=a[i];
		for (j=1;j<=n;j++)
			if(a[j]==max)
				k++;
		if (k>maxcntr)
			maxcntr=max;
	}
	cout<<"Max :"<<maxcntr;
	getch();
	return 0;
}