# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
int list[10],min,cnt,k;
clrscr();
cout<<"list[0] : ";
cin>>list[0];
min=list[0];
for(int i=1;i<10;i++)
	{
	cout<<"list["<<i<<"] : ";
	cin>>list[i];
	if(list[i]<min)
		min=list[i];
	}//For
min--;
for(i=0;i<10;i++)
	if(list[i]!=min)
		{
		cnt=0;
		k=list[i];
		for(int j=i;j<10;j++)
			if(list[j]==k)
				{
				cnt++;
				list[j]=min;
				}//If
		cout<<k<<" : "<<cnt<<'\n';
		}//If
getch();
}//Main
