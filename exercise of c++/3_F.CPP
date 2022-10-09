# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void link(char *s1,char *s2,int n,int m)
{
int j;
for(j=n+1;j>=0;j--)
	s1[j+m]=s1[j];
for(j=0;j<m;j++)
	s1[j]=s2[j];
s1[n+m]=0;
cout<<"Linked String: ";
for(j=0;s1[j];j++)
cout<<s1[j];
}//Link
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
link(s1,s2,n1,n2);
getch();
}//Main


