#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
//==============================================================================
struct memberinfo
{
int id;
char fname[20];
char lname[30];
char father[20];
long int shsh;
long int ncode;
int byear;
int myear;
int mmonth;
int mday;
int creditmonth;
int branch[4];
}mem;
//==============================================================================
int todayy;
int todaym;
int todayd;
int showrow;
int branchnum;
int find;
char fn[20];
char ln[30];
int clubarray[500];
//==============================================================================
class treeNode
{
friend class tree;
private:
treeNode *left;
int id;
char fname[20];
char lname[30];
char father[20];
long int shsh;
long int ncode;
int byear;
int myear;
int mmonth;
int mday;
int creditmonth;
int branch[4];
treeNode *right;
};//class treeNode
//==============================================================================
treeNode memarray[500];
//==============================================================================
class tree
{
public:
tree();
treeNode *getRoot()
	{
   return root;
   }//getRoot
void insert(int);
void search_id(int);
void edit_id(int);
void delete_id(int);
void search2(int id,int *found,treeNode **locptr,treeNode **parent);
void revival_id(int);
void show_club(treeNode *s);
void show_exp(treeNode *s);
void find_name(treeNode *s);
void show_branch(treeNode *s);
void save(treeNode *s);
void load();
private:
treeNode *root;
};//class tree
//------------------------------------------------------------------------------
tree::tree()
{
root=NULL;
}//tree
//------------------------------------------------------------------------------
void tree::save(treeNode *s)
{
FILE *outfp;
if(root==NULL)
	outfp=fopen("MemberFile","wb");
if(s!=NULL)
	{
   save(s->left);
	mem.id=s->id;
	strcpy(mem.fname,s->fname);
	strcpy(mem.lname,s->lname);
	strcpy(mem.father,s->father);
	mem.shsh=s->shsh;
	mem.ncode=s->ncode;
	mem.byear=s->byear;
	mem.myear=s->myear;
	mem.mmonth=s->mmonth;
	mem.mday=s->mday;
	mem.creditmonth=s->creditmonth;
	mem.branch[0]=s->branch[0];
	mem.branch[1]=s->branch[1];
	mem.branch[2]=s->branch[2];
	mem.branch[3]=s->branch[3];
   if(s==root)
   	outfp=fopen("MemberFile","wb");
   else
   	outfp=fopen("MemberFile","ab");
   fwrite(&mem,sizeof(struct memberinfo),1,outfp);
   save(s->right);
   }//if
}//save
//------------------------------------------------------------------------------
void tree::load()
{
FILE *infp;
infp=fopen("MemberFile","rb");
if(!infp)
	{
	textcolor(13);
	gotoxy(22,2);
	cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
	textcolor(11);
	gotoxy(22,3);
	cprintf("< Anoosheh Mansoori  Diba Vafabakhsh >");
   gotoxy(20,8);
   textcolor(15);
   cprintf("WELCOME , This Program Run for First Time");
   gotoxy(80,25);
   getch();
   return;
   }//if
int saveid=0;
for(;;)
	{
   fread(&mem,sizeof(struct memberinfo),1,infp);
   if(saveid==mem.id)
   	goto ENDLOOP;
   saveid=mem.id;
	treeNode *node,*help;
	node=new treeNode;
	node->left=node->right=NULL;
	node->id=mem.id;
   clubarray[node->id-1000]=1;
	strcpy(node->fname,mem.fname);
	strcpy(node->lname,mem.lname);
	strcpy(node->father,mem.father);
	node->shsh=mem.shsh;
	node->ncode=mem.ncode;
	node->byear=mem.byear;
	node->myear=mem.myear;
	node->mmonth=mem.mmonth;
	node->mday=mem.mday;
	node->creditmonth=mem.creditmonth;
	node->branch[0]=mem.branch[0];
	node->branch[1]=mem.branch[1];
	node->branch[2]=mem.branch[2];
	node->branch[3]=mem.branch[3];
   if(root==NULL)
		root=node;
	else
		{
   	help=root;
   	while(help!=NULL)
   		{
      	if(node->id>help->id)
      		{
         	if(help->right!=NULL)
         		help=help->right;
         	else
         		{
         		help->right=node;
            	break;
            	}//else
         	}//if
      	else
      		{
         	if(help->left!=NULL)
         		help=help->left;
         	else
         		{
            	help->left=node;
            	break;
            	}//else
         	}//else
      	}//while
   	}//else
   ENDLOOP:
   if(feof(infp))
   	break;
   }//for
}//load
//------------------------------------------------------------------------------
void tree::search2(int id,int *found,treeNode **locptr,treeNode **parent)
{
*locptr=root;
*parent=NULL;
*found=0;
for(;;)
	{
   if((*found)||*locptr==NULL)
   	return;
   if(id<(*locptr)->id)
   	{
      *parent=*locptr;
      *locptr=(*locptr)->left;
      }//if
   else if(id>(*locptr)->id)
   			{
            *parent=*locptr;
            *locptr=(*locptr)->right;
            }//if
   		else
         	(*found)=1;
   }//for
}//saerch2
//------------------------------------------------------------------------------
void tree::delete_id(int id)
{
int found,i;
treeNode *x,*parent,*xSucc,*subtree;
search2(id,&found,&x,&parent);
if(!found)
	{
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Can not Find This Member ..... ");
   gotoxy(80,25);
   getch();
   return;
   }//if
clubarray[x->id-1000]=0;
if(x->left!=NULL && x->right!=NULL)
	{
   xSucc=x->right;
   parent=x;
   while(xSucc->left!=NULL)
   	{
      parent=xSucc;
      xSucc=xSucc->left;
      }//while
   x->id=xSucc->id;
	strcpy(x->fname,xSucc->fname);
	strcpy(x->lname,xSucc->lname);
	strcpy(x->father,xSucc->father);
	x->shsh=xSucc->shsh;
	x->ncode=xSucc->ncode;
	x->byear=xSucc->byear;
	x->myear=xSucc->myear;
	x->mmonth=xSucc->mmonth;
	x->mday=xSucc->mday;
	x->creditmonth=xSucc->creditmonth;
	x->branch[0]=xSucc->branch[0];
	x->branch[1]=xSucc->branch[1];
	x->branch[2]=xSucc->branch[2];
	x->branch[3]=xSucc->branch[3];
   x=xSucc;
   }//if
subtree=x->left;
if(subtree==NULL)
	subtree=x->right;
if(parent==NULL)
	root=subtree;
else if(parent->left==x)
			parent->left=subtree;
		else
      	parent->right=subtree;
delete x;
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,23);
   cprintf("-");
   }//for
