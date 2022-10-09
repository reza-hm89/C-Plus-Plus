#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Menu();
void InputA();
void InputB();
void Sum();
void Sub();
void Subscription();
void Sorting();
//-------------------------------
char a[20][20],b[20][20],c[20][20];
int  LenA,LenB,LenC;
//-------------------------------
void Menu()
{
	int i,n;
	clrscr();
	cout<<"\n1. Input array A";
	cout<<"\n\n2. Input array B";
	cout<<"\n\n3. A + B";
	cout<<"\n\n4. A - B";
	cout<<"\n\n5. A ï B";//(char)239
	cout<<"\n\n6. A * B";
	cout<<"\n\n7. Sorting A";
	cout<<"\n\n8. Exit";
	cout<<"\n\nEnter Number (1..8) : ";

	if (LenA!=0)
	{
		gotoxy(1,22);
		cout<<"A= { ";
		for (i=0;i<LenA-1;i++)
			cout<<a[i]<<" , ";
		cout<<a[LenA-1]<<" }";
	}

	if (LenB!=0)
	{
		gotoxy(1,25);
		cout<<"B= { ";
		for (i=0;i<LenB-1;i++)
			cout<<b[i]<<" , ";
		cout<<b[LenB-1]<<" }";
	}

	do {
		gotoxy(23,18);
		cout<<"      ";
		gotoxy(23,18);
		cin>>n;
	} while (n<1 || n>8);

	switch (n)
	{
		case 1:
			InputA();
			break;
		case 2:
			InputB();
			break;
		case 3:
			Sum();
			break;
		case 4:
			Sub();
			break;
		case 5:
			Subscription();
			break;
		case 7:
			Sorting();
			break;
		case 8:
			exit(0);
	}
	Menu();
	getch();
}
//--------------------------------
void InputA()
{
	int i;
	clrscr();
	cout<<"Enter Number Of Names: ";
	cin>>LenA;
	for (i=0;i<LenA;i++)
	{
		cout<<"Enter Name "<<i+1<<": ";
		gets(a[i]);
	}
	getch();
}
//--------------------------------
void InputB()
{
	int i;
	clrscr();
	cout<<"Enter Number Of Names: ";
	cin>>LenB;
	for (i=0;i<LenB;i++)
	{
		cout<<"Enter Name "<<i+1<<": ";
		gets(b[i]);
	}
	getch();
}
//--------------------------------
void Sum()
{
	int i,j,sw;
	LenC=0;
	clrscr();
	cout<<"Sum A,B:\n\n";
	for (i=0;i<LenA;i++)
		strcpy(c[LenC++],a[i]);

	for (i=0;i<LenB;i++)
	{
		sw=0;
		for (j=0;j<LenC;j++)
			if (strcmp(c[j],b[i])==0)
				sw=1;
		if (sw==0)
			strcpy(c[LenC++],b[i]);
	}
	for (i=0;i<LenC;i++)
		cout<<c[i]<<"\t";
	getch();
}
//--------------------------------
void Sub()
{
	int i,j,sw;
	LenC=0;
	clrscr();
	cout<<"Sub A-B :\n\n";
	for (i=0;i<LenA;i++)
	{
		sw=0;
		for (j=0;j<LenB;j++)
			if (strcmp(a[i],b[j])==0)
				sw=1;
		if (sw==0)
			strcpy(c[LenC++],a[i]);
	}
	for (i=0;i<LenC;i++)
		cout<<c[i]<<"\t";
	getch();
}
//--------------------------------
void Subscription ()
{
	int i,j;
	LenC=0;
	clrscr();
	cout<<"A ï B:\n\n";
	for (i=0;i<LenA;i++)
		for (j=0;j<LenB;j++)
			if (strcmp(a[i],b[j])==0)
				strcpy(c[LenC++],a[i]);
	for (i=0;i<LenC;i++)
		cout<<c[i]<<"\t";
	getch();
}
//--------------------------------
void Sorting()
{
	clrscr();
	LenC=0;
	int i,j;
	char temp[20];
	cout<<"Sorting A:\n\n";
	for (i=0;i<LenA;i++)
		strcpy(c[LenC++],a[i]);
	for (i=0;i<LenC;i++)
		for (j=0;j<LenC-i-1;j++)
			if (strcmp(c[j],c[j+1])>0)
			{
				strcpy(temp,c[j]);
				strcpy(c[j],c[j+1]);
				strcpy(c[j+1],temp);
			}
	for (i=0;i<LenC;i++)
		cout<<c[i]<<"\t";
	getch();
}
//--------------------------------
void main()
{
	Menu();
}