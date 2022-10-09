#include<iostream.h>
#include<conio.h>
#include<string.h>
int main()
{       char s[100],ch;
	int i,n,x,k=0;
	clrscr();
	cout<<"Enter your Statement:\n\n";
	cin.get(s,100);
	x=strlen(s);
	cout<<"Enter Your Character And a Number of repeat in the statement:\n";
	cin>>ch>>n;
	for (i=0;i<x;i++)
		if (s[i]==ch)
			{
			 k++;
			 if (n==k)
				cout<<"\nIn location "<<i+1;
			}
	if (n!=k)
		cout<<"Character in "<<n<<" location is not exist.";
	getch();
	return 0;
}
