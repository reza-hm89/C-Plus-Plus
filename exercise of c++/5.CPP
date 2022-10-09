# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
int check(char st[100])
{
for(int i=0;st[i];i++);
if(i==4)
	return 1;
return 0;
}//Check
void main()
{
char s[100],help_s[100];
int i,j,k,cnt=0,r;
clrscr();
cout<<"\nEnter S : ";
gets(s);
for(i=0;s[i];i++)
	{
	k=0;
	for(j=i;s[j]&&s[j]!=' ';i++,j++)
			help_s[k++]=s[j];
	help_s[k]=0;
	r=check(help_s);
	cnt+=r;
	}//For
cout<<"\nCnt : "<<cnt;
getch();
}//Main