textcolor(12);gotoxy(22,24);cprintf("   Delete This Member Successfully ");
gotoxy(80,25);
getch();
}//delete_id
//------------------------------------------------------------------------------
void tree::insert(int id)
{
int i;
treeNode *node,*help;
node=new treeNode;
node->left=node->right=NULL;
node->id=id;
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,5);
   cprintf("-");
   }//for
textcolor(15);
gotoxy(6,6);cprintf("Mem.ship ID  : ");textcolor(12);cprintf("%d",node->id);
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,7);
   cprintf("-");
   }//for
textcolor(15);gotoxy(6,8);cprintf("Firstname    : ");cin>>node->fname;
textcolor(15);gotoxy(6,9);cprintf("Lastname     : ");cin>>node->lname;
textcolor(15);gotoxy(6,10);cprintf("Father Name  : ");cin>>node->father;
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,11);
   cprintf("-");
   }//for
textcolor(15);gotoxy(6,12);cprintf("SH.Number    : ");cin>>node->shsh;
textcolor(15);gotoxy(6,13);cprintf("NationalCode : ");cin>>node->ncode;
textcolor(15);gotoxy(6,14);cprintf("Birth Year   : ");cin>>node->byear;
while(node->byear<1360 || node->byear>1380)
	{
   gotoxy(21,14);cout<<"                               ";
   gotoxy(21,14);cin>>node->byear;
   }//while
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,15);
   cprintf("-");
   }//for
textcolor(15);gotoxy(6,16);cprintf("Memship Date : ");
textcolor(12);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(12);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(12);cprintf("%d",todayd);
node->myear=todayy;
node->mmonth=todaym;
node->mday=todayd;
textcolor(15);gotoxy(6,17);cprintf("Credit Month : ");cin>>node->creditmonth;
while(node->creditmonth<1 || node->creditmonth>6)
	{
   gotoxy(21,17);cout<<"                               ";
   gotoxy(21,17);cin>>node->creditmonth;
   }//while
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,18);
   cprintf("-");
   }//for
