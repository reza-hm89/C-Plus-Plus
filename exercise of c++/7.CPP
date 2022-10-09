# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
char s[100];
int i,j,k;
clrscr();
cout<<"\nEnter S : ";
gets(s);
if(s[0]>='a'&&s[0]<='z')
	s[0]-=32;
for(i=1;s[i];i++)
	if(s[i]>='A'&&s[i]<='Z'&&s[i-1]!=' ')
		s[i]+=32;
	else
		if(s[i]>='a'&&s[i]<='z'&&s[i-1]==' ')
			s[i]-=32;
cout<<"\nResult : ";
puts(s);
getch();
}//Main