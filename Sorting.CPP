#include<iostream.h>
#include<conio.h>
class Sort {
	int a[20];
	int n;
	public :
		void Get();
		void Print();
		void Bubble_Sort();
		void Selection_Sort();
		void Insertion_Sort();
	};
void Sort::Get()
{
	int i;
	cout<<"Enter n: ";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Enter Number "<<i+1<<" : ";
		cin>>a[i];
	}
}
void Sort::Print()
{
	for (int i=0;i<n;i++)
		cout<<a[i]<<"\t";
}
void Sort::Bubble_Sort()
{
	int i,j,temp;
	for (i=0;i<n;i++)
		for (j=0;j<n-i;j++)
			if (a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}
void Sort::Selection_Sort()
{
	int i,j,minpos,temp;
	for (i=0;i<n-1;i++)
	{
		minpos=i;
		for (j=i+1;j<n;j++)
			if (a[j]<a[minpos])
				minpos=j;
		temp=a[minpos];
		a[minpos]=a[i];
		a[i]=temp;
	}
}
void Sort::Insertion_Sort()
{
	int i,j,x;
	for (i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while (j>=0 && x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void main()
{
	clrscr();
	Sort sort;
	sort.Get();
	clrscr();
	int n=0;
	cout<<"1.Bubble Sort";
	cout<<"\n2.Selection Sort";
	cout<<"\n3.Insertion Sort";
	cout<<"\nEnter 1..3 : ";
	cin>>n;
	if (n==1)
	{
	cout<<"\nBubble Sort:\n";
	sort.Bubble_Sort();
	sort.Print();
	}
	else if (n==2)
	{
	cout<<"\nSelection Sort:\n";
	sort.Selection_Sort();
	sort.Print();
	}
	else if (n==3)
	{
	cout<<"\nInsertion Sort:\n";
	sort.Insertion_Sort();
	sort.Print();
	}
	getch();
}
