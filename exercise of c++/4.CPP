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
for(i=0;s[i];i++)
	for(j=i+1;s[j];j++)
		if(s[i]==s[j])
			{
			for(k=j;s[k];k++)
				s[k]=s[k+1];
			j--;
			}//If
cout<<"\nResult : ";
puts(s);
getch();
}//Main