textcolor(15);gotoxy(40,17);cprintf("Exp. Date : ");
int eyear=todayy;
int emonth=todaym+node->creditmonth;
int eday=todayd;
if(emonth>12)
	{
   emonth%=12;
   eyear++;
   }//if
if(emonth>6 && eday==31)
	eday=30;
textcolor(12);cprintf("%d",eyear);
textcolor(15);cprintf(" / ");
textcolor(12);cprintf("%d",emonth);
textcolor(15);cprintf(" / ");
textcolor(12);cprintf("%d",eday);
textcolor(15);gotoxy(6,19);cprintf("Football     : ");cin>>node->branch[0];
while(node->branch[0]!=0 && node->branch[0]!=1)
	{
   gotoxy(21,19);cout<<"                               ";
   gotoxy(21,19);cin>>node->branch[0];
   }//while
textcolor(15);gotoxy(6,20);cprintf("Basketball   : ");cin>>node->branch[1];
while(node->branch[1]!=0 && node->branch[1]!=1)
	{
   gotoxy(21,20);cout<<"                               ";
   gotoxy(21,20);cin>>node->branch[1];
   }//while
textcolor(15);gotoxy(6,21);cprintf("Volleyball   : ");cin>>node->branch[2];
while(node->branch[2]!=0 && node->branch[2]!=1)
	{
   gotoxy(21,21);cout<<"                               ";
   gotoxy(21,21);cin>>node->branch[2];
   }//while
textcolor(15);gotoxy(6,22);cprintf("Handball     : ");cin>>node->branch[3];
while(node->branch[3]!=0 && node->branch[3]!=1)
	{
   gotoxy(21,22);cout<<"                               ";
   gotoxy(21,22);cin>>node->branch[3];
   }//while
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,23);
   cprintf("-");
   }//for
if(root==NULL)
	root=node;
else
	{
   help=root;
   while(help!=NULL)
   	{
      if(node->id>help->id)
      	{
         if(help->right!=NULL)
         	help=help->right;
         else
         	{
         	help->right=node;
            break;
            }//else
         }//if
      else
      	{
         if(help->left!=NULL)
         	help=help->left;
         else
         	{
            help->left=node;
            break;
            }//else
         }//else
      }//while
   }//else
textcolor(12);gotoxy(22,24);cprintf("    Insert New Member Successfully ");
gotoxy(80,25);
getch();
}//insert
//------------------------------------------------------------------------------
void tree::search_id(int id)
{
int found=0,i;
treeNode *help=root;
while(help!=NULL)
	{
   if(id<help->id)
   	help=help->left;
   else
   	if(id>help->id)
      	help=help->right;
      else
      	{
         found=1;
         break;
         }//else
   }//while
if(found==0)
	{
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Can not Find This Member ..... ");
   }//if
else
	{
   for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,7);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,8);cprintf("Firstname    : ");textcolor(14);cprintf("%s",help->fname);
   textcolor(15);gotoxy(6,9);cprintf("Lastname     : ");textcolor(14);cprintf("%s",help->lname);
	textcolor(15);gotoxy(6,10);cprintf("Father Name  : ");textcolor(14);cprintf("%s",help->father);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,11);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,12);cprintf("SH.Number    : ");textcolor(14);cprintf("%ld",help->shsh);
	textcolor(15);gotoxy(6,13);cprintf("NationalCode : ");textcolor(14);cprintf("%ld",help->ncode);
	textcolor(15);gotoxy(6,14);cprintf("Birth Year   : ");textcolor(14);cprintf("%d",help->byear);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,15);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,16);cprintf("Memship Date : ");
	textcolor(14);cprintf("%d",help->myear);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",help->mmonth);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",help->mday);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,18);
   	cprintf("-");
   	}//for
	textcolor(15);gotoxy(6,17);cprintf("Exp. Date    : ");
	int eyear=help->myear;
	int emonth=help->mmonth+help->creditmonth;
	int eday=help->mday;
	if(emonth>12)
		{
   	emonth%=12;
   	eyear++;
   	}//if
	if(emonth>6 && eday==31)
		eday=30;
	textcolor(14);cprintf("%d",eyear);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",emonth);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",eday);
	textcolor(15);gotoxy(6,19);cprintf("Football     : ");
   if(help->branch[0]==1)
   	{
      textcolor(14);cprintf("YES");
      }//if
   else
   	{
      textcolor(14);cprintf("NO");
      }//else
	textcolor(15);gotoxy(6,20);cprintf("Basketball   : ");
   if(help->branch[1]==1)
   	{
      textcolor(14);cprintf("YES");
      }//if
   else
   	{
      textcolor(14);cprintf("NO");
      }//else
	textcolor(15);gotoxy(6,21);cprintf("Volleyball   : ");
   if(help->branch[2]==1)
   	{
      textcolor(14);cprintf("YES");
      }//if
   else
   	{
      textcolor(14);cprintf("NO");
      }//else
	textcolor(15);gotoxy(6,22);cprintf("Handball     : ");
   if(help->branch[3]==1)
   	{
      textcolor(14);cprintf("YES");
      }//if
   else
   	{
      textcolor(14);cprintf("NO");
      }//else
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Find This Member  Successfully ");
   }//else
