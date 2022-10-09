#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void main()
{
clrscr();
struct st{
	char a[4][10];
	}st1;
int i,j;
ofstream fp("data.dat",ios::out|ios::binary|ios::app);
if (!fp)
{
	cout<<"ccsfddsaffsad";
	getch();
	exit(0);
}
gets(st1.a[1]);
fp.write((char*)&st1,sizeof(struct st));
fp.close();
ifstream fp1("data.dat",ios::binary);
i=0;
while (fp1.read((char*)&st1,sizeof(struct st)))
{
	if (st1.a[i]=="elias")
		break;
	else i++;
}
fp.seekp((i-1*40));
cout<<st1.a[i];
getch();
}
