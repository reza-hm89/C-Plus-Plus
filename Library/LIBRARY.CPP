#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
/////////////////////////////
struct member {
	int code;
	char name[30];
	};
////////////////////////////
struct book {
	int code;
	int state;
	char name[30];
	char writer[30];
	};
////////////////////////////
struct date {
	int day;
	int month;
	int year;
	};
////////////////////////////
struct taken {
	int bcode[50];
	int mcode;
	char mname[20];
	char bname[20][20];
	date borrow[20];
	date returning[20];
	};
/////////////////////////////////
taken	t[50];
book	b[50];
int	numbook[100];
int 	inc;
/////////////////////////////////
void mem_menu();
void mem_add();
void mem_edit();
void mem_delete();
void MEMBER();
void book_menu();
void book_add();
void book_delete();
void book_edit();
void BOOK();
void borrowing();
void returning();
void searching();
void reporting();
void saveinfile();
int menu();
/////////////////////////////////
int menu()
{
	clrscr();
	int i,y=5;
	char ch;
	textcolor(15);
	for (i=20;i<=60;i++) //rasme kadre ofoghi
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for (i=3;i<=22;i++) //rasme kadre amoodi
	{
		gotoxy(20,i);
		cout<<"º";
		gotoxy(60,i);
		cout<<"º";
	}
	//chape menu//
	gotoxy(20,3); cout<<"É";
	gotoxy(60,3); cout<<"»";
	gotoxy(20,22); cout<<"È";
	gotoxy(60,22); cout<<"¼";
	gotoxy(35,5); cout<<"1.Member";
	gotoxy(35,7); cout<<"2.Book";
	gotoxy(35,9); cout<<"3.Borrow Book";
	gotoxy(35,11); cout<<"4.Return Book";
	gotoxy(35,13); cout<<"5.Searching";
	gotoxy(35,15); cout<<"6.Reporting";
	gotoxy(35,17); cout<<"7.Exit Library";
	gotoxy(30,5);  cout<<"-->";
	ch=getch();
	while (ch!=27) { //harekate felesh '-->'
		gotoxy(30,y);
		cout<<"   ";
		if (ch==72) {
			y-=2;
			if (y<5) y=17;
		}
		else if (ch==80) {
			y+=2;
			if (y>17) y=5;
		}
		else if (ch==13) {
			if (y==5) {
				mem_menu();
				return 1;
				}
			else if (y==7) {
				book_menu();
				return 1;
				}
			else if (y==9) {
				borrowing();
				return 1;
				}
			else if (y==11) {
				returning();
				return 1;
				}
			else if (y==13) {
				searching();
				return 1;
				}
			else if (y==15) {
				reporting();
				return 1;
				}
			else if (y==17) {
				saveinfile();
				return 0;
				}
		}
		gotoxy(30,y);
		cout<<"-->";
		ch=getch();
	}//end of while
	return 0;
}
////////////////////////////////
void main()
{
	clrscr();
	while(1)
		if(!menu())
			break;
}
////////////////////////////////
void mem_menu()
{
	int n;
	clrscr();
	cout<<"\n1.Add Member";
	cout<<"\n2.Delete Member";
	cout<<"\n3.Edit Member";
	cout<<"\n4.Show Members";
	cout<<"\n\nEnter Number(1..4):";
	do {
		gotoxy(20,7);
		cout<<"                   ";
		gotoxy(20,7);
		cin>>n;
	} while (n>4);
	if (n==1)
		mem_add();
	else if (n==2)
		mem_delete();
	else if (n==3)
		mem_edit();
	else
		MEMBER();
}
/////////////////////////////////
void mem_add()
{
	clrscr();
	int code,sw=0;
	member mb;
	cout<<"Enter your code to Add:";
	cin>>code;
	fstream fp("member.dat",ios::in | ios::binary);
	while (!fp.eof()) {
		fp.read((char *)&mb,sizeof(struct member));
		if (code==mb.code)
		{
			cout<<"Exist";
			getch();
			sw=1;
		}
	}
	if (!sw)
	{
		fstream fp1("member.dat",ios::out|ios::app | ios::binary);
		cout<<"Enter your name:";
		cin>>mb.name;
		mb.code=code;
		fp1.seekp(sizeof(struct member)*mb.code,ios::beg);
		fp1.write((char *)&mb,sizeof(struct member));
		fp1.close();
	}
	getch();
	fp.close();
	return;
}
////////////////////////////////
void mem_delete()
{
	clrscr();
	int code;
	member mb;
	ifstream fp("member.dat",ios::in | ios::binary);
	ofstream fp1("temp.dat",ios::out | ios::binary);
	cout<<"Enter your code to delete:";
	cin>>code;
	while (!fp.eof()) {
		fp.read((char *)&mb,sizeof(struct member));
		if (code!=mb.code)
			fp1.write((char *)&mb,sizeof(struct member));
	}
	remove("member.dat");
	rename("temp.dat","member.dat");
	fp.close();
	fp1.close();
	getch();
}
////////////////////////////////
void mem_edit() {
	clrscr();
	int code;
	member mb;
	ifstream fp("member.dat",ios::in | ios::binary);
	ofstream fp1("temp.dat",ios::out | ios::binary);
	cout<<"Enter your code to Edit:";
	cin>>code;
	while (!fp.eof()) {
		fp.read((char *)&mb,sizeof(struct member));
		if (code==mb.code)
		{
			cout<<"Enter new name: ";
			cin>>mb.name;
		}
			fp1.write((char *)&mb,sizeof(struct member));
	}
	remove("member.dat");
	rename("temp.dat","member.dat");
	fp.close();
	fp1.close();
	getch();
}
///////////////////////////////
void MEMBER()
{
	clrscr();
	member mb;
	int y=4;
	fstream fp("member.dat",ios::in | ios::out | ios::binary);
	cout<<"Member Name              code";
	gotoxy(1,2);
	for (int i=1;i<=80;cout<<"-",i++);
	while (fp.read((char *)&mb,sizeof(struct member))) {
		gotoxy(1,y);
		cout<<mb.name;
		gotoxy(27,y);
		cout<<mb.code;
		y++;
	}
	fp.close();
	getch();
}
///////////////////////////////
void book_menu()
{
	int n;
	clrscr();
	cout<<"\n1.Add Book";
	cout<<"\n2.Delete Book";
	cout<<"\n3.Edit Book";
	cout<<"\n4.Show Books";
	cout<<"\n\nEnter Number(1..4):";
	do {
		gotoxy(20,7);
		cout<<"                   ";
		gotoxy(20,7);
		cin>>n;
	} while (n>4);
	if (n==1)
		book_add();
	else if (n==2)
		book_delete();
	else if (n==3)
		book_edit();
	else
		BOOK();
}
/////////////////////////////////
void book_add()
{
	clrscr();
	int code,sw=0;
	book bk;
	cout<<"Enter your code to Add:";
	cin>>code;
	fstream fp("book.dat",ios::in | ios::binary);
	while (!fp.eof()) {
		fp.read((char *)&bk,sizeof(struct book));
		if (code==bk.code)
		{
			cout<<"Exist";
			getch();
			sw=1;
		}
	}
	if (!sw)
	{
		fstream fp1("book.dat",ios::out|ios::app | ios::binary);
		cout<<"Enter your name Book:\n";
		cin>>bk.name;
		cout<<"\nEnter Writer Name:\n";
		cin>>bk.writer;
		bk.code=code;
		fp1.seekp(sizeof(struct member)*bk.code,ios::beg);
		fp1.write((char *)&bk,sizeof(struct book));
		fp1.close();
	}
	getch();
	fp.close();
	return;
}

