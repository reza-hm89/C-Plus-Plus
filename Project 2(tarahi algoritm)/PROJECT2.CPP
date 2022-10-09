#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
//=========================================
void ReadFile();
void SaveFile();
void Convert();
void Check();
void mabna2(int,int &);
int Calculate(char []);
//=========================================
char input[100][100];
int output[100];
int NumOfString;
//=========================================
void main()
{
	clrscr();
	ReadFile();
	Convert();
	Check();
	SaveFile();
	getch();
}
//=========================================
void mabna2(int n,int a[])
{
	int r,i=0;
	while (n>0)
	{
		r=n%2;
		a[i++]=r;
		n/=2;
	}
}
//=========================================
void Check()
{
	char s[100],s1[100];
	int i,j,k,t,z,cnt=0;
	int a[100]={0};
	for (i=0;i<NumOfString;i++)
	{
		for (int i1=0;i1<100;i1++)
			a[i1]=0;
		strcpy(s,input[i]);
		k=0;
		cnt=0;
		for (j=0;s[j];j++)
			if (s[j]=='*')
				k++;
		for (t=0;t<pow(2,k);t++)
		{
			mabna2(t,a);
			z=0;
			for (j=0;j<strlen(s);j++)
			{
				if (s[j]=='*')
					s1[j]=a[z++]+48;
				else
					s1[j]=s[j];
			}
			s1[j]='\0';
			if (Calculate(s1))
				cnt++;
		}
		output[i]=cnt;
	}
}
//=========================================
int Calculate(char s[])
{
	int len,x,i,j,k,z,t;
	char s1[100],s2[100],s3[100];
	len=strlen(s);
	x=len/3;
	for (i=1;i<=x;i++)
	{
		for (j=0;j<len-i;j++)
		{
			t=0;z=1;
			for (k=0;k<i;k++)
				s1[t++]=s[k+j];
			s1[t]='\0';
			t=0;z++;
			for (k=i;k<=z*i-1;k++)
				s2[t++]=s[k+j];
			s2[t]='\0';
			t=0;
			for (k=z*i;k<=(z+1)*i-1;k++)
				s3[t++]=s[k+j];
			s3[t]='\0';
			if (strcmp(s1,s2)==0 && strcmp(s2,s3)==0 && strcmp(s1,s3)==0)
				return 0;
		}
	}
	return 1;
}
//=========================================
void Convert()
{
	char s[100][100];
	int i,j,k,t;
	for (i=0;i<NumOfString;i++)
	{
		t=0;
		for (j=0;j<100;j++)
		{
			if (input[i][j]==' ')
			{
				for (k=j+1;k<100;k++)
					s[i][t++]=input[i][k];
				s[i][t+1]='\0';
				break;
			}
		}
	}
	for (i=0;i<NumOfString;i++)
		strcpy(input[i],s[i]);
	NumOfString--;
}
//=========================================
void ReadFile()
{
	ifstream f;
	char s[100],t[100];
	int i=0;
	textmode(C80);
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	gotoxy(1,2);
	cprintf("Enter Adress for Input  ");
	textbackground(BLACK);
	cprintf("                                ");
	textbackground(BLUE);
	gotoxy(26,2);
	gets(t);
	f.open(t,ios::in);
	if (!f)
	{
		cout<<"Can not Open File...";
		return;
	}
	while (1) {
		f.getline(s,100,'\n');
		if (s[0]==0)
			break;
		strcpy(input[i++],s);
	}
	NumOfString=i;
	f.close();
}
//=========================================
void SaveFile()
{
	int i;
	char s[20]="Case ",ch[]=" : ";
	char x[4],t[100];
	gotoxy(1,4);
	cprintf("Enter Adress for Output ");
	textbackground(BLACK);
	cprintf("                                ");
	textbackground(BLUE);
	gotoxy(26,4);
	gets(t);
	clrscr();
	ofstream f;
	f.open(t,ios::out);
	if (!f) {
		cout<<"Can not Open File...";
		getch();
		return;
	}
	for (i=0;i<NumOfString;i++)
	{
		strcpy(s,"Case ");
		itoa((i+1),x,10);
		strcat(s,x);
		strcat(s,ch);
		x[0]='\0';
		itoa(output[i],x,10);
		strcat(s,x);
		strcat(s,"\n");
		puts(s);
		f.write(s,20);
		s[0]='\0';
		s[0]=NULL;
	}
	f.close();
}