gotoxy(80,25);
getch();
}//search_id
//------------------------------------------------------------------------------
void tree::edit_id(int id)
{
int found=0,i;
treeNode *help=root;
while(help!=NULL)
	{
   if(id<help->id)
   	help=help->left;
   else
   	if(id>help->id)
      	help=help->right;
      else
      	{
         found=1;
         break;
         }//else
   }//while
if(found==0)
	{
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Can not Find This Member ..... ");
   }//if
else
	{
   for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,7);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,8);cprintf("Firstname    : ");textcolor(14);cprintf("%s",help->fname);
   textcolor(15);gotoxy(6,9);cprintf("Lastname     : ");textcolor(14);cprintf("%s",help->lname);
	textcolor(15);gotoxy(6,10);cprintf("Father Name  : ");textcolor(14);cprintf("%s",help->father);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,11);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,12);cprintf("SH.Number    : ");textcolor(14);cprintf("%ld",help->shsh);
	textcolor(15);gotoxy(6,13);cprintf("NationalCode : ");textcolor(14);cprintf("%ld",help->ncode);
	textcolor(15);gotoxy(6,14);cprintf("Birth Year   : ");textcolor(14);cprintf("%d",help->byear);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,15);
   	cprintf("-");
   	}//for
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(40,8);cprintf("Firstname    : ");cin>>help->fname;
   textcolor(15);gotoxy(40,9);cprintf("Lastname     : ");cin>>help->lname;
	textcolor(15);gotoxy(40,10);cprintf("Father Name  : ");cin>>help->father;
   textcolor(15);gotoxy(40,12);cprintf("SH.Number    : ");cin>>help->shsh;
	textcolor(15);gotoxy(40,13);cprintf("NationalCode : ");cin>>help->ncode;
	textcolor(15);gotoxy(40,14);cprintf("Birth Year   : ");cin>>help->byear;
   while(help->byear<1360 || help->byear>1380)
		{
   	gotoxy(55,14);cout<<"             ";
   	gotoxy(55,14);cin>>help->byear;
   	}//while
   textcolor(12);gotoxy(22,24);cprintf("    Edit This Member  Successfully ");
   }//else
