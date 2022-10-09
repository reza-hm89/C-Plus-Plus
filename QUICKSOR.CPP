#include<iostream.h>
#include<conio.h>
void quicksort(int [],int,int);
int partition(int[],int,int);
void main()
{
	clrscr();
	int a[100],n;
	cout<<"Enter  n: ";
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	a[n]=3000;
	quicksort(a,0,n-1);
	for (i=0;i<n;cout<<a[i]<<"\t",i++);
	getch();
}
void quicksort(int a[],int low,int high)
{
	if (low>=high) return;
	else {
		int i;
		i=partition(a,low,high+1);
		quicksort(a,low,i-1);
		quicksort(a,i+1,high);
		}
}
int partition(int a[],int low,int high)
{
	int i=low,j=high,pivot=a[low],tmp;
	while (i<=j)
	{
		do {
		i++;
		}while(a[i]<a[low]);
		do {
		j--;
		}while(a[j]>a[low]);
		if (i<j) {
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			}
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
}