#include<iostream.h>
#include<conio.h>
#include<string.h>
int main()
{       char s[100],s1[100];
	int i,n,m,j,index=0;
	clrscr();
	cout<<"Enter your Statement:\n\n";
	cin.get(s,100);
	n=strlen(s);
	strcpy(s1,s);
	m=strlen(s1);
	for (i=m-1,j=0;i>0,j<n;i--,j++)
		if (s1[i]==s[j])
			index++;
	if (index==m)
		cout<<"\nAdad ayne ei ast";
	else
		cout<<"\nAdad ayne ei nist";
	getch();
	return 0;
}
