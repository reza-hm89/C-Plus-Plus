# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
int motegharen(char s1[100])
{
char s2[100];
int i,j,k=0;
if(s1[0]==0)
	return 0;
for(i=0;s1[i];i++);
	i--;
for(j=i;j>=0;j--)
	{
	s2[k]=s1[j];
	k++;
	}//For
s2[k]=0;
for(i=0;s1[i];i++)
	if(s1[i]!=s2[i])
		return 0;
return 1;
}//Motegharen
//------------------------------------------------------------------------------
void main()
{
char s[100],ss[100];
int i=0,j=0,k=0,l,res=0,a;
clrscr();
cout<<"Enter String : ";
gets(s);
for(i=0;s[i];i++)
	{
	k=0;
	while(s[i]!=' '&&s[i]!=0)
		{
		ss[k]=s[i];
		k++;
		i++;
		}//While
	ss[k]=0;
	a=motegharen(ss);
	if(a==1)
		{
		cout<<"\n";
		puts(ss);
		}//If
	if(s[i]==0)
		break;
	}//For
getch();
}//Main

