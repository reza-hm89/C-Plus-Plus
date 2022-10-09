#include<stdio.h>
struct stacknode
{
	int item;
	stacknode *next;
};
class stack {
	private:
		stacknode *top;
	public:
		stack() { top=NULL; };
		void push(int item);
		int  pop();
		int  empty();
	};
////////////////////////////////////////
int stack::empty() {
	if (top==NULL)
		return 1;
	else	return 0;
	}
////////////////////////////////////////
int stack::pop()
{
	int item;
	stacknode *p;
	if (empty())
		return NULL;
	item=top->item;
	p=top;
	top=top->next;
	delete p;
	return item;
}
////////////////////////////////////////
void stack::push(int item)
{
	stacknode *p;
	p=new stacknode;
	p->item=item;
	p->next=top;
	top=p;
}