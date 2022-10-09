# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
char s1[100],s2[100];
int i,n1,n2;
clrscr();
cout<<"s1 :";
gets(s1);
cout<<"s2 :";
gets(s2);
for(i=0;s1[i];i++);
	n1=i;
for(i=0;s2[i];i++);
	n2=i;
for(i=n1+1;i>=0;i--)
	s1[i+n2]=s1[i];
for(i=0;i<n2;i++)
	s1[i]=s2[i];
s1[n1+n2]=0;
cout<<"Linked String: ";
for(i=0;s1[i];i++)
	cout<<s1[i];
getch();
}//sMain


