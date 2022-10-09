#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<fstream.h>

int i=1,k;
char s[20];
fstream f;
////////////////
struct Data
{
	char Name[30];
	long int Cod;
	char Tsaakht[20];
	char Tnamayesh[20];
	char TfTekrar[20];
	int Cnt;//tedad tekrar
	char Sazande[30];
	int Shabake;
	char No[15];//noe barname

};
struct TreeNode
{
	Data data;
	TreeNode *left,*right;
};
/////////////
class Bst
{
	public:
		TreeNode *root;
		Bst();
		void Menu();
		void Add();
		void SortCode(TreeNode *cur);
		TreeNode* Bst::SearchCode();
		void Edit();
		void Del();
		void Search();
		void STnamayesh();
		void STfTekrar();
		void ShowTmoshakhas();
		void InOrderT(TreeNode *cur);
		void ShowBshabake();
		void InOrderSH(TreeNode *cur);
		void ShowBsazande();
		void InOrderS(TreeNode *cur);
		void ShowBnBaar();
		void InOrderN(TreeNode *cur);
		void Save(TreeNode *cur);
		void Load();
};
//////////////////////////////////////
Bst::Bst()
{
	root=NULL;
}
/////////////////////////////////////////
///////////////////////////////////////
void Bst::Menu()
{
	clrscr();
	window(0,0,79,49);
	textcolor(15);
	gotoxy(25,15);
	cprintf("Ezaafe kardane barname");
	gotoxy(25,17);
	cprintf("Virayeshe ettelaate barname");
	gotoxy(25,19);
	cprintf("Hazfe barname");
	gotoxy(25,21);
	cprintf("Jostojoo");
	gotoxy(25,23);
	cprintf("Sabte tarikhe namaayeshe barnaame");
	gotoxy(25,25);
	cprintf("Sabte tarikhe namayeshe avvalin tekrar");
	gotoxy(25,27);
	cprintf("Chappe morattabe barnaameha");
	gotoxy(25,29);
	cprintf("Chappe barnaamehaye ye tarikhe moshakhas");
	gotoxy(25,31);
	cprintf("Chape barnamehaye yek shabake");
	gotoxy(25,33);
	cprintf("Chape barnamehye marboot be ye saazande");
	gotoxy(25,35);
	cprintf("Chape barnamehaye N bar tekrar shode");
	gotoxy(25,37);
	cprintf("Exit");
	textcolor(1);
	gotoxy(22,15);
	cprintf("->");
	char ch;
	int y=15;
	while (1)
	{
	     ch=getch();
	     if (!ch)
		ch=getch();
	     gotoxy(22,y);
	     cprintf("  ");
	     if (ch==72)
		y-=2;
	     if (ch==80)
		y+=2;
	     if (y>37)
		y=15;
	     if (y<15)
		y=37;
	     gotoxy(22,y);
	     cprintf("->");
	     if (ch==13 && y==15)
	     {
		Add();
		return;
	     }
	     else if (ch==13 && y==17)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		Edit();
		Menu();
		return;
	     }
	     else if (ch==13 && y==19)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		Del();
	     }
	     else if (ch==13 && y==21)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		Search();
	     }
	     else if (ch==13 && y==23)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		STnamayesh();
	     }
	     else if (ch==13 && y==25)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		STfTekrar();
	     }
	     else if (ch==13 && y==27)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		i=3;
		SortCode(root);
		getch();
		Menu();
	     }
	     else if (ch==13 && y==29)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		ShowTmoshakhas();
	     }
	     else if (ch==13 && y==31)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		ShowBshabake();
	     }
	     else if (ch==13 && y==33)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		ShowBsazande();
	     }
	     else if (ch==13 && y==35)
	     {
		clrscr();
		textcolor(15);
		clrscr();
		ShowBnBaar();
	     }
	     else if (ch==13 && y==37)
	     {
		f.open("tv.dat",ios::out | ios::binary | ios::beg);
		Save(root);
		f.close();
		exit(0);
	     }

	}
}
////////////////////////////////////////
void Bst::Add()
{
	textcolor(15);
	clrscr();
	textcolor(15);
	textcolor(14);
	TreeNode *newnode;
	newnode=new TreeNode;
	cprintf("Ezaafe Kardane Barnameye Jadid");
	gotoxy(1,1);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(1,2);
	cprintf("NaameBarname:");
	gets(newnode->data.Name);
	gotoxy(1,3);
	cprintf("Cod:");
	cin>>newnode->data.Cod;
	gotoxy(1,4);
	cprintf("Tarikhe saakht:");
	gets(newnode->data.Tsaakht);
	gotoxy(1,5);
	cprintf("Tarikhe namayesh:");
	gets(newnode->data.Tnamayesh);
	gotoxy(1,6);
	cprintf("Tarikhe Avalin Tekrar:");
	gets(newnode->data.TfTekrar);
	gotoxy(1,7);
	cprintf("Tedad Tekrar:");
	cin>>newnode->data.Cnt;
	gotoxy(1,8);
	cprintf("Naame Sazande:");
	gets(newnode->data.Sazande);
	gotoxy(1,9);
	cprintf("Shabakeye Namayesh:");
	cin>>newnode->data.Shabake;
	gotoxy(1,10);
	cprintf("Noe barnaame:");
	gets(newnode->data.No);
	//////
	TreeNode *p,*q;
	p=root;
	q=NULL;
	int x=newnode->data.Cod;
	while (p)
	{
		q=p;
		if (p->data.Cod<x)
			p=p->right;
		else
			p=p->left;
	}
	p=new TreeNode;
	p=newnode;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->data.Cod <x)
		q->right=p;
	else
		q->left=p;