gotoxy(80,25);
getch();
}//edit_id
//------------------------------------------------------------------------------
void tree::revival_id(int id)
{
int found=0,i;
treeNode *help=root;
while(help!=NULL)
	{
   if(id<help->id)
   	help=help->left;
   else
   	if(id>help->id)
      	help=help->right;
      else
      	{
         found=1;
         break;
         }//else
   }//while
if(found==0)
	{
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Can not Find This Member ..... ");
   }//if
else
	{
   for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,7);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,8);cprintf("Firstname    : ");textcolor(14);cprintf("%s",help->fname);
   textcolor(15);gotoxy(6,9);cprintf("Lastname     : ");textcolor(14);cprintf("%s",help->lname);
	textcolor(15);gotoxy(6,10);cprintf("Father Name  : ");textcolor(14);cprintf("%s",help->father);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,11);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,12);cprintf("SH.Number    : ");textcolor(14);cprintf("%ld",help->shsh);
	textcolor(15);gotoxy(6,13);cprintf("NationalCode : ");textcolor(14);cprintf("%ld",help->ncode);
	textcolor(15);gotoxy(6,14);cprintf("Birth Year   : ");textcolor(14);cprintf("%d",help->byear);
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,15);
   	cprintf("-");
   	}//for
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(15);gotoxy(6,16);cprintf("Memship Date : ");
	textcolor(14);cprintf("%d",help->myear);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",help->mmonth);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",help->mday);
   textcolor(15);gotoxy(6,17);cprintf("Credit Month : ");
   textcolor(14);cprintf("%d",help->creditmonth);
	textcolor(15);gotoxy(6,18);cprintf("Exp. Date    : ");
	int eyear=help->myear;
	int emonth=help->mmonth+help->creditmonth;
	int eday=help->mday;
	if(emonth>12)
		{
   	emonth%=12;
   	eyear++;
   	}//if
	if(emonth>6 && eday==31)
		eday=30;
	textcolor(14);cprintf("%d",eyear);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",emonth);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",eday);
   int n;
   textcolor(15);gotoxy(40,17);cprintf("Add Credit Month : ");cin>>n;
   while(n<1 || n>6)
      {
   	gotoxy(59,17);
      cout<<"         ";
      gotoxy(59,17);
      cin>>n;
      }//while
   help->creditmonth+=n;
	textcolor(15);gotoxy(40,18);cprintf("New Exp. Date    : ");
	eyear=help->myear;
	emonth=help->mmonth+help->creditmonth;
	eday=help->mday;
	if(emonth>12)
		{
   	emonth%=12;
   	eyear++;
   	}//if
	if(emonth>6 && eday==31)
		eday=30;
	textcolor(14);cprintf("%d",eyear);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",emonth);
	textcolor(15);cprintf(" / ");
	textcolor(14);cprintf("%d",eday);
   textcolor(12);gotoxy(22,24);cprintf("   Revival Credit Date Successfully ");
   }//else
