//===============================================
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
//===============================================
struct Program
{
   int code;
   char name[15];
   int date_create;
   int date_view;
   int date_first;
   int rep;
   char direct[15];
   char chanel[15];
   char type[15];
}temp;
//===============================================
struct TreeNode
{
   Program data;
   TreeNode *left,*right;
};
TreeNode *start;
//===============================================
void topic()
{
   cout<<" | =============== Main Menu =============== |"<<endl;
   cout<<" | 1-Add New Program                         |"<<endl;
   cout<<" | 2-Remove Program by Code                  |"<<endl;
   cout<<" | 3-Edit Program by Code                    |"<<endl;
   cout<<" | 4-Search Program by Code                  |"<<endl;
   cout<<" | 5-Enter Date's View Program               |"<<endl;
   cout<<" | 6-Enter Date's View First Repeat Program  |"<<endl;
   cout<<" | 7-Print Programs Sort by Code             |"<<endl;
   cout<<" | 8-Print Program in Selection Date         |"<<endl;
   cout<<" | 9-Print Program From The Chanel           |"<<endl;
   cout<<" | 10-Print Program From The Director        |"<<endl;
   cout<<" | 11-Print Program Repeated                 |"<<endl;
   cout<<" | 12-Exit                                   |"<<endl;
   cout<<" | ========================================= |"<<endl;
}
//===============================================
int Insert(TreeNode *&root,int x)
{
   TreeNode *p,*q;
   p=root;
   q=NULL;
   while(p)
   {
	q=p;
	if(p->data.code==x)
		return 0;
	if(x<p->data.code)
		p=p->left;
	else
		p=p->right;
   }
   p=new TreeNode;
   p->left=p->right=NULL;
   if(!root)
	root=p;
   else if (q->data.code>x)
	q->right=p;
   else
	q->right=p;
   return 1;
}
//===============================================
void add_program()
{
   clrscr();
   topic();
   cout<<endl<<"Enter Program's Code : ";
   cin>>temp.code;
   cout<<endl<<"Enter Program's Name : ";
   gets(temp.name);
   cout<<endl<<"Enter Program's Create Date : ";
   cin>>temp.date_create;
   cout<<endl<<"Enter Program's View Date : ";
   cin>>temp.date_view;
   cout<<endl<<"Enter Program's First View Date : ";
   cin>>temp.date_first;
   cout<<endl<<"Enter Program's Number of Frequency : ";
   cin>>temp.rep;
   cout<<endl<<"Enter Program's Director : ";
   gets(temp.direct);
   cout<<endl<<"Enter Program's Chanel Name : ";
   gets(temp.chanel);
   cout<<endl<<"Enter Program's Type : ";
   gets(temp.type);
   TreeNode *root=start;
   Insert(*root,temp.code);
   cout<<endl<<"\t Set Program Success !";
   getche();
}
//===============================================
TreeNode *BinarySearch(TreeNode *root,int key)
{
   while(root)
   {
	if(root->data.code==key)
		return root;
	else if (key<root->data.code)
		root=root->left;
	else
		root=root->right;
   }
   return NULL;
}
//===============================================
void search_program()
{
   clrscr();
   topic();
   int key;
   cout<<" Please Type Code to be Searched : ";
   cin>>key;
   TreeNode *root=start;
   BinarySearch(*root,key);
   if(root)
	Show(*root);
   else
	cout<<" False ,The Program don't Exist in this List";
   getche();
}
//===============================================
void Show(TreeNode *root)
{
   cout<<endl<<"Program's Code : "<<root->data.code;
   cout<<endl<<"Program's Name : ";
   puts(root->data.name);
   cout<<endl<<"Program's Create Date : "<<root->data.date_create;
   cout<<endl<<"Program's View Date : "<<root->data.date_view;
   cout<<endl<<"Program's First View Date : "<<root->data.date_first;
   cout<<endl<<"Program's Number of Frequency : "<<root->data.rep;
   cout<<endl<<"Program's Director : ";
   gets(root->data.direct);
   cout<<endl<<"Program's Chanel Name : ";
   gets(root->data.chanel);
   cout<<endl<<"Program's Type : ";
   gets(root->data.type);
   getche();
}
//===============================================
void edit_program()
{
   clrscr();
   topic();
   cout<<" Please Type IDNumber to be Edited : ";

   getche();
}
//===============================================
void enter_date()
{
}
//===============================================
void enter_date_fr()
{
}
//===============================================
void print_sort()
{
}
//===============================================
void print_selection()
{
}
//===============================================
void print_chanel()
{
}
//===============================================
void print_director()
{
}
//===============================================
void print_repeated()
{
}
//===============================================
void remove_program()
{
   clrscr();
   topic();
   cout<<" Please Type IDNumber to be Removed : ";

   getche();
}
//-----------------------------------------------
int main()
{
   int nfunc;
   while(1)
   {
	clrscr();
	topic();
	cout<<" Please Select Number From Menu : ";
	cin>>nfunc;
	switch(nfunc)
	{
		case 1:
			add_program();
			break;
		case 2:
			remove_program();
			break;
		case 3:
			edit_program();
			break;
		case 4:
			search_program();
			break;
		case 5:
			enter_date();
			break;
		case 6:
			enter_date_fr();
			break;
		case 7:
			print_sort();
			break;
		case 8:
			print_selection();
			break;
		case 9:
			print_chanel();
			break;
		case 10:
			print_director();
			break;
		case 11:
			print_repeated();
			break;
		case 12:
			return 0;
	}
   }
}
//-----------------------------------------------