/////////////////////////////////
void book_delete()
{
	clrscr();
	int code;
	book bk;
	ifstream fp("book.dat",ios::in | ios::binary);
	ofstream fp1("temp.dat",ios::out | ios::binary);
	cout<<"Enter your code to delete Book:";
	cin>>code;
	while (!fp.eof()) {
		fp.read((char *)&bk,sizeof(struct book));
		if (code!=bk.code)
			fp1.write((char *)&bk,sizeof(struct book));
	}
	remove("book.dat");
	rename("temp.dat","book.dat");
	fp.close();
	fp1.close();
	getch();
}
/////////////////////////////////
void book_edit()
{
	clrscr();
	int code;
	book bk;
	ifstream fp("book.dat",ios::in | ios::binary);
	ofstream fp1("temp.dat",ios::out | ios::binary);
	cout<<"Enter your code to Edit Book:";
	cin>>code;
	while (!fp.eof()) {
		fp.read((char *)&bk,sizeof(struct book));
		if (code==bk.code)
		{
			cout<<"Enter new Book name:\n";
			cin>>bk.name;
			cout<<"Enter writer Book:\n";
			cin>>bk.writer;
		}
		fp1.write((char *)&bk,sizeof(struct book));
	}
	remove("book.dat");
	rename("temp.dat","book.dat");
	fp.close();
	fp1.close();
	getch();

}
/////////////////////////////////
void BOOK()
{
	clrscr();
	book bk;
	int y=4;
	ifstream fp1("book.dat",ios::in | ios::binary);
	cout<<"Book name            Writer            code              state";
	gotoxy(1,2);
	for (int i=1;i<=80;cout<<"-",i++);
	while(fp1.read((char *)&bk,sizeof(struct book)))
	{
	gotoxy(1,y);
	cout<<bk.name;
	gotoxy(22,y);
	cout<<bk.writer;
	gotoxy(41,y);
	cout<<bk.code;
	gotoxy(60,y);
	cout<<b[bk.code].state;
	y++;
	}
	fp1.close();
	getch();
}
////////////////////////////////
void borrowing()
{
	clrscr();
	int code,sw=0,p;
	int day,month,year;
	int tc;
	char tn[10];
	member mb;
	book bk;
	ifstream fp("member.dat",ios::binary);
	ifstream fp1("book.dat",ios::binary);
	cout<<"Enter your code to borrow a book:";
	cin>>code;
	while (!fp.eof()) {
		fp.read((char *)&mb,sizeof(struct member));
		if (mb.code==code) {
			mb.code=code;
			tc=mb.code;
			strcpy(tn,mb.name);
			sw=1;
			p=mb.code;
		}
	}//end of while fp
	if (sw==1) {
		BOOK();
		cout<<"\n\n\nEnter your code book to borrow:";
		cin>>code;
	while (!fp1.eof()) {
		fp1.read((char *)&bk,sizeof(struct book));
		if ((bk.code==code) && (b[code].state==0)) {

			numbook[bk.code]++;
			t[p].mcode=tc;
			strcpy(t[p].mname,tn);
			bk.code=code;
			t[p].bcode[inc]=bk.code;
			strcpy(t[p].bname[inc],bk.name);
			strcpy(b[bk.code].name,bk.name);
			b[bk.code].state=1;
			sw=2;
		}
	}//end of while fp1
	if(sw==2) {
		cout<<"\nEnter borrowing date:\n";
		cout<<"Day(1-30): ";
		cin>>day;
		cout<<"\nMonth(1-12): ";
		cin>>month;
		cout<<"\nYear(1000-9999): ";
		cin>>year;
		t[p].borrow[inc].day=day;
		t[p].borrow[inc].month=month;
		t[p].borrow[inc].year=year;
		inc++;
		}//end of sw==2
	}//end of if sw==1
	else
		cout<<"Not find...";
	getch();
}
////////////////////////////////
void returning()
{
	clrscr();
	int mcode,bcode,i,y=3,j=0,k=0;
	cout<<"Enter your code and book code to Return the book: ";
	cin>>mcode>>bcode;
	if (t[mcode].mcode!=mcode)  {
		cout<<"your code if False..." ;
		getch();
		return;
		}
	if (b[bcode].state==0)  {
		cout<<"The book has not been borrowed...\n";
		getch();
		return;
		}
	clrscr();
	cout<<"\nMem code     Mem Name        B.code     B.name           Borrow date";
	gotoxy(1,2);
	for (i=1;i<=80;cout<<"-",i++);
	for (i=0;i<50;i++) {
		if ( t[i].mcode==mcode) {
			gotoxy(1,y);
			cout<<t[i].mcode;
			gotoxy(15,y);
			cout<<t[i].mname;
			gotoxy(30,y);
			while (1) {
			if (t[i].bcode[j]==bcode) {
			cout<<t[i].bcode[j];
			gotoxy(41,y);
			cout<<t[i].bname[j];
			gotoxy(60,y);
			cout<<t[i].borrow[j].day<<"\\";
			cout<<t[i].borrow[j].month<<"\\";
			cout<<t[i].borrow[j].year;
			b[bcode].state=0;
			break;
			}
			j++;  }
		} }
	gotoxy (1,y);
	//while (1) {
       //	if (!t[mcode].returning[k].day)  {
	cout<<"\nEnter returning date: ";
	cout<<"\nDay: ";
	cin>>t[mcode].returning[j].day;
	cout<<"\nmonth: ";
	cin>>t[mcode].returning[j].month;
	cout<<"\nYear: ";
	cin>>t[mcode].returning[j].year;
      //	break;
      //	}
       //	k++;  }
	getch();
}
////////////////////////////////
void searching()
{
	clrscr();
	int i;
	cout<<"Number of borrowing Book:\n";
	for (i=0;i<50;i++) {
		if (numbook[i]) {
			cout<<b[i].name<<"\t";
			cout<<numbook[i]<<endl;
			}
		}
	getch();
}
///////////////////////////////
void reporting()
{
	clrscr();
	int i,j=0,k=0,y=3;
	cout<<"Mem code     Mem Name        B.code     B.name      Borrow date   return date";
	gotoxy(1,2);
	for (i=1;i<=80;cout<<"-",i++);
	for (i=0;i<30;i++)
	{
		if(t[i].mcode)
		{
		while (t[i].bcode[j]) {
			gotoxy(1,y);
			cout<<t[i].mcode;
			gotoxy(15,y);
			cout<<t[i].mname;
			gotoxy(30,y);
			cout<<t[i].bcode[j];
			gotoxy(41,y);
			cout<<t[i].bname[j];
			gotoxy(56,y);
			cout<<t[i].borrow[j].day<<"\\";
			cout<<t[i].borrow[j].month<<"\\";
			cout<<t[i].borrow[j].year;
			gotoxy(70,y);
			cout<<t[i].returning[k].day<<"\\";
			cout<<t[i].returning[k].month<<"\\";
			cout<<t[i].returning[k].year;
			k++;
			j++;
			y++;
		}
		}
	}
	getch();
}
/////////////////////////////////////
void saveinfile()
{
	ofstream fp("taken.dat",ios::binary);
	for (int i=0;i<50;i++)
	{
		fp.seekp(sizeof(struct taken)*i,ios::beg);
		fp.write((char *)&t,sizeof(struct taken));
	}
	fp.close();
}