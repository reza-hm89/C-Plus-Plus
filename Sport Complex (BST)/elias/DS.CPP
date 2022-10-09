#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<bitmap.h>
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
fstream save;
void menu();
void searchmenu();
void fieldsmenu();
void showmenu();
int i;
char reshteha[4][30]={{"Footbal"},{"Valyball"},{"Basketball"},{"Tennis"}};
int codereshteha[4]={11,12,13,14};
struct mydate
{
int date,month,year;
};
struct treenode
{
char name1[50],name2[50],fname[50];
long int shsh,melli;  //shomare shenasname,melli
int birth,id;//saale tavallod va code ozviat
mydate begdate;  //tarikhe shorooe ozviat
//long int money;
int sumdate;  //tedad roozhaye etebar
int cnt;//tedad reshtehaye entekhabi
int reshte[4];  //code reshtehaye entekhaabi
treenode *left,*right;
};
class bst{
       //	private:
	 //	treenode *root;
	public:
	       treenode *root;
	       bst();
	       void maketree(treenode *cur);
	       void add(treenode *cur);
	       void regist();
	       void tamdid();
	       void deletenode();
	       void search2(int item,int *found,treenode **locptr,treenode **parent);
	       void edit();
	       treenode* searchid();
	       treenode* searchname();
	       void fields();
	       void show2(treenode *ret);
	       void inorderbyex(treenode *cur);
	       void showlistbyex();
	       void inorderbyfield(treenode *cur,int cod);
	       void showlistbyfield(int cod);
	       void showlistall(treenode *cur);//id
	       void shoelistfield();//id
	       void reset();
	       void inorder(treenode *cur);
	       void show(treenode *ret);
	       ~bst();
}ob,tree2;
//======================
bst::bst()
{  root=NULL;
  }
