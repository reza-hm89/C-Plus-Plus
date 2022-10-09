# include<conio.h>
# include<iostream.h>
# include<stdio.h>
# include<stdlib.h>
void main()
{
char s1[50],s2[50];
int i,j,k,c=0,num1[50]={0},num2[50]={0},num3[51]={0};
clrscr();
cout<<"\nNum1 : ";
gets(s1);
cout<<"\nNum2 : ";
gets(s2);
for(i=0;s1[i];i++);
for(j=i-1,k=49;j>=0;j--,k--)
	num1[k]=s1[j]-'0';
for(i=0;s2[i];i++);
for(j=i-1,k=49;j>=0;j--,k--)
	num2[k]=s2[j]-'0';
for(i=49;i>=0;i--)
	{
	num3[i+1]=(num1[i]+num2[i]+c)%10;
	c=(num1[i]+num2[i]+c)/10;
	}//For
num3[0]=c;
for(i=0;!num3[i];i++);
cout<<"\nResult : ";
for(j=i;j<51;j++)
	cout<<num3[j];
getch();
}//Main