gotoxy(80,25);
getch();
}//revival_id
//------------------------------------------------------------------------------
void tree::show_club(treeNode *s)
{
if(s!=NULL)
	{
   show_club(s->left);
   if(showrow<25)
   	{
      textcolor(14);gotoxy(6,showrow);cprintf("%d",s->id);
      textcolor(15);gotoxy(15,showrow);cprintf("%s",s->fname);
      textcolor(15);gotoxy(30,showrow);cprintf("%s",s->lname);
      textcolor(15);gotoxy(45,showrow);cprintf("%s",s->father);
      textcolor(15);gotoxy(60,showrow);if(s->branch[0]==1)cprintf("Y");else cprintf("N");
      textcolor(15);gotoxy(64,showrow);if(s->branch[1]==1)cprintf("Y");else cprintf("N");
      textcolor(15);gotoxy(68,showrow);if(s->branch[2]==1)cprintf("Y");else cprintf("N");
      textcolor(15);gotoxy(72,showrow);if(s->branch[3]==1)cprintf("Y");else cprintf("N");
      showrow+=2;
      }//if
   show_club(s->right);
   }//if
}//show_club
//------------------------------------------------------------------------------
void tree::show_exp(treeNode *s)
{
if(s!=NULL)
	{
   show_exp(s->left);
   int eyear=s->myear;
   int emonth=s->mmonth+s->creditmonth;
   int eday=s->mday;
   if(emonth>12)
   	{
      emonth%=12;
      eyear++;
   	}//if
   if(emonth>6 && eday==31)
   	eday=30;
   int pass=0;
   if(eyear<todayy) pass=1;
   if(eyear==todayy && emonth<todaym) pass=1;
   if(eyear==todayy && emonth==todaym && eday<todayd) pass=1;
   if(showrow<25 && pass==1)
   	{
      textcolor(14);gotoxy(6,showrow);cprintf("%d",s->id);
      textcolor(15);gotoxy(15,showrow);cprintf("%s",s->fname);
      textcolor(15);gotoxy(30,showrow);cprintf("%s",s->lname);
      textcolor(15);gotoxy(45,showrow);cprintf("%s",s->father);
		textcolor(15);gotoxy(60,showrow);
		textcolor(14);cprintf("%d",eyear);
		textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",emonth);
		textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",eday);
      showrow+=2;
      }//if
   show_exp(s->right);
   }//if
}//show_exp
//------------------------------------------------------------------------------
void tree::find_name(treeNode *s)
{
int i;
if(s!=NULL)
	{
   find_name(s->left);
   if(strcmp(s->fname,fn)==0 && strcmp(s->lname,ln)==0)
   	{
      find=1;
   	for(i=5;i<=75;i++)
			{
   		textcolor(8);
   		gotoxy(i,7);
   		cprintf("-");
   		}//for
      textcolor(15);gotoxy(40,8);cprintf("Member ID   : ");textcolor(14);cprintf("%d",s->id);
   	textcolor(15);gotoxy(6,8);cprintf("Firstname    : ");textcolor(14);cprintf("%s",s->fname);
   	textcolor(15);gotoxy(6,9);cprintf("Lastname     : ");textcolor(14);cprintf("%s",s->lname);
		textcolor(15);gotoxy(6,10);cprintf("Father Name  : ");textcolor(14);cprintf("%s",s->father);
		for(i=5;i<=75;i++)
			{
   		textcolor(8);
   		gotoxy(i,11);
   		cprintf("-");
   		}//for
   	textcolor(15);gotoxy(6,12);cprintf("SH.Number    : ");textcolor(14);cprintf("%ld",s->shsh);
		textcolor(15);gotoxy(6,13);cprintf("NationalCode : ");textcolor(14);cprintf("%ld",s->ncode);
		textcolor(15);gotoxy(6,14);cprintf("Birth Year   : ");textcolor(14);cprintf("%d",s->byear);
		for(i=5;i<=75;i++)
			{
   		textcolor(8);
   		gotoxy(i,15);
   		cprintf("-");
   		}//for
   	textcolor(15);gotoxy(6,16);cprintf("Memship Date : ");
		textcolor(14);cprintf("%d",s->myear);
		textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",s->mmonth);
		textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",s->mday);
		for(i=5;i<=75;i++)
			{
   		textcolor(8);
   		gotoxy(i,18);
   		cprintf("-");
   		}//for
		textcolor(15);gotoxy(6,17);cprintf("Exp. Date    : ");
		int eyear=s->myear;
		int emonth=s->mmonth+s->creditmonth;
		int eday=s->mday;
		if(emonth>12)
			{
   		emonth%=12;
   		eyear++;
   		}//if
		if(emonth>6 && eday==31)
			eday=30;
      textcolor(14);cprintf("%d",eyear);
      textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",emonth);
		textcolor(15);cprintf(" / ");
		textcolor(14);cprintf("%d",eday);
		textcolor(15);gotoxy(6,19);cprintf("Football     : ");
   	if(s->branch[0]==1)
   		{
      	textcolor(14);cprintf("YES");
      	}//if
   	else
   		{
      	textcolor(14);cprintf("NO");
      	}//else
		textcolor(15);gotoxy(6,20);cprintf("Basketball   : ");
   	if(s->branch[1]==1)
   		{
      	textcolor(14);cprintf("YES");
      	}//if
   	else
   		{
      	textcolor(14);cprintf("NO");
      	}//else
		textcolor(15);gotoxy(6,21);cprintf("Volleyball   : ");
   	if(s->branch[2]==1)
   		{
      	textcolor(14);cprintf("YES");
      	}//if
   	else
   		{
      	textcolor(14);cprintf("NO");
      	}//else
		textcolor(15);gotoxy(6,22);cprintf("Handball     : ");
   	if(s->branch[3]==1)
   		{
      	textcolor(14);cprintf("YES");
      	}//if
   	else
   		{
      	textcolor(14);cprintf("NO");
      	}//else
		for(i=5;i<=75;i++)
			{
   		textcolor(8);
   		gotoxy(i,23);
   		cprintf("-");
   		}//for
   	textcolor(12);gotoxy(22,24);cprintf("    Find This Member  Successfully ");
		gotoxy(80,25);
		getch();
      }//if
   find_name(s->right);
   }//if
}//find_name
//------------------------------------------------------------------------------
void tree::show_branch(treeNode *s)
{
if(s!=NULL)
	{
   show_branch(s->left);
   if(showrow<25 && s->branch[branchnum-1]==1)
   	{
      textcolor(14);gotoxy(6,showrow);cprintf("%d",s->id);
      textcolor(15);gotoxy(15,showrow);cprintf("%s",s->fname);
      textcolor(15);gotoxy(30,showrow);cprintf("%s",s->lname);
      textcolor(15);gotoxy(45,showrow);cprintf("%s",s->father);
      textcolor(15);gotoxy(60,showrow);cprintf("%ld",s->ncode);
      showrow+=2;
      }//if
   show_branch(s->right);
   }//if
}//show_branch
//==============================================================================
tree clubtree;
//==============================================================================
void search_by_name()
{
int i;
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ------ Search by Name  Menu ------ >");
textcolor(15);
gotoxy(6,6);cprintf("Firstname    : ");cin>>fn;
gotoxy(40,6);cprintf("Lastname    : ");cin>>ln;
clubtree.find_name(clubtree.getRoot());
if(find==0)
	{
	for(i=5;i<=75;i++)
		{
   	textcolor(8);
   	gotoxy(i,23);
   	cprintf("-");
   	}//for
   textcolor(12);gotoxy(22,24);cprintf("    Can not Find This Member ..... ");
   gotoxy(80,25);
   getch();
   }//if
}//saerch_by_name
//------------------------------------------------------------------------------
void insert_new_member()
{
int i;
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ----- Insert New Member Menu ----- >");
for(i=0;i<500;i++)
	if(clubarray[i]==0)
   	break;
clubarray[i]=1;
clubtree.insert(1000+i);
}//inser_new_member
//------------------------------------------------------------------------------
void show_all_club_members()
{
int i;
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ----- Show All Club  Members ----- >");
showrow=8;
textcolor(8);
gotoxy(6,6);
cprintf("Mem.ID");
gotoxy(15,6);
cprintf("Firstname");
gotoxy(30,6);
cprintf("Lastname");
gotoxy(45,6);
cprintf("Fathername");
gotoxy(60,6);
cprintf("F");
gotoxy(64,6);
cprintf("B");
gotoxy(68,6);
cprintf("V");
gotoxy(72,6);
cprintf("H");
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,7);
   cprintf("-");
   }//for
