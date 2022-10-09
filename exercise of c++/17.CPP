# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
int list[10],help_1[10],help_2[10],p=0,min,cnt,k,t1,t2;
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
		help_1[p]=k;
		help_2[p]=cnt;
		p++;
		}//If
for(i=0;i<p;i++)
	for(int j=i+1;j<p;j++)
		if(help_2[j]>help_2[i])
			{
			t2=help_2[j];
			t1=help_1[j];
			help_2[j]=help_2[i];
			help_1[j]=help_1[i];
			help_2[i]=t2;
			help_1[i]=t1;
			}//If
for(i=0;i<p;i++)
	cout<<help_1[i]<<" : "<<help_2[i]<<'\n';
getch();
}//Main
