#include<iostream.h>
#include<conio.h>
///////////////////
void insert();
void ejtema();
void eshterak();
void tafazol();
void sort();
void search();
int menu();
///////////////////
int a[100],b[100],c[100];
int na,nb,index;
///////////////////
void main()
{
	while (1)
		if (!menu())
			break;
}
///////////////////
void InsertA()
{
	clrscr();
	int i=0,sw=0,j,num;
	index=1;
	cout<<"Tedad anasore A ra vared konid: ";
	cin>>na;
	cout<<"Azve 1:";
	cin>>a[i++];
	while (i<na)
	{
		cout<<"\nOzve "<<i+1<<":";
		cin>>num;
		sw=0;
		for (j=0;j<i;j++)
			if (a[j]==num)
				sw=1;
		if (sw==0)
			a[i++]=num;
		else
			cout<<"\nAdad tekrari ast";
	}
	cout<<"\nA = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}";
	getch();
}
////////////////////////////////////////
void InsertB()
{
	clrscr();
	int i=0,sw=0,j,num;
	cout<<"Tedad anasore B ra vared konid: ";
	cin>>nb;
	cout<<"Azve 1:";
	cin>>b[i++];
	while (i<nb)
	{
		cout<<"\nOzve "<<i+1<<":";
		cin>>num;
		sw=0;
		for (j=0;j<i;j++)
			if (b[j]==num)
				sw=1;
		if (sw==0)
			b[i++]=num;
		else
			cout<<"\nAdad tekrari ast";
	}
	cout<<"\nB = {";
	for (i=0;i<nb-1;i++)
		cout<<b[i]<<",";
	cout<<b[i]<<"}";
	getch();
}
/////////////////////////////////////////
void ejtema()
{
	clrscr();
	int nc=0,i,j,sw;
	cout<<"\nA = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}\n";
	cout<<"\nB = {";
	for (i=0;i<nb-1;i++)
		cout<<b[i]<<",";
	cout<<b[i]<<"}";

	for (i=0;i<na;i++)
		c[i]=a[i];
	nc=i;
	i=0;
	while (i<nb) {
		sw=0;
		for (j=0;j<nc;j++)
			if (c[j]==b[i])
				sw=1;
		if (sw==0)
			c[nc++]=b[i];
		i++;
	}
	if (index) {
	cout<<"\n\nA U B = {";
	for (i=0;i<nc-1;i++)
		cout<<c[i]<<",";
	cout<<c[i]<<"}"; }
	getch();
}
/////////////////////////////////////////
void eshterak()
{
	clrscr();
	int i,j,k=0;
	cout<<"\nA = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}\n";
	cout<<"\nB = {";
	for (i=0;i<nb-1;i++)
		cout<<b[i]<<",";
	cout<<b[i]<<"}";

	for (i=0;i<na;i++)
	{
		for (j=0;j<nb;j++)
			if (a[i]==b[j])
				c[k++]=a[i];
	}
	if (index){
	cout<<"\n\nA ï B = {";
	for (i=0;i<k-1;i++)
		cout<<c[i]<<",";
	cout<<c[i]<<"}"; }
	getch();
}
/////////////////////////////////////////
void tafazol()
{
	clrscr();
	int i,j,k=0,sw;
	cout<<"\nA = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}\n";
	cout<<"\nB = {";
	for (i=0;i<nb-1;i++)
		cout<<b[i]<<",";
	cout<<b[i]<<"}";

	for (i=0;i<na;i++)
	{
		sw=0;
		for (j=0;j<nb;j++)
			if (a[i]==b[j])
				sw=1;
		if (sw==0)
			c[k++]=a[i];
	}
	if (index) {
	cout<<"\n\nA - B = {";
	for (i=0;i<k-1;i++)
		cout<<c[i]<<",";
	cout<<c[i]<<"}"; }
	getch();
}
/////////////////////////////////////////
void sort()
{
	clrscr();
	int i,j,t;
	for (i=0;i<na;i++)
		for (j=0;j<na-1;j++)
			if (a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	if (index) {
	cout<<"\n\nSorted A = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}";  }
	getch();
}
/////////////////////////////////////////
void search()
{
	clrscr();
	int i,num,sw=0;
	cout<<"\n\nSorted A = {";
	for (i=0;i<na-1;i++)
		cout<<a[i]<<",";
	cout<<a[i]<<"}";
	cout<<"\n\nEnter A number to search in A { }:";
	cin>>num;
	for (i=0;i<na;i++)
		if (num==a[i])
			sw=1;
	if (sw==1)
		cout<<"Number Found...";
	else
		cout<<"Number Not found...";
	getch();
}
/////////////////////////////////////////
int menu()
{
	clrscr();
	int i,y=5;
	char ch;
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
	gotoxy(30,5); cout<<"1.Enter Anasore A { }";
	gotoxy(30,7); cout<<"2.Enter Anasore B { }";
	gotoxy(30,9); cout<<"3.A U B";
	gotoxy(30,11); cout<<"4.A ï B ";
	gotoxy(30,13); cout<<"5.A - B";
	gotoxy(30,15); cout<<"6.Sorting A { }";
	gotoxy(30,17); cout<<"7.Searching in A { }";
	gotoxy(30,19);  cout<<"8.Exit Program";
	gotoxy(25,5);
	cout<<"-->";
	ch=getch();
	while (ch!=27) { //harekate felesh '-->'
		gotoxy(25,y);
		cout<<"   ";
		if (ch==72) {
			y-=2;
			if (y<5) y=19;
		}
		else if (ch==80) {
			y+=2;
			if (y>19) y=5;
		}
		else if (ch==13) {
			if (y==5) {
				InsertA();
				return 1;
				}
			else if (y==7) {
				InsertB();
				return 1;
				}
			else if (y==9) {
				ejtema();
				return 1;
				}
			else if (y==11) {
				eshterak();
				return 1;
				}
			else if (y==13) {
				tafazol();
				return 1;
				}
			else if (y==15) {
				sort();
				return 1;
				}
			else if (y==17) {
				search();
				return 1;
				}
			else if (y==19)
				return 0;
		}
		gotoxy(25,y);
		cout<<"-->";
		ch=getch();
	}//end of while
	return 0;
}