clubtree.show_club(clubtree.getRoot());
gotoxy(80,25);
getch();
}//show_all_club_members
//------------------------------------------------------------------------------
void show_all_exp_members()
{
int i;
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ----- Show All Exp.  Members ----- >");
showrow=8;
textcolor(8);
gotoxy(6,6);
cprintf("Mem.ID");
gotoxy(15,6);
cprintf("Firstname");
gotoxy(30,6);
cprintf("Lastname");
gotoxy(45,6);
cprintf("Fathername");
gotoxy(60,6);
cprintf("Expiry Date");
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,7);
   cprintf("-");
   }//for
clubtree.show_exp(clubtree.getRoot());
gotoxy(80,25);
getch();
}//show_all_exp_members
//------------------------------------------------------------------------------
void show_all_branch_members()
{
int i;
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ---- Show All Branch  Members ---- >");
textcolor(15);gotoxy(6,6);cprintf("Branch Code (F:1/B:2/V:3/H:4) : ");cin>>branchnum;
while(branchnum<1 || branchnum>4)
	{
   gotoxy(38,6);cout<<"                             ";
   gotoxy(38,6);cin>>branchnum;
   }//while
showrow=10;
textcolor(8);
gotoxy(6,8);
cprintf("Mem.ID");
gotoxy(15,8);
cprintf("Firstname");
gotoxy(30,8);
cprintf("Lastname");
gotoxy(45,8);
cprintf("Fathername");
gotoxy(60,8);
cprintf("National Code");
for(i=5;i<=75;i++)
	{
   textcolor(8);
   gotoxy(i,9);
   cprintf("-");
   }//for
clubtree.show_branch(clubtree.getRoot());
gotoxy(80,25);
getch();
}//show_all_branch_members
//------------------------------------------------------------------------------
void search_by_id()
{
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ------- Search by ID  Menu ------- >");
int id;
textcolor(15);
gotoxy(6,6);cprintf("Mem.ship ID  : ");cin>>id;
clubtree.search_id(id);
}//search_by_id
//------------------------------------------------------------------------------
void edit_member_info()
{
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< -- Edit Member Information Menu -- >");
int id;
textcolor(15);
gotoxy(6,6);cprintf("Mem.ship ID  : ");cin>>id;
clubtree.edit_id(id);
}//edit_member_info
//------------------------------------------------------------------------------
void delete_member()
{
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ------- Delete Member Menu ------- >");
int id;
textcolor(15);
gotoxy(6,6);cprintf("Mem.ship ID  : ");cin>>id;
clubtree.delete_id(id);
}//delete_member
//------------------------------------------------------------------------------
void revival_credit_date()
{
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ---- Revival Credit Date Menu ---- >");
int id;
textcolor(15);
gotoxy(6,6);cprintf("Mem.ship ID  : ");cin>>id;
clubtree.revival_id(id);
}//revival_credit_date
//------------------------------------------------------------------------------
void menu()
{
int row=6,brow;
char ch;
showagain:
clrscr();
textcolor(15);gotoxy(64,2);
textcolor(11);cprintf("%d",todayy);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todaym);
textcolor(15);cprintf(" / ");
textcolor(11);cprintf("%d",todayd);
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< Anoosheh Mansoori  Diba Vafabakhsh >");
textcolor(15);
gotoxy(6,6);cprintf("[ ] Insert New Member");
gotoxy(6,7);cprintf("[ ] Delete Member");
gotoxy(6,8);cprintf("[ ] Revival Member's Credit Date");
gotoxy(6,9);cprintf("[ ] Edit Member's Info");
gotoxy(6,10);cprintf("[ ] Show All Club Members");
gotoxy(6,11);cprintf("[ ] Show All Branch Members");
gotoxy(6,12);cprintf("[ ] Show All Club Members (Exp.)");
gotoxy(6,13);cprintf("[ ] Search by ID");
gotoxy(6,14);cprintf("[ ] Search by Name");
gotoxy(6,15);cprintf("[ ] Exit From Program");
textcolor(12);
gotoxy(7,row);cprintf(">");
while(1)
	{
   gotoxy(80,25);
   ch=getch();
   if(ch==0) ch=getch();
   if(ch==13)
   	{
      if(row==6)
      	{
         insert_new_member();
         goto showagain;
         }//if
      if(row==7)
         {
         delete_member();
         goto showagain;
         }//if
      if(row==8)
         {
         revival_credit_date();
         goto showagain;
         }//if
      if(row==9)
      	{
         edit_member_info();
         goto showagain;
         }//if
      if(row==10)
         {
			show_all_club_members();
         goto showagain;
         }//if
      if(row==11)
         {
			show_all_branch_members();
         goto showagain;
         }//if
      if(row==12)
         {
			show_all_exp_members();
         goto showagain;
         }//if
      if(row==13)
      	{
         search_by_id();
         goto showagain;
         }//if
      if(row==14)
      	{
         search_by_name();
         goto showagain;
         }//if
      if(row==15) return;
      }//if
   if(ch==80)
   	{
      brow=row;
      row++;
      }//if
   if(ch==72)
   	{
      brow=row;
      row--;
      }//if
   if(row==5) row=15;
   if(row==16) row=6;
   gotoxy(7,brow);cprintf(" ");
   gotoxy(7,row);cprintf(">");
   }//while
gotoxy(80,25);
}//menu
//------------------------------------------------------------------------------
void inputfile()
{
clubtree.load();
}//inputfile
//------------------------------------------------------------------------------
void outputfile()
{
clubtree.save(clubtree.getRoot());
}//outputfile
//------------------------------------------------------------------------------
void todaydate()
{
clrscr();
textcolor(13);
gotoxy(22,2);
cprintf("***<<SPORT CLUB MANAGEMENT SYSTEM>>***");
textcolor(11);
gotoxy(22,3);
cprintf("< ----- Enter Today Date  Menu ----- >");
textcolor(15);
gotoxy(6,6);cprintf("Today Year  : ");cin>>todayy;
while(todayy<1300 || todayy>2000)
	{
   gotoxy(20,6);
   cout<<"              ";
   gotoxy(20,6);
   cin>>todayy;
   }//while
gotoxy(6,8);cprintf("Today Month : ");cin>>todaym;
while(todaym<1 || todaym>12)
	{
   gotoxy(20,8);
   cout<<"              ";
   gotoxy(20,8);
   cin>>todaym;
   }//while
gotoxy(6,10);cprintf("Today Day   : ");cin>>todayd;
int flag=1;
if(todaym>=7 && todaym<=12 && todayd==31)
	flag=0;
while(todayd<1 || todayd>31 || flag==0)
	{
   gotoxy(20,10);
   cout<<"              ";
   gotoxy(20,10);
   cin>>todayd;
   flag=1;
   if(todaym>=7 && todaym<=12 && todayd==31)
		flag=0;
   }//while
}//todaydate
//==============================================================================
void main()
{
inputfile();
todaydate();
menu();
outputfile();
}//main
//==============================================================================