/*treenode *st;
save.open("data.dat",ios::in,ios::binary);
if (!save)
{
	cout<<"save in saazande not opened";
	getch();
	exit(0);
}
do
{
	st=new treenode;
	save.read((char*)&st,sizeof(struct treenode));
	treenode *p,*q;
	p=new treenode;
	q=new treenode;
	p=root;
	q=NULL;
	int x=st->id;
	while (p)
	{
		q=p;
		if (p->id<x)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=st;
	p->left=p->right=NULL;
	if (!root)
		root=p;
	if (q->id <x)
		q->right=p;
	else
		q->left=p;
} while (!save.eof());
save.close();
} */
//==============================================
void bst::inorder(treenode *cur)
{
	if (cur)
	{
		ob.inorder(cur->left);
		save.write((char *)&cur,sizeof(struct treenode));
		ob.inorder(cur->right);
	}
}
//==============================================
bst::~bst()
{ }
 /*	save.open("data.dat",ios::binary,ios::out);
	inorder(root);
	save.close();
}  */
//================================
void bst::regist()
{
while (1){
treenode *newnode;
newnode=new treenode;
restorecrtmode();
textmode(LASTMODE);
clrscr();
int i,j;
textcolor(8);
for (i=1;i<=50;i++)
{
	for (j=1;j<=80;j++)
		cprintf("Û");
	gotoxy(1,i);
}
textcolor(14);
for (i=1;i<=80;i++)
{
	gotoxy(i,1);
	cprintf("อ");
	gotoxy(i,49);
	cprintf("อ");
	if (i<49)
	{
	gotoxy(1,i);
	cprintf("บ");
	gotoxy(80,i);
	cprintf("บ");
	}
}
gotoxy(80,1);cprintf("ป");
gotoxy(1,1);cprintf("ษ");
gotoxy(1,49);cprintf("ศ");
gotoxy(80,49);cprintf("ผ");
textcolor(8);
for (int k=0;k<=36;k+=10)
{
gotoxy(10,9+k);
for (i=1;i<=3;i++)
{
	for (j=1;j<=15;j++)
		cprintf(" ");
	gotoxy(10,9+i+k);
}
}
for (k=0;k<=36;k+=10)
{
gotoxy(10+15+7,9+k);
for (i=1;i<=3;i++)
{
	for (j=1;j<=15;j++)
		cprintf(" ");
	gotoxy(10+15+7,9+i+k);
}
}

gotoxy(32+15,39);
for (i=1;i<=3;i++)
{
	for (j=1;j<=22;j++)
		cprintf(" ");
	gotoxy(32+15,39+i);
}
for (k=0;k<=26;k+=10)
{
gotoxy(10+15+7+15+7,9+k);
for (i=1;i<=3;i++)
{
	for (j=1;j<=15;j++)
		cprintf(" ");
	gotoxy(10+15+7+15+7,9+i+k);
}
}
textcolor(7);
gotoxy(15,9);
cprintf("Name");
gotoxy(10,11);
gets(newnode->name1);
if (!(newnode->name1[0]))
	break;
gotoxy(36,9);
cprintf("Family");
gotoxy(32,11);
gets(newnode->name2);
gotoxy(56,9);
cprintf("Father name");
gotoxy(54,11);
gets(newnode->fname);
gotoxy(11,19);
cprintf("sh shenasname");
gotoxy(10,21);
cin>>newnode->shsh;
gotoxy(34,19);
cprintf("Code  melli");
gotoxy(32,21);
cin>>newnode->melli;
gotoxy(54,19);
cprintf("Saale  tavallod");
gotoxy(54,21);
cin>>newnode->birth;
gotoxy(10,29);
cprintf("Tarikhe  ozviat");
struct date d;
getdate(&d);
newnode->begdate.date=d.da_day;
newnode->begdate.month=d.da_mon;
newnode->begdate.year=d.da_year;
gotoxy(12,31);
cprintf("    /  /  ");
gotoxy(12,31);
delay(170);
cout<<newnode->begdate.year;
gotoxy(17,31);
delay(170);
cout<<newnode->begdate.month;
gotoxy(20,31);
delay(170);
cout<<newnode->begdate.date;
gotoxy(32,29);
cprintf("Vaj'h pardakhti");
gotoxy(32,31);
long int money;
cin>>money;
newnode->sumdate=(int)(money/500);
gotoxy(54,29);
cprintf("Moddate  etebar");
gotoxy(54,31);
cout<<newnode->sumdate<<" rooz";
gotoxy(10,39);
cprintf("Tedad reshte");
newnode->cnt=11;
while (newnode->cnt <0 || newnode->cnt>4)
{
	gotoxy(10,41);
	cprintf("             ");
	gotoxy(10,41);
	cin>>newnode->cnt;
}
gotoxy(32,39);
cprintf("Code reshteha");
i=0;
while (i<newnode->cnt)
{
gotoxy(32+3*i,41);
cprintf("      ");
gotoxy(32+3*i,41);
cin>>newnode->reshte[i];
if(newnode->reshte[i]>10 && newnode->reshte[i]<15)
	i++;
}
int nid=100;
treenode *s;
s=ob.root;
int sw=1;
while (sw==1)
{
randomize();
nid=random(1500)+1;
s=ob.root;
sw=0;
   while (s)
   {
	if (s->id==nid)
	{
		sw=1;
		break;
	}
	if (s->id < nid)
		s=s->right;
	else
		s=s->left;
   }
}
newnode->id=nid;
////////////////////
treenode *p,*q;
	p=ob.root;
	q=NULL;
	int x=newnode->id;
	while (p)
	{
		q=p;
		if (p->id<x)
			p=p->right;
		else
			p=p->left;
	}
	p=new treenode;
	p=newnode;
	p->left=p->right=NULL;
	if (!ob.root)
		ob.root=p;
	if (q->id <x)
		q->right=p;
	else
		q->left=p;
///////////
window(26,24,52,33);
clrscr();
textcolor(0);
gotoxy(1,6);cprintf("               ");
gotoxy(9,6);
textcolor(88);
cprintf("saving.");
delay(700);
cprintf(".");
delay(700);
cprintf(".");
delay(500);
clrscr();
textcolor(14);
gotoxy(7,2);
cprintf(" Your ID:");
cout<<nid;
gotoxy(7,5);
cprintf(" Any one else?");
gotoxy(9,7);
cprintf("  (y/n):");
if(getche()!='y')
{
delay(500);
break;
}
window(1,1,50,80);
}
menu();
}
////////////////////////DELETE///////////////////////////////////
void bst::deletenode()
{
restorecrtmode();
textmode(LASTMODE);
int item;
gotoxy(1,2);
cprintf("ออออออออออออออออออออออออออออออออออออออออออออ");
textcolor(14);
gotoxy(1,1);
cprintf("Enter ID:");
cin>>item;
int found;
treenode *x,*parent,*xSucc,*subtree;
search2(item,&found,&x,&parent);
if (!found)
{
textcolor(4);
gotoxy(1,3);
cprintf("not found");
getch();
menu();
return;
}
if (x->left!=NULL && x->right!=NULL)
{
	xSucc=x->right;
	parent=x;
	while (xSucc->left!=0)
	{
		parent=xSucc;
		xSucc=xSucc->left;
	}
	x->id=xSucc->id;
	x=xSucc;
}
subtree=x->left;
if (subtree==NULL)
	subtree=x->right;
if (parent==NULL)
	ob.root=subtree;
else if (parent->left==x)
	parent->left=subtree;
else
	parent->right=subtree;

ob.show(x);
delete x;
textcolor(204);
gotoxy(1,10);
cprintf("DELETED..");
getch();
menu();
return;
}
///////////
void bst::search2(int item,int *found,treenode **locptr,treenode **parent)
{
*locptr=root;
*parent=NULL;
*found=0;
for(;;)
{
	if ((*found)|| *locptr==NULL)
		return;
	if (item<(*locptr)->id)
	{
		*parent=*locptr;
		*locptr=(*locptr)->left;
	}
	else if (item>(*locptr)->id)
	{
		*parent=*locptr;
		*locptr=(*locptr)->right;
	}
	else
		(*found)=1;
}
}
////////////////////////END OF DELETE////////////////////////////
//============================================================
/*treenode* bst::searchname()
{
restorecrtmode();
textmode(LASTMODE);
char sfam[50];
textcolor(14);
cprintf("Enter famil:");
gets(sfam);
gotoxy(1,2);
cprintf("ออออออออออออออออออออออออออออออออออออออออออออ");
treenode *p=root;
while (p)
{
	if (strcmp(p->name2,sfam)==0)
		return p;
	q=p->right;
	while(q)
	{
	 < sid)
		p=p->right;
	else
		p=p->left;
}
textcolor(4);
gotoxy(1,3);
cprintf("not found");
getch();
menu();
return NULL;
} */
//==============================================================
treenode* bst::searchid()
{
restorecrtmode();
textmode(LASTMODE);
int sid;
textcolor(14);
cprintf("Enter ID:");
cin>>sid;
gotoxy(1,2);
cprintf("ออออออออออออออออออออออออออออออออออออออออออออ");
treenode *p=ob.root;
while (p)
{
	if (p->id==sid)
		return p;
	if (p->id < sid)
		p=p->right;
	else
		p=p->left;
}
textcolor(4);
gotoxy(1,3);
cprintf("not found");
getch();
menu();
return NULL;
}
//=====================
void bst::show(treenode *ret)
{
gotoxy(1,3);
textcolor(13);
cprintf("Code ozviat:");
cout<<ret->id<<"\n";
cprintf("Naam:");
cout<<ret->name1<<"\n";
cprintf("Famil:");
cout<<ret->name2<<"\n";
cprintf("Tarikhe ozviat");
cout<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year<<"\n";
cprintf("Modddate etebar:");
cout<<ret->sumdate<<"\n";
cprintf("Reshtehaye sabte naami:");
for (int i=0;i<ret->cnt;i++)
	cout<<reshteha[ret->reshte[i]-11]<<" ";

}
//================================================================
void bst::showlistall(treenode *cur)
{
	if (cur)
	{
		ob.showlistall(cur->left);

		delay(200);
		if (i>42)
		{
		getch();
		window(1,3,80,25);
		clrscr();
		window(1,1,80,25);
		i=3;
		}
		textcolor(9);
		gotoxy(1,i++);
		cprintf("Code ozviat:");
		cout<<cur->id;
		gotoxy(1,i++);
		cprintf("Naam:");
		cout<<cur->name1;
		gotoxy(1,i++);
		cprintf("Famil:");
		cout<<cur->name2;
		gotoxy(1,i++);
		cprintf("Tarikhe ozviat");
		cout<<cur->begdate.date<<"/"<<cur->begdate.month<<"/"<<cur->begdate.year<<"\n";
		gotoxy(1,i++);
		cprintf("Modddate etebar:");
		cout<<cur->sumdate<<"\n";
		gotoxy(1,i++);
		cprintf("Reshtehaye sabte naami:");
		for (int j=0;j<cur->cnt;j++)
			cout<<reshteha[cur->reshte[j]-11]<<" ";
		gotoxy(1,i++);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");

		ob.showlistall(cur->right);
	}
}
//==========================================================================
void bst::show2(treenode *ret)
{
if (i>42)
{
	getch();
	window(1,3,80,50);
	clrscr();
	window(1,1,80,50);
	i=3;
}
gotoxy(1,i);
textcolor(13);
cprintf("Code ozviat:");
cout<<ret->id<<"\n";
cprintf("Naam:");
cout<<ret->name1<<"\n";
cprintf("Famil:");
cout<<ret->name2<<"\n";
cprintf("Tarikhe ozviat");
cout<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year<<"\n";
cprintf("Modddate etebar:");
cout<<ret->sumdate<<"\n";
cprintf("Reshtehaye sabte naami:");
for (int j=0;j<ret->cnt;j++)
	cout<<reshteha[ret->reshte[j]-11]<<" ";
cout<<"\n";
textcolor(14);
cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
i+=7;
}
//================================================================
void bst::inorderbyfield(treenode *cur,int cod)
{
	if(cur)
	{
		ob.inorderbyfield(cur->left,cod);
		for (int j=0;j<cur->cnt;j++)
			if (cur->reshte[j]==cod)
				ob.show2(cur);

		ob.inorderbyfield(cur->right,cod);
	}
}
//===================================================================
void bst::inorderbyex(treenode *cur)
{
	if(cur)
	{
		ob.inorderbyex(cur->left);
		if (cur->sumdate==0)
			ob.show2(cur);

		ob.inorderbyex(cur->right);
	}
}
//================================================================
void bst::showlistbyfield(int cod)
{
 treenode *s;
 s=new treenode;
 s=ob.root;
 ob.inorderbyfield(s,cod);
 getch();
 menu();
 return;
}
//================================================================
void bst::showlistbyex()
{
 treenode *s;
 s=new treenode;
 s=ob.root;
 ob.inorderbyex(s);
 getch();
 menu();
 return;
}
//================================================================
void searchmenu()
{
setcolor(12);
line(303,250,350,250);
line(350,225,350,275);
line(350,225,370,225);
line(350,275,370,275);
setcolor(0);
settextstyle(1,0,3);
outtextxy(375,259,"By Name");
setcolor(14);
outtextxy(375,209,"By Id");
char ch=11;
int y=1;
treenode *ret;
while (ch!=13)
{
	if (!(ch=getch()))
		ch=getch();
	if (ch==80)
		y++;
	else if (ch==72)
		y--;
	if (y>2)
		y=1;
	if (y<1)
		y=2;
	setcolor(0);
	outtextxy(375,259,"By Name");
	outtextxy(375,209,"By Id");
	setcolor(14);
	if (y==1)
	   outtextxy(375,209,"By Id");
	else
	   outtextxy(375,259,"By Name");
	if (ch==13 && y==1)
	{
	    ret=ob.searchid();
	    if (ret)
		ob.show(ret);
	    getch();
	    menu();
	}
	else if (ch==13 && y==2)
	{
	    ob.searchname();
	    if (ret)
		tree2.show(ret);
	    getch();
	    menu();
	}
}
getch();
exit(0);
}
//================================================================
void filedsmenu()
{
 cleardevice();
 setbkcolor(0);
 setcolor(8);
 setfillstyle(1,1);
 bar3d(20,120,600,400,20,1);
 settextstyle(7,0,6);
 setcolor(13);
 outtextxy(1,1,"   Fields Of Complex");
 setcolor(15);
 settextstyle(1,0,5);
 outtextxy(90,130,"Football");
 outtextxy(90,195,"Valyball");
 outtextxy(90,255,"Basketball");
 outtextxy(90,315,"Tennis");
 setcolor(14) ;
 outtextxy(500,130,"11");
 outtextxy(500,195,"12");
 outtextxy(500,255,"13");
 outtextxy(500,315,"14");
 getch();
 menu();
}
//================================================================
void showmenu()
{
setcolor(12);
line(287,350,335,350);
line(335,300,335,400);
line(335,300,345,300);
line(335,350,345,350);
line(335,400,345,400);
setcolor(0);
settextstyle(1,0,3);
outtextxy(347,335,"By Fields");
outtextxy(347,385,"Expireds");
setcolor(14);
outtextxy(347,285,"By Id");
int y=1;
char ch=11;
while (ch!=13)
{
	if (!(ch=getch()))
		ch=getch();
	if (ch==80)
		y++;
	else if (ch==72)
		y--;
	if (y>3)
		y=1;
	if (y<1)
		y=3;
	setcolor(0);
	outtextxy(347,335,"By Fields");
	outtextxy(347,385,"Expireds");
	outtextxy(347,285,"By Id");
	setcolor(14);
	switch(y){
	case 1:outtextxy(347,285,"By Id");break;
	case 2:outtextxy(347,335,"By Fields");break;
	case 3:outtextxy(347,385,"Expireds");break;
	}
	if (ch==13 && y==1)
	{
		restorecrtmode();
		textmode(LASTMODE);
		clrscr();
		if (ob.root==NULL)
		{
		    textcolor(4);
		    cprintf("List Is Empty");
		    getch();
		    menu();
		    return ;
		}
		cprintf("                              List By Id");
		gotoxy(1,2);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		i=3;
		ob.showlistall(ob.root);
	}
	else if (ch==13 && y==2)
	{

		restorecrtmode();
		textmode(LASTMODE);
		clrscr();
		if (ob.root==NULL)
		{
		    textcolor(4);
		    cprintf("List Is Empty");
		    getch();
		    menu();
		    return ;
		}
		cprintf("                              List By field");
		gotoxy(1,2);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		gotoxy(1,3);
		int cod;
		cprintf("code reshte ra vared konid:");
		cin>>cod;
		while (cod<11 || cod>14)
		{
		gotoxy(28,3);
		cprintf("          ");
		gotoxy(28,3);
		cin>>cod;
		}
		gotoxy(34,2);
		cout<<reshteha[cod-11];
		i=5;
		ob.showlistbyfield(cod);
	}
	else if (ch==13 && y==3)
       {
		restorecrtmode();
		textmode(LASTMODE);
		clrscr();
		if (ob.root==NULL)
		{
		    textcolor(4);
		    cprintf("List Is Empty");
		    getch();
		    menu();
		    return ;
		}
		cprintf("                                   Expireds");
		gotoxy(1,2);
		cprintf("อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
		i=3;
		ob.showlistbyex();
	   }
       }
getch();
menu();
}
//===============================================================
void bst::tamdid()
{
treenode *ret;
ret=new treenode;
ret=NULL;
ret=ob.searchid();
if (ret)
	ob.show(ret);
cout<<"\n============================================";
cout<<"\n\n";
textcolor(15);
cprintf("vaj'he daryafti jahate tamdide ozviat:");
long int money;
cin>>money;
ret->sumdate+=(int)(money/500);
cout<<"\n";
cprintf("Moddate etebar:");
cout<<ret->sumdate<<" Rooz";
getch();
menu();
return;
}
//================================================================
void bst::edit()
{
treenode *ret;
ret=new treenode;
ret=NULL;
ret=ob.searchid();
if(!ret)
	return;
gotoxy(10,3);
textcolor(13);
cprintf("Code ozviat:");
cout<<ret->id;
gotoxy(10,4);
cprintf("Naam:");
cout<<ret->name1;
gotoxy(10,5);
cprintf("Famil:");
cout<<ret->name2;
gotoxy(10,6);
cprintf("Tarikhe ozviat:");
cout<<ret->begdate.date<<"/"<<ret->begdate.month<<"/"<<ret->begdate.year;
gotoxy(10,7);
cprintf("Modddate etebar:");
cout<<ret->sumdate;
gotoxy(10,8);
cprintf("Reshtehaye sabte naami:");
for (int i=0;i<ret->cnt;i++)
	cout<<reshteha[ret->reshte[i]-11]<<" ";
gotoxy(16,10);
textcolor(3);
cprintf("Press Esc to exit");
i=3;
char ch=10;
gotoxy(8,i);
textcolor(4);
cprintf("ฏ");//175
while(ch!=27)
{
	if (!(ch=getch()))
		ch=getch();
	gotoxy(8,i);
	cprintf(" ");
	if (ch==80)
		i++;
	else if (ch==72)
		i--;
	if (i>8)
		i=3;
	if (i<3)
		i=8;
	gotoxy(8,i);
	textcolor(4);
	cprintf("ฏ");
	textcolor(15);
	if (ch==13){switch(i){
		case 3:gotoxy(22,i);
		       cprintf("                              ");
		       gotoxy(22,i);
		       cin>>ret->id;
		       break;
		case 4:gotoxy(15,i);
		       cprintf("                      ");
		       gotoxy(15,i);
		       gets(ret->name1);
		       break;
		case 5:gotoxy(16,i);
		       cprintf("                       ");
		       gotoxy(16,i);
		       gets(ret->name2);
		       break;
		case 6:gotoxy(25,i);
		       cprintf("                     ");
		       gotoxy(25,i);
		       cprintf("day:");
		       cin>>ret->begdate.date;
		       while (ret->begdate.date<1 || ret->begdate.date>31)
		       {
			  gotoxy(29,i);
			  cprintf("       ");
			  gotoxy(29,i);
			  cin>>ret->begdate.date;
		       }
		       gotoxy(32,i);
		       cprintf("month:");
		       cin>>ret->begdate.month;
		       while (ret->begdate.month<1 || ret->begdate.month>12)
		       {
			  gotoxy(38,i);
			  cprintf("       ");
			  gotoxy(38,i);
			  cin>>ret->begdate.month;
		       }
		       gotoxy(41,i);
		       cprintf("year:");
		       cin>>ret->begdate.year;
		       while (ret->begdate.year<1980 || ret->begdate.year>2008)
		       {
			  gotoxy(46,i);
			  cprintf("       ");
			  gotoxy(46,i);
			  cin>>ret->begdate.year;
		       }
		       break;
		case 7:gotoxy(26,i);
		       cprintf("            ");
		       gotoxy(26,i);
		       cin>>ret->sumdate;
		       break;
		case 8:gotoxy(33,i);
		       cprintf("                                            ");
		       gotoxy(34,i);
		       cprintf("Tedad reshte:");
		       cin>>ret->cnt;
		       while (ret->cnt>4 || ret->cnt<0)
		       {
			  gotoxy(47,i);
			  cprintf("        ");
			  gotoxy(47,i);
			  cin>>ret->cnt;
		       }
			gotoxy(49,i);
			cprintf("Code reshteha:");
			int j=0;
			while (j<ret->cnt)
			{
			gotoxy(63+3*j,i);
			cprintf("      ");
			gotoxy(63+3*j,i);
			cin>>ret->reshte[j];
			if(ret->reshte[j]>10 && ret->reshte[j]<15)
				j++;
			}
			break;
		       }
		       gotoxy(9,i);
		}
	}
menu();
return;
}
//=========================================================================
void bst::reset()
{
cleardevice();
settextstyle(7,0,8);
setcolor(4);
outtextxy(80,100,"  Reseting");
sound(300);
delay(120);
sound(200);
delay(100);
nosound();
rectangle(100,230,540,300);
rectangle(99,229,541,301);
setfillstyle(12,4);
for(i=101;i<540;i++)
{
delay(10);
bar(i,232,i,298);
}
delay(400);
menu();
return;
}
//==================================================================
void bst::add(treenode *cur)
{
      treenode *p,*q;
      p=tree2.root;
      q=NULL;
      while (p)
      {
	q=p;
	if (strcmp(p->name2,cur->name2)<0)
		p=p->right;
	else
		p=p->left;
      }
      p=new treenode;
      p=cur;
      p->left=p->right=NULL;
      if (!tree2.root)
	tree2.root=p;
      if (strcmp(q->name2,cur->name2)<0)
	q->right=p;
      else
	q->left=p;
}
//==================================================================
void bst::maketree(treenode *cur)
{
      if (cur)
      {
		ob.maketree(cur->left);
		tree2.add(cur);
		ob.maketree(cur->right);
      }
}
//==================================================================
treenode* bst::searchname()
{
	treenode *cur;
	cur=new treenode;
	cur=ob.root;
	tree2.root=NULL;
	ob.maketree(cur);
	restorecrtmode();
	textmode(LASTMODE);
	char sname[50];
	textcolor(14);
	cprintf("Enter family:");
	gets(sname);
	gotoxy(1,2);
	cprintf("ออออออออออออออออออออออออออออออออออออออออออออ");
	treenode *p=tree2.root;
	i=3;
	while (p)
	{
		if (strcmp(p->name2,sname)==0)
			     return p;
		if (strcmp(p->name2,sname)<0)
			p=p->right;
		else
			p=p->left;
	}
	textcolor(4);
	gotoxy(1,3);
	cprintf("not found");
	getch();
	menu();
	return NULL;
}
//================================================================
void menu()
{
setgraphmode(getgraphmode());
setfillstyle(1,8);
bar(1,1,640,480);
setfillstyle(9,8);
bar(1,1,640,10);
bar(1,1,8,480);
bar(1,470,640,480);
bar(632,1,640,480);
//rectangle(5,5,635,475);
displaybitmap(516,11,"h:\\1.BMP");
setcolor(0);
settextstyle(1,0,4);
//outtextxy(30,25,"Registration");
outtextxy(30,75,"Extension Of Membership");
outtextxy(30,175,"Delete A Member");
outtextxy(30,125,"Edit A Member Info");
outtextxy(30,225,"Search A Member");
outtextxy(30,275,"Fields Of Complex");
outtextxy(30,325,"List Of Members");
outtextxy(30,375,"Reset All");
outtextxy(30,425,"Exit");
setcolor(14);
outtextxy(30,25,"Registration");
char ch=10;
int y=25;
while (ch!=27)
{
  ch=getch();
  if (!ch)
	ch=getch();
  switch (ch)
  {
  case 80:y+=50;
	break;
  case 72:y-=50;
	break;
  }
  if (ch==13 && y==25)
	ob.regist();
  else if (ch==13 && y==75)
	ob.tamdid();
  else if (ch==13 && y==125)
	ob.edit();
  else if (ch==13 && y==175)
	ob.deletenode();
  else if (ch==13 && y==225)
	searchmenu();
  else if (ch==13 && y==275)
	filedsmenu();
  else if (ch==13 && y==325)
	showmenu();
  else if (ch==13 && y==375)
	ob.reset();
  else if (ch==13 && y==425)
	exit(0);
  if (y>425)
	y=25;
  if (y<25)
	y=425;
  setcolor(0);
  outtextxy(30,25,"Registration");
  outtextxy(30,75,"Extension Of Membership");
  outtextxy(30,175,"Delete A Member");
  outtextxy(30,125,"Edit A Member Info");
  outtextxy(30,225,"Search A Member");
  outtextxy(30,275,"Fields Of Complex");
  outtextxy(30,325,"List Of Members");
  outtextxy(30,375,"Reset All");
  outtextxy(30,425,"Exit");
  setcolor(14);
  switch (y){
  case 25:outtextxy(30,25,"Registration");
	break;
  case 75:outtextxy(30,75,"Extension Of Membership");
	break;
  case 125:outtextxy(30,125,"Edit A Member Info");
	break;
  case 175:outtextxy(30,175,"Delete A Member");
	break;
  case 225:outtextxy(30,225,"Search A Member");
	break;
  case 275:outtextxy(30,275,"Fields Of Complex");
	break;
  case 325:outtextxy(30,325,"List Of Members");
	break;
  case 375:outtextxy(30,375,"Reset All");
	break;
  case 425:outtextxy(30,425,"Exit");
	break;
  }

}
closegraph();
}
void main()
{
//fstream f1("data.dat",ios::in,ios::out);
int driver=DETECT,mode=0;
initgraph(&driver,&mode,"c:\\tc\\bgi");
displaybitmap(1,1,"h:\\2.BMP");
getch();
menu();
}