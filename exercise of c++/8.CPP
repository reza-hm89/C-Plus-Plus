# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
char s1[100],s2[100];
int i,j,k,find=0;
clrscr();
cout<<"Enter S1 : ";
gets(s1);
cout<<"\nEnter S2 : ";
gets(s2);
for(i=0;i<=strlen(s1)-strlen(s2);i++)
	if(s1[i]==s2[0])
		{
		for(j=1,k=i+1,find=1;s2[j]&&find;j++,k++)
			if(s1[k]!=s2[j])
				find=0;
		if(find)
			cout<<"\nPos : "<<i;
		}//If
if(!find)
	cout<<"\nPos : Not Found";
getch();
}//Main