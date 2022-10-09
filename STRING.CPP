#include<iostream.h>
#include<conio.h>
#include<string.h>
int main()
{       char s[100];
	int i,n;
	clrscr();
	cout<<"Enter your Statement:\n\n";
	cin.get(s,100);
	n=strlen(s);
	clrscr();
	for (i=0;i<n;i++)
	       {
		if (s[i]!=' ')
			cout<<s[i];
		else
			cout<<"\n\n";
	       }
	getch();
	return 0;
}
