#include<iostream.h>
#include<conio.h>
void maxmin(int [],int,int ,int&,int&);
void main()
{
	int n,a[100],max1=0,max2=0;
	clrscr();
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	maxmin(a,0,n-1,max1,max2);
	cout<<max1<<"  "<<max2;
	getch();
}
void  maxmin(int a[],int low,int high,int &max1,int &max2)
{
	int ml1,ml2,mr1,mr2;
	if (low==high) {
		max1=max2=a[low]; return;}
	if (low==high-1)
	{
		if (a[low]>a[high]) {
			max1=a[low]; max2=a[high];
		}
		else
		{	max1=a[high];   max2=a[low];      }
		return;
	}
	int m;
	m=(low+high)/2;
	maxmin(a,low,m,ml1,ml2);
	maxmin(a,m+1,high,mr1,mr2);
	if (ml1>mr1 && ml1>mr2)
		max1=ml1;
	if (mr1>ml1 && mr1>ml2)
		max1=mr1;
	if (ml1<mr1 && ml1>mr2)
		max2=ml1;
	if (mr1<ml1 && mr1>ml2)
		max2=mr1;
	if (mr2>ml1)
		max2=mr2;
	if (ml2>mr1)
		max2=ml2;
}