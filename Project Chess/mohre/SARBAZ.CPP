#include<iostream.h>
#include<conio.h>
void main()
{       int i,j,x,y,a[9],b[9],c[8][8];
	clrscr();
	cout<<"Enter your location:\n";
	cin>>x>>y;
	for (i=0;i<=8;i++)
		for (j=0;j<=8;j++)
			c[i][j]=0;
	b[y]=y;
	a[x]=x;
	i=a[x];
	j=b[y];
	c[4][5]=1;
       //	for (i=0;i<8;i++)

		if((b[y]==2) && (c[x][++y]==0))
		{	cout<<i<<++j<<"\t";
			cout<<i<<++j;
		}
		else   //(c[x][++y]==0)
			cout<<i<<++j;
	 getch();
}