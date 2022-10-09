#include<iostream.h>
#include<conio.h>
struct book {
	char name[20];
	char writer[20];
	char nasher[20];
	char gheymet[20];
	char  salechap[20];
	}b[100];
//////////////////////////////
int menu();
void insert();
void search(int);
void booksearch();
void writersearch();
void salsearch();
int i1;
//////////////////////////////
int menu()
{
	int n;
	clrscr();
	cout<<"1.Enter Data";
	cout<<"\n2.Search name book";
	cout<<"\n3.Search writer book";
	cout<<"\n4.search Sale enteshar";
	cout<<"\n5.Exit Library";
	cout<<"\n\nEnter 1..5: ";
	do {
	gotoxy(15,7);
	cin>>n;
	} while (n>5);
	return n;
}
///////////////////////////////////////
void main()
{       int n;
	while (1) {
	n=menu();
	if (n==1) insert();
	else search(n);
	if (n==5) break;
	}
}
///////////////////////////////////////
void insert()
{
	int i,y=4,n;
	clrscr();
	cout<<"Enter number of book: ";
	cin>>n;
	clrscr();
	gotoxy(1,1);
	cout<<"Name book    writer name     Nasher      gheymat        sale enteshar";
	gotoxy(1,2);
	for (i=1;i<80;cout<<"-",i++);
	for (i1=0;i1<n;i1++,y++) {
	gotoxy(1,y);
	cin>>b[i1].name;
	gotoxy(15,y);
	cin>>b[i1].writer;
	gotoxy(30,y);
	cin>>b[i1].nasher;
	gotoxy(45,y);
	cin>>b[i1].gheymet;
	gotoxy(60,y);
	cin>>b[i1].salechap;
	}
	getch();
}
///////////////////////////////////////
void search(int n)
{
	switch (n) {
		case 2: booksearch();
			break;
		case 3:writersearch();
			break;
		case 4:salsearch();
			break;
		}
}
/////////////////////////////////////////
void booksearch()
{
	char t[20],ch;
	clrscr();
	cout<<"Enter your book: ";
	gotoxy(1,2);
	ch=getch();
	int i=0;
	while (ch!=13) {
		t[i++]=ch;
		t[i]='\0';
		clrscr();
		gotoxy(1,1);
		cout<<"Enter your book: ";
		cout<<t;
		gotoxy(1,5);
		cout<<"Name book    writer name     Nasher         gheymat        sale enteshar";
		gotoxy(1,6);
		for (int i2=1;i2<=80;cout<<"-",i2++);
		for (int j=0;j<i1;j++){
			int sw=0;
			for (int k=0;k<i;k++)
				if (t[k]!=b[j].name[k])
					sw=1;
				if (sw==0) {
					cout<<b[j].name<<"\t\t";
					cout<<b[j].writer<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].salechap<<"\n\n";
					}
				}
		ch=getch();
		}
}
/////////////////////////////////////////
void writersearch()
{
	char t[20],ch;
	clrscr();
	cout<<"Enter your writer: ";
	gotoxy(1,2);
	ch=getch();
	int i=0;
	while (ch!=13) {
		t[i++]=ch;
		t[i]='\0';
		clrscr();
		gotoxy(1,1);
		cout<<"Enter your writer: ";
		cout<<t;
		gotoxy(1,5);
		cout<<"Name book    writer name     Nasher         gheymat        sale enteshar";
		gotoxy(1,6);
		for (int i2=1;i2<=80;cout<<"-",i2++);
		for (int j=0;j<i1;j++){
			int sw=0;
			for (int k=0;k<i;k++)
				if (t[k]!=b[j].writer[k])
					sw=1;
				if (sw==0) {
					cout<<b[j].name<<"\t\t";
					cout<<b[j].writer<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].salechap<<"\n\n";
					}
				}
		ch=getch();
		}
}
/////////////////////////////////////////
void salsearch()
{
	char t[20],ch;
	clrscr();
	cout<<"Enter your sal: ";
	gotoxy(1,2);
	ch=getch();
	int i=0;
	while (ch!=13) {
		t[i++]=ch;
		t[i]='\0';
		clrscr();
		gotoxy(1,1);
		cout<<"Enter your sal: ";
		cout<<t;
		gotoxy(1,5);
		cout<<"Name book    writer name     Nasher         gheymat        sale enteshar";
		gotoxy(1,6);
		for (int i2=1;i2<=80;cout<<"-",i2++);
		for (int j=0;j<i1;j++){
			int sw=0;
			for (int k=0;k<i;k++)
				if (t[k]!=b[j].salechap[k])
					sw=1;
				if (sw==0) {
					cout<<b[j].name<<"\t\t";
					cout<<b[j].writer<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].nasher<<"\t\t";
					cout<<b[j].salechap<<"\n\n";
					}
				}
		ch=getch();
		}

}
