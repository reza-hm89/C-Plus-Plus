#include<iostream.h>
#include<conio.h>
void mergesort(int [],int,int);
void merge(int [],int,int,int);
void main()
{
	clrscr();
	int a[20],n;
	cout<<"Enter n: ";
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	for (i=0;i<n;i++)
		cout<<a[i]<<"\t";
	getch();
}
void mergesort(int a[],int low,int high)
{
	if (low>=high)	return;
	else {
		int mid;
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid, int high)
{
	int i,k,j,b[20];
	i=k=low;
	j=mid+1;
	while (i<=mid && j<=high)
	{
		if (a[i]<a[j])
			b[k++]=a[i++];
		else if (a[i]>a[j])
			b[k++]=a[j++];
		else {
			b[k++]=a[i++];
			j++;
		}
	}
	for (;i<=mid;i++)
		b[k++]=a[i];
	for (;j<=high;j++)
		b[k++]=a[j];
	for (i=low;i<=high;i++)
		a[i]=b[i];
}