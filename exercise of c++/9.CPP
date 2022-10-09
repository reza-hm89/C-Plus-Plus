# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void del(char s1[100],char s2[100])
{
int i,j,k,f=0,m,n;
for(i=0;s1[i];i++);
m=i;
for(i=0;s2[i];i++);
n=i;
for(i=0;s1[i];i++)
	{
	if(s1[i]==s2[0])
		{
		f=1;
		k=1;
		for(j=i+1;s2[k]&&f;j++)
			{
			if(s1[j]!=s2[k])f=0;
			k++;
			}//For
		}//If
	if(f==1)
		{
		for(j=i;s1[j];j++)
		s1[j]=s1[j+n];
		s1[m-n]=0;
		cout<<"Deleted String : ";
		puts(s1);
		break;
		}//If
	}//For
if(f!=1)
	{
	cout<<"Deleted String : ";
	puts(s1);
	}//If
}//Delete
void main()
{
char s[100],ss[100];
clrscr();
cout<<"Enter Your First String Here : ";
gets(s);
cout<<"Enter Your Second String Here : ";
gets(ss);
clrscr();
cout<<"  First String : ";puts(s);
cout<<" Second String : ";puts(ss);
del(s,ss);
getch();
}//Main

