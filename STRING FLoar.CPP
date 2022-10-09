#include<iostream.h>
#include<conio.h>
#include<string.h>
void main()
{       char s[100];
	long int i,ch,k=10,j;
	long float sum=0,che;
	clrscr();
	cout<<"Enter Your number:";
	cin.get(s,100);
	for (i=0;s[i]!='.';i++)
	{
		ch=s[i]-48;
		sum=ch+(sum*10);
	}
	for (j=i+1;j<strlen(s);j++)
	{
		che=s[j]-48;
		sum+=che/k;
		k*=10;
	}
	cout<<sum*2;

	getch();
}