Menu();
}
///////////////////////////////////////
void Bst::SortCode(TreeNode *cur)
{
	if (cur)
	{
		SortCode(cur->left);

		delay(200);
		if (i>34)
		{
		gotoxy(30,49);
		cprintf("Press Enter For Next Page");
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=3;
		}
		textcolor(15);
		gotoxy(1,i++);
		cprintf("Code:");
		cout<<cur->data.Cod;
		gotoxy(1,i++);
		cprintf("Name:");
		cout<<cur->data.Name;
		gotoxy(1,i++);
		cprintf("Tarikhe saakht:");
		cout<<cur->data.Tsaakht;
		gotoxy(1,i++);
		cprintf("Tarikhe namayesh:");
		cout<<cur->data.Tnamayesh;
		gotoxy(1,i++);
		cprintf("Tarikhe avvalin tekrar:");
		puts(cur->data.TfTekrar);
		gotoxy(1,i++);
		cprintf("Tedad tekrar:");
		cout<<cur->data.Cnt;
		gotoxy(1,i++);
		cprintf("Saazande:");
		cout<<cur->data.Sazande;
		gotoxy(1,i++);
		cprintf("Shabake:");
		cout<<cur->data.Shabake;
		gotoxy(1,i++);
		cprintf("Noe barname:");
		cout<<cur->data.No;
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");

		SortCode(cur->right);
	}
}
////////////////////////////////////////
TreeNode* Bst::SearchCode()
{
int Scod;
textcolor(14);
cprintf("Enter Code:");
cin>>Scod;
gotoxy(1,2);
cprintf("ออออออออออออออออออออออออออออออออออออออออออออ");
TreeNode *p=root;
while (p)
{
	if (p->data.Cod==Scod)
		return p;
	if (p->data.Cod < Scod)
		p=p->right;
	else
		p=p->left;
}
textcolor(4);
gotoxy(1,3);
cprintf("not found");
getch();
Menu();
return NULL;
}
/////////////////////////////////////////
void Bst::Edit()
{
TreeNode *cur;
cur=new TreeNode;
cur=NULL;
cur=SearchCode();
if(!cur)
	return;
textcolor(13);
gotoxy(10,15);
cprintf("1.Name barname:");
cout<<cur->data.Name;
gotoxy(10,16);
cprintf("2.Tarikhe saakht:");
cout<<cur->data.Tsaakht;
gotoxy(10,17);
cprintf("3.Tarikhe namayesh:");
cout<<cur->data.Tnamayesh;
gotoxy(10,18);
cprintf("4.Tarikhe avvalin tekrar:");
puts(cur->data.TfTekrar);
gotoxy(10,19);
cprintf("5.Tedad tekrar:");
cout<<cur->data.Cnt;
gotoxy(10,20);
cprintf("6.Saazande:");
cout<<cur->data.Sazande;
gotoxy(10,21);
cprintf("7.Shabake:");
cout<<cur->data.Shabake;
gotoxy(10,22);
cprintf("8.Noe barname:");
cout<<cur->data.No;
int select=20;
while (select!=-1)
{
gotoxy(10,25);
cprintf("9.Shomareye filde morede nazar ra vared konid(-1:exit) :         ");
gotoxy(67,25);
cin>>select;
while (select>9 || select<1 && select!=-1)
{
	gotoxy(67,25);
	cprintf("      ");
	gotoxy(67,25);
	cin>>select;
}
gotoxy(10,26);
cprintf("                                     ");
gotoxy(10,26);
switch (select){
case 1:
	cprintf("jadide barname:");
	gets(cur->data.Name);
	break;
case 2:
	cprintf("Tarikhe saakht:");
	gets(cur->data.Tsaakht);
	break;
case 3:
	cprintf("Tarikhe namayesh:");
	gets(cur->data.Tnamayesh);
	break;
case 4:
	cprintf("Tarikhe avvalin tekrar:");
	gets(cur->data.TfTekrar);
	break;
case 5:
	cprintf("Tedad tekrar:");
	cin>>cur->data.Cnt;
	break;
case 6:
	cprintf("Sazandeye barname:");
	gets(cur->data.Sazande);
	break;
case 7:
	cprintf("Shabake:");
	cin>>cur->data.Shabake;
	break;
case 8:
	cprintf("Noe barname:");
	gets(cur->data.No);
	break;
case -1:
	Menu();
	return;
}
}//While
}
/////////////////////////////////////
void Bst::Del()
{
int found=0,code;
clrscr();
TreeNode *cur,*q;
cprintf("Cod ra vared konid: ");
cin>>code;
cur=root;
if(!cur)
{
	cprintf("List Khali ast");
	getch();
	Menu();
	return;
}
while(cur)
{
	if(cur->data.Cod == code)
	{
		found = 1;
		break;
	}
	else
	{
		q=cur;
		if(cur->data.Cod<code)
			cur=cur->right;
		else
			cur=cur->left;
	}
}
if(!found)
{
	textcolor(4);
	gotoxy(1,3);
	cprintf("not found!");
	getch();
	Menu();
	return;
}
textcolor(4);
gotoxy(1,3);
cprintf("Deleted");
getch();
//agar cur barg bashad
if( cur->left == NULL && cur->right == NULL)
{
	if(q->left == cur)
		q->left = NULL;
	else
		q->right = NULL;
	delete cur;
	Menu();
	return;
}
//////////
if((cur->left == NULL && cur->right != NULL)|| (cur->left != NULL && cur->right == NULL))
{
	//1 farzande rast dashte bashad
	if(cur->left == NULL && cur->right != NULL)
	{
		if(q->left == cur)
		{
			q->left = cur->right;
			delete cur;
		}
		else
		{
			q->right = cur->right;
			delete cur;
		}
	}
	else // 1 farzande chap dashte bashad
	{
		if(q->left == cur)
		{
			q->left = cur->left;
			delete cur;
		}
		else
		{
			q->right = cur->left;
			delete cur;
		}
	}
	Menu();
	return;
}
////////////////
//2 farzand dashte bashad (ba koochektarine samte rast avaz mishavad
if (cur->left != NULL && cur->right != NULL)
{
	TreeNode *CurR;
	CurR=cur->right;
	if((CurR->left==NULL) && (CurR->right == NULL))
	{
		cur=CurR;
		delete CurR;
		cur->right=NULL;
	}
	else // agar samte rasti farzand dashte bashad
	{
	//agar in samte rasti farzande chap dashte bashad
	// peida kardane koochektarine samte chap
	if((cur->right)->left != NULL)
	{
		TreeNode *hlp1;       //lcurr=hlp1
		TreeNode *hlp2;     //lcurrp=hlp2
		hlp2=cur->right;
		hlp1=(cur->right)->left;
		while(hlp1->left!=NULL)
		{
			hlp2=hlp1;
			hlp1=hlp1->left;
		}
		cur->data=hlp1->data;
		delete hlp1;
		hlp2->left = NULL;
	}
	else
	{
		TreeNode *temp;
		temp=cur->right;
		cur->data=temp->data;
		cur->right=temp->right;
		delete temp;
	}
	}//else
	return;
}
}
///////////////////////////////////////
void Bst::Search()
{
TreeNode *cur;
cur=new TreeNode;
cur=NULL;
cur=SearchCode();
if(!cur)
	return;
textcolor(13);
gotoxy(1,3);
cprintf("Name barname:");
cout<<cur->data.Name;
gotoxy(1,4);
cprintf("Tarikhe saakht:");
cout<<cur->data.Tsaakht;
gotoxy(1,5);
cprintf("Tarikhe namayesh:");
cout<<cur->data.Tnamayesh;
gotoxy(1,6);
cprintf("Tarikhe avvalin tekrar:");
puts(cur->data.TfTekrar);
gotoxy(1,7);
cprintf("Tedad tekrar:");
cout<<cur->data.Cnt;
gotoxy(1,8);
cprintf("Saazande:");
cout<<cur->data.Sazande;
gotoxy(1,9);
cprintf("Shabake:");
cout<<cur->data.Shabake;
gotoxy(1,10);
cprintf("Noe barname:");
cout<<cur->data.No;
getch();
Menu();
}
///////////////////////////////////////
void Bst::STnamayesh()
{
TreeNode *cur;
cur=new TreeNode;
cur=NULL;
cur=SearchCode();
if(!cur)
	return;
textcolor(13);
gotoxy(1,3);
cprintf("Tatikhe namayesh ra vared konid:");
cin>>cur->data.Tnamayesh;
gotoxy(1,5);
textcolor(4);
cprintf("Saved");
getch();
Menu();
}
/////////////////////////////////////////
void Bst::STfTekrar()
{
TreeNode *cur;
cur=new TreeNode;
cur=NULL;
cur=SearchCode();
if(!cur)
	return;
textcolor(13);
gotoxy(1,3);
cprintf("Tatikhe avvalin tekrar ra vared konid:");
cin>>cur->data.TfTekrar;
gotoxy(1,5);
textcolor(4);
cprintf("Saved");
getch();
Menu();
}

