# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
unsigned char s1[100],s2[100],*p1,*p2;
clrscr();
cout<<"s1 :";
gets(s1);
cout<<"s2 :";
gets(s2);
for(p2=s2;*p2;p2++);
for(p1=s1;*p1;p2++,p1++)
	*p2=*p1;
*p2=0;
cout<<"Linked String: ";
for(p2=s2;*p2;p2++)
	cout<<*p2;
getch();
}//Main


