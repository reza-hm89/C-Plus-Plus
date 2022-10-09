# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
int i,j,k,x,p=0,insert,list[10];
clrscr();
for(i=1;i<=10;i++)
	{
	cout<<"Enter List [ "<<i<<" ] : ";
	cin>>x;
	insert=1;
	for(j=0;j<p && insert;j++)
		if(x<=list[j])
			{
			for(k=p;k>j;k--)
				list[k]=list[k-1];
			list[j]=x;
			insert=0;
			p++;
			}//If
	if(insert)
		{
		list[p]=x;
		insert=0;
		p++;
		}//If
	}//For
cout<<"\nSorted List : ";
for(i=0;i<10;i++)
	cout<<list[i]<<"     ";
getch();
}//Main