/////////////////////////////////////////
void Bst::ShowTmoshakhas()
{
clrscr();
textcolor(15);
clrscr();
cprintf("Tarikh ra vared konid(ba formate vared shode):");
gets(s);
i=3;
InOrderT(root);
getch();
Menu();
}
////////////////////////////////////////
void Bst::InOrderT(TreeNode *cur)
{
	if (cur)
	{
		InOrderT(cur->left);
		if (strcmp(cur->data.Tnamayesh,s)==0)
		{
		if (i>34)
		{
		gotoxy(30,49);
		cprintf("Press Enter For Next Page");
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=3;
		}
		textcolor(15);
		gotoxy(1,i++);
		cprintf("Code:");
		cout<<cur->data.Cod;
		gotoxy(1,i++);
		cprintf("Name:");
		cout<<cur->data.Name;
		gotoxy(1,i++);
		cprintf("Tarikhe saakht:");
		cout<<cur->data.Tsaakht;
		gotoxy(1,i++);
		cprintf("Tarikhe namayesh:");
		cout<<cur->data.Tnamayesh;
		gotoxy(1,i++);
		cprintf("Tarikhe avvalin tekrar:");
		puts(cur->data.TfTekrar);
		gotoxy(1,i++);
		cprintf("Tedad tekrar:");
		cout<<cur->data.Cnt;
		gotoxy(1,i++);
		cprintf("Saazande:");
		cout<<cur->data.Sazande;
		gotoxy(1,i++);
		cprintf("Shabake:");
		cout<<cur->data.Shabake;
		gotoxy(1,i++);
		cprintf("Noe barname:");
		cout<<cur->data.No;
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		}
		InOrderT(cur->right);
	}
}
/////////////////////////////////
void Bst::ShowBshabake()
{
clrscr();
textcolor(15);
clrscr();
cprintf("Shomare shabake ra vared konid:");
cin>>k;
i=3;
InOrderSH(root);
getch();
Menu();
}
////////////////////////////////////////
void Bst::InOrderSH(TreeNode *cur)
{
	if (cur)
	{
		InOrderSH(cur->left);
		if (cur->data.Shabake==k)
		{
		if (i>34)
		{
		gotoxy(30,49);
		cprintf("Press Enter For Next Page");
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=3;
		}
		textcolor(15);
		gotoxy(1,i++);
		cprintf("Code:");
		cout<<cur->data.Cod;
		gotoxy(1,i++);
		cprintf("Name:");
		cout<<cur->data.Name;
		gotoxy(1,i++);
		cprintf("Tarikhe saakht:");
		cout<<cur->data.Tsaakht;
		gotoxy(1,i++);
		cprintf("Tarikhe namayesh:");
		cout<<cur->data.Tnamayesh;
		gotoxy(1,i++);
		cprintf("Tarikhe avvalin tekrar:");
		puts(cur->data.TfTekrar);
		gotoxy(1,i++);
		cprintf("Tedad tekrar:");
		cout<<cur->data.Cnt;
		gotoxy(1,i++);
		cprintf("Saazande:");
		cout<<cur->data.Sazande;
		gotoxy(1,i++);
		cprintf("Shabake:");
		cout<<cur->data.Shabake;
		gotoxy(1,i++);
		cprintf("Noe barname:");
		cout<<cur->data.No;
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		}
		InOrderSH(cur->right);
	}
}
/////////////////////////////////
void Bst::ShowBsazande()
{
clrscr();
textcolor(15);
clrscr();
cprintf("Name sazande ra vared konid:");
gets(s);
i=3;
InOrderS(root);
getch();
Menu();
}
////////////////////////////////////////
void Bst::InOrderS(TreeNode *cur)
{
	if (cur)
	{
		InOrderS(cur->left);
		if (strcmp(cur->data.Sazande,s)==0)
		{
		if (i>34)
		{
		gotoxy(30,49);
		cprintf("Press Enter For Next Page");
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=3;
		}
		textcolor(15);
		gotoxy(1,i++);
		cprintf("Code:");
		cout<<cur->data.Cod;
		gotoxy(1,i++);
		cprintf("Name:");
		cout<<cur->data.Name;
		gotoxy(1,i++);
		cprintf("Tarikhe saakht:");
		cout<<cur->data.Tsaakht;
		gotoxy(1,i++);
		cprintf("Tarikhe namayesh:");
		cout<<cur->data.Tnamayesh;
		gotoxy(1,i++);
		cprintf("Tarikhe avvalin tekrar:");
		puts(cur->data.TfTekrar);
		gotoxy(1,i++);
		cprintf("Tedad tekrar:");
		cout<<cur->data.Cnt;
		gotoxy(1,i++);
		cprintf("Saazande:");
		cout<<cur->data.Sazande;
		gotoxy(1,i++);
		cprintf("Shabake:");
		cout<<cur->data.Shabake;
		gotoxy(1,i++);
		cprintf("Noe barname:");
		cout<<cur->data.No;
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		}
		InOrderS(cur->right);
	}
}
////////////////////////////////////
void Bst::ShowBnBaar()
{
clrscr();
textcolor(15);
clrscr();
cprintf("N ra vared konid:");
cin>>k;
i=3;
InOrderN(root);
getch();
Menu();
}
////////////////////////////////////////
void Bst::InOrderN(TreeNode *cur)
{
	if (cur)
	{
		InOrderN(cur->left);
		if (cur->data.Cnt==k)
		{
		if (i>34)
		{
		gotoxy(30,49);
		cprintf("Press Enter For Next Page");
		char ch;
		ch=getch();
		while (ch!=13)
			ch=getch();
		clrscr();
		i=3;
		}
		textcolor(15);
		gotoxy(1,i++);
		cprintf("Code:");
		cout<<cur->data.Cod;
		gotoxy(1,i++);
		cprintf("Name:");
		cout<<cur->data.Name;
		gotoxy(1,i++);
		cprintf("Tarikhe saakht:");
		cout<<cur->data.Tsaakht;
		gotoxy(1,i++);
		cprintf("Tarikhe namayesh:");
		cout<<cur->data.Tnamayesh;
		gotoxy(1,i++);
		cprintf("Tarikhe avvalin tekrar:");
		puts(cur->data.TfTekrar);
		gotoxy(1,i++);
		cprintf("Tedad tekrar:");
		cout<<cur->data.Cnt;
		gotoxy(1,i++);
		cprintf("Saazande:");
		cout<<cur->data.Sazande;
		gotoxy(1,i++);
		cprintf("Shabake:");
		cout<<cur->data.Shabake;
		gotoxy(1,i++);
		cprintf("Noe barname:");
		cout<<cur->data.No;
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		}
		InOrderN(cur->right);
	}
}
///////////////////////////////////////
void Bst::Save(TreeNode *cur)
{
	if (cur)
	{
		Save(cur->left);
		f.write((char *)&(cur->data),sizeof(struct TreeNode));
		Save(cur->right);
	}
}
/////////////////////////////////////////
void Bst::Load()
{
	TreeNode *newnode;
	newnode=new TreeNode;
	while (f.read((char *)&(newnode->data),sizeof (struct TreeNode)))
	{
		TreeNode *p,*q;
		p=root;
		q=NULL;
		int x=newnode->data.Cod;
		while (p)
		{
			q=p;
			if (p->data.Cod<x)
				p=p->right;
			else
				p=p->left;
		}
		p=new TreeNode;
		p=newnode;
		p->left=p->right=NULL;
		if (!root)
			root=p;
		if (q->data.Cod<x)
			q->right=p;
		else
			q->left=p;
		newnode=new TreeNode;
	}
}
///////////////////////////////////////
void main()
{
	Bst ob;
	f.open("tv.dat",ios::in | ios::binary | ios::beg);
	if (!f)
	{
		ob.Menu();
	}
	ob.Load();
	f.close();
	ob.Menu();
}
///////////////////////////////////////

