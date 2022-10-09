#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k=0,x=1,n,index=1,num,a[100],b[100];
	clrscr();
	printf("Enter Number of Array:\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("Enter Number %d:",i);
		scanf("%d",&a[i]);
	}
	b[1]=a[1];
	for (i=2;i<=n;i++)
	{
		index=1;
		for (j=1;j<i;j++)
			if (a[i]==b[j])
				index=0;
		if(index==1)
		{
			x++;
			b[x]=a[i];
		}
	}
	for (j=1;j<=x;j++)
		printf("%d\t",b[j]);

	getch();
	return 0;
}