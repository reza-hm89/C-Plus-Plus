#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>   //for exit(0)

int a[5][5]={{1,1,0,1,0},
		     {0,0,1,0,0},
		     {1,0,0,1,0},
		     {0,1,1,0,1},
		     {0,0,0,0,1}};

	int b[5][5]={{1,0,1,0,0},
		     {1,0,1,0,1},
		     {0,0,0,0,0},
		     {0,1,1,0,0},
		     {0,1,1,1,0}};
//===============================
struct listnode
{
	int row,col,data;
	listnode *next;
};
//===============================
class Sparse
{
	listnode *start;
	public:
		Sparse() { start=NULL; };
		void Insert(listnode *newnode);
		void Transpose(Sparse);
		void Add(Sparse);
		void Display(Sparse);
};
//===============================
void Sparse::Insert(listnode *newnode)
{
	listnode *prev,*cur;
	//list is NULL and add in firstlist
	if (!start)
	{
		start=newnode;
		start->next=NULL;
		return;
	}
	prev=NULL;
	cur=start;
	while (cur && cur->data<newnode->data)
	{
		prev=cur;
		cur=cur->next;
	}
	//Add in first list
	if (!prev)
	{
		newnode->next=start;
		start=newnode;
	}
	//Add in middle or end of list
	else
	{
		prev->next=newnode;
		newnode->next=cur;
	}
}
//===============================
void Sparse::Add(Sparse b)
{
	int sw=0;
	Sparse c;
	listnode *p,*q,*cur;
	p=new listnode;
	q=new listnode;
	cur=new listnode;
	p=start;
	cur=c.start;
	while (p)
	{
	q=b.start;
	sw=0;
	while (q)
	{
		if (p->row==q->row && p->col==q->col)
		{
			cur=new listnode;
			cur->row=p->row;
			cur->col=p->col;
			cur->data=(p->data+q->data);
			c.Insert(cur);
			cur=cur->next;
			sw=1;
		}
		q=q->next;
	}
	if (sw==0)
	{
		cur=new listnode;
		cur->row=p->row;
		cur->col=p->col;
		cur->data=p->data;
		c.Insert(cur);
		cur=cur->next;
	}
	p=p->next;
	}
	c.Display(c);
}
//===============================
void Sparse::Transpose(Sparse cur)
{
	Sparse temp;
	listnode *p,*q;
	p=new listnode;
	q=new listnode;
	p=cur.start;
	q=temp.start;
	while (p)
	{
		q=new listnode;
		q->row=p->col;
		q->col=p->row;
		q->data=p->data;
		temp.Insert(q);
		p=p->next;
	}
	temp.Display(temp);
}
//===============================
void Sparse::Display(Sparse cur)
{
	clrscr();
	listnode *p;
	p=new listnode;
	p=cur.start;
	while (p)
	{
		cout<<"\nrow: "<<p->row;
		cout<<"\ncol: "<<p->col;
		cout<<"\nValue: "<<p->data;
		p=p->next;
	}
	getch();
}
//===============================
int Menu();
void Select();
//===============================
void main()
{
	clrscr();
	Select();
}
//=======================================
int Menu()
{
	int n;
	clrscr();
	cout<<"1.Insert Matrix A";
	cout<<"\n2.Insert Matrix B";
	cout<<"\n3.Add A+B";
	cout<<"\n4.Transpose A";
	cout<<"\n5.Exit";
	cout<<"\n\nEnter 1-5: ";
	do {
		gotoxy(15,7);
		cin>>n;
	}while (n>5);
	return n;
}
//=======================================
void Select()
{
	int n,num,sw1=0,sw2=0;
	listnode *p;
	Sparse s1,s2;
	p=new listnode;
	while (1)
	{
	n=Menu();
	switch (n)
	{
		//for matrix A
		case 1:
			p=NULL;
			if (sw1==0) {
			for (int i=0;i<5;i++)
				for (int j=0;j<5;j++)
					if (a[i][j])
				{
					p=new listnode;
					p->row=i+1;
					p->col=j+1;
					p->data=a[i][j];
					s1.Insert(p);
					sw1=1;
				}
			}
			s1.Display(s1);
			break;
		//for Matrix B
		case 2:
			p=NULL;
			if (sw2==0) {
			for (int i=0;i<5;i++)
				for (int j=0;j<5;j++)
					if (b[i][j])
				{
					p=new listnode;
					p->row=i+1;
					p->col=j+1;
					p->data=b[i][j];
					s2.Insert(p);
				}
			sw2=1;
			}
			s2.Display(s2);
			break;
		case 3:
			s1.Add(s2);
			break;
		case 4:
			s1.Transpose(s1);
			break;
		case 5:
			exit(0);
			break;
	}
	}//end of while (1)
}