#include"conio.h"
#include"iostream.h"
#include"fstream.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct component
{
	int tag,rep;
	char name[30];
	char unit[50];
	int code,unitcode;
	char inp[30],otp[30];
};
component comp[100];
int cnt;
char s[5][20];

void LoadFile()
{
	int i=0;
	ifstream f1,f2,f3,f4;
	f1.open("kargozini.txt");
	f2.open("hesabdari.txt");
	f3.open("hamlonaghl.txt");
	f4.open("anbar.txt");
	if (!f1 || !f2 || !f3 || !f4)
	{
		cout<<"can not open file";
		getch();
		return;
	}
	do
	{
		f1.read((char*)&comp[i++],sizeof(struct component));
	} while(!f1.eof());
	do
	{
		f2.read((char*)&comp[i++],sizeof(struct component));
	} while(!f2.eof());
	do
	{
		f3.read((char*)&comp[i++],sizeof(struct component));
	} while(!f3.eof());
	do
	{
		f4.read((char*)&comp[i++],sizeof(struct component));
	} while(!f4.eof());
	cnt=i;
}
void SaveFile()
{
	clrscr();
	int i;
	ofstream f1,f2,f3,f4;
	f1.open("kargozini.txt");
	f2.open("hesabdari.txt");
	f3.open("hamlonaghl.txt");
	f4.open("anbar.txt");
	for (i=0;i<cnt;i++)
	{
		if (comp[i].unitcode==1)
			f1.write((char *)&comp[i],sizeof(struct component));
		else if (comp[i].unitcode==2)
			f2.write((char *)&comp[i],sizeof(struct component));
		else if (comp[i].unitcode==3)
			f3.write((char *)&comp[i],sizeof(struct component));
		else if (comp[i].unitcode==4)
			f4.write((char *)&comp[i],sizeof(struct component));
	}
	f1.close();
	f2.close();
	f3.close();
	f4.close();
	cout<<"Saved to File...";
	getch();
	return;
}
int ChooseUnit()
{
	int n;
	cout<<"\nEnter Number of Unit: (1=Kargozini, 2=Hesabdari,"
		<< "3=hamlo naghl, 4=anbar): ";
	do {
	cin>>n;
	} while (n<1 || n>4);
	return n;
}

void Insert()
{
	clrscr();
	cout<<"Component name: ";
	gets(comp[cnt].name);
	cout<<"\nEnter Component code: ";
	cin>>comp[cnt].code;
	cout<<"\nEnter unit code (1=Kargozini, 2=Hesabdari,"
		<< " 3=hamlo naghl, 4=anbar) :";
	cin>>comp[cnt].unitcode;
	cout<<"\nEnter input date (d/m/y): ";
	gets(comp[cnt].inp);
	cout<<"\nEnter output date (d/m/y): ";
	gets(comp[cnt].otp);
	comp[cnt].tag=1;
	comp[cnt].rep=0;
	strcpy(comp[cnt].unit,s[comp[cnt].unitcode]);
	cnt++;
}
void Edit()
{
	clrscr();
	char ans;
	int cod,n;
	n=ChooseUnit();
	cout<<"\nEnter code of component: ";
	cin>>cod;
	for (int i=0;i<cnt;i++)
	{
		if (comp[i].code==cod && comp[i].unitcode==n)
		{
			cout<<"found...\n";
			cout<<"\nEnter new Data:\n";
			cout<<"\nComponent name: ";
			gets(comp[i].name);
			cout<<"\nComponent code: ";
			cin>>comp[i].code;
			cout<<"\nDo you want this component goto repair part (y/n)?: ";
			cin>>ans;
			if (ans=='y')
				comp[i].rep=1;
			break;
		}
	}
}
void Delete()
{
	clrscr();
	int cod,n;
	char ans;
	n=ChooseUnit();
	cout<<"\nEnter code of component: ";
	cin>>cod;
	for (int i=0;i<cnt;i++)
	{
		if (comp[i].code==cod && comp[i].unitcode==n && comp[i].tag==1)
		{
			cout<<"found...\n";
			cout<<"\nDo you want delete from this part (y/n): ";
			cin>>ans;
			if (ans=='y')
			{
				comp[i].tag=0;
				cout<<"\nDeleted...";
				getch();
				return;
			}
		}
	}
	cout<<"not found";
	getch();
}
void Search()
{
	clrscr();
	int cod,n;
	cout<<"Enter code of component: ";
	cin>>cod;
	for (int i=0;i<cnt;i++)
	{
		if (comp[i].code==cod && comp[i].tag==1)
		{

			cout<<"\nfound...";
			cout<<"\nexist in "<<comp[i].unit;
			getch();
			return;
		}
	}
	cout<<"not found";
	getch();
}
void Sort()
{
	clrscr();
	int i,j;
	component temp,sort[100];

	for (i=0;i<cnt;i++)
		sort[i]=comp[i];
	for (i=0;i<cnt;i++)
		for (j=i+1;j<cnt;j++)
			if (strcmp(sort[i].name,sort[j].name)<0)
			{
				temp=sort[i];
				sort[i]=sort[j];
				sort[j]=temp;
			}
	for (i=0;i<cnt;i++)
	{
		cout<<"\n";
		cout<<sort[i].name<<"    "<<sort[i].code;
	}
	getch();
}
void Print()
{
	clrscr();
	int i,n,y=4;
	n=ChooseUnit();
	clrscr();
	cout<<"CompName       CompCode    Unit       UnitCode       Input date      output date";
	cout<<"\n--------------------------------------------------------------------------------";
	for (i=0;i<cnt;i++)
	{
		if (comp[i].unitcode==n && comp[i].tag==1)
		{
			gotoxy(1,y);
			cout<<comp[i].name;
			gotoxy(15,y);
			cout<<comp[i].code;
			gotoxy(30,y);
			cout<<comp[i].unit;
			gotoxy(45,y);
			cout<<comp[i].unitcode;
			gotoxy(55,y);
			cout<<comp[i].inp;
			gotoxy(70,y);
			cout<<comp[i].otp;
			y++;
		}
	}
	getch();
}
void Repair()
{
	clrscr();
	for (int i=0;i<cnt;i++)
	{
		if (comp[i].rep==1)
		{
			cout<<"\n"<<comp[i].name;
			cout<<"    "<<comp[i].code;
		}
	}
	getch();
}
void Menu()
{
	int n;
	clrscr();
	cout<<"\n1.Insert New Component";
	cout<<"\n2.Edit Component";
	cout<<"\n3.Search Component";
	cout<<"\n4.Delete Component";
	cout<<"\n5.Sorting";
	cout<<"\n6.Print";
	cout<<"\n7.Tamirat";
	cout<<"\n8.Save to file";
	cout<<"\n9.Exit";
	cout<<"\n\nEnter number (1-9): ";
	do {
	cin>>n;
	} while (n<1 || n>9);
	while (1)
	{
	switch (n)
	{
		case 1:
			Insert();
			Menu();
			break;
		case 2:
			Edit();
			Menu();
			break;

		case 3:
			Search();
			Menu();
			break;
		case 4:
			Delete();
			Menu();
			break;
		case 5:
			Sort();
			Menu();
			break;
		case 6:
			Print();
			Menu();
			break;
		case 7:
			Repair();
			Menu();
			break;
		case 8:
			SaveFile();
			Menu();
			break;
		case 9:
			exit(0);
	}
	}
}

void main()
{
	strcpy(s[1],"Kargozini");
	strcpy(s[2],"Hesabdari");
	strcpy(s[3],"Hamlo naghl");
	strcpy(s[4],"Anbar");
	LoadFile();
	Menu();
}