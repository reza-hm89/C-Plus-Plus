#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{
	char s1[100],s2[100];
	int a[20],b[20],c[21],ch1,ch2,i,j,n,m,x,z,k=0;
	clrscr();
	cout<<"Enter Your Number 1(20 digit):";
	cin.get(s1,20);
	cin.get();
	cout<<"Enter Your Number 2(20 digit):";
	cin.get(s2,20);
	n=strlen(s1);
	m=strlen(s2);
	for (i=0;i<n;i++)
	{
		ch1=s1[i];
		a[i]=ch1-48;
	}
	for (i=0;i<m;i++)
	{
		ch2=s2[i];
		b[i]=ch2-48;
	}
	for (i=0;i<21;i++)
		c[i]=0;
	if (n>m)
	{
	for (i=n-1,j=m-1;i>=0;i--,j--)
	{
	       x=a[i]+b[j];
	       if (x<10)
	       {        k++;
			z=x;
	       }
	       else
	       {        k++;
			z=x-10;
			c[k+1]++;
	       }
	       c[k]+=z;
	}
	}
	if (m>n)
	{
	for (i=n-1,j=m-1;j>=0;i--,j--)
	{
	       x=a[i]+b[j];
	       if (x<10)
	       {
			k++;
			z=x;
	       }
	       else
	       {
			k++;
			z=x-10;
			c[k+1]++;
	       }
	       c[k]+=z;
	}
	}
	if (m==n)
	{
	for (i=n-1,j=m-1;i>=0,j>=0;i--,j--)
	{
	       x=a[i]+b[j];
	       if (x<10)
	       {
			k++;
			z=x;
	       }
	       else
	       {
			k++;
			z=x-10;
			c[k+1]++;
	       }
	       c[k]+=z;
	}
	}
	cout<<"\n\nSum is:";
	for (i=k+1;i>0;i--)
		cout<<c[i];
	getch();
}

