#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
class  node {
       friend class linkList;
       char name[21];
       int stno;
       float ave;
       node *next;
       node *prior;
};
//******************
class  linkList {
   public:
      linkList();
      ~linkList();
      void addNode();
      void delNode(int &);
      void display();
   private:
      node *first;
      node *last;
};
//*****************
linkList::linkList()
{
   first = last = NULL;
}
//************
linkList::~linkList()
{
  node *curPtr = first;
  node *temp;
  while(curPtr) {
      temp = curPtr;
      delete temp;
      curPtr = curPtr -> next;
  }
}
//*******************
void linkList:: delNode(int &no)
{
  node *curPtr = first ;
  while(curPtr) {
     if(no == curPtr -> stno )
	  if (curPtr == first) {
	      first = first -> next;
	      first -> prior = NULL;
	      delete curPtr;
	      break;
	  }
	  else {
	       if (curPtr == last)
		   last = curPtr -> prior;
	       curPtr -> prior -> next = curPtr -> next;
	       curPtr -> next -> prior = curPtr -> prior;
	       delete curPtr;
	       break;
	  }
     else
	  curPtr = curPtr -> next;
  }
}
//******************
void linkList::addNode()
{
   node *newPtr = new node;
   if(!newPtr) {
     cout << "allocation";
     getch();
   }
   newPtr -> next = NULL;
   clrscr();
   cout << "name              "
       << "stno     " << "  average\n";
   gotoxy(1, 2);
   cin >> newPtr -> name;
   gotoxy(20, 2);
   cin >> newPtr -> stno;
   gotoxy(30, 2);
   cin >> newPtr -> ave;
   if (first == NULL)
      first = last = newPtr;
   else {
	last -> next = newPtr;
	newPtr ->prior = last;
	last = newPtr;
   }
}
//****************
void linkList::display()
{
  int r = 2;
  clrscr();
  cout << "Name              "
       << "Stno     " << "  Average\n";
  node *curPtr = first;
  while(curPtr) {
     gotoxy(1, r);
     cout << curPtr -> name << "     ";
     gotoxy(20, r);
     cout << curPtr -> stno << "  ";
     gotoxy(30, r);
     cout << curPtr -> ave << "  ";
     curPtr = curPtr -> next;
     r ++;
  }
}
//**********
int menu();
int main()
{
  int no;
  linkList testList;
  for (;;) {
     clrscr();
     switch(menu()) {
	      case 1: testList.addNode();   break;
	      case 2:
	         cout << "Enter stno to delete :";
	         cin >> no;
	         testList.delNode(no);   break;
         case 3: testList.display(); getch();  break;
	      case 4: exit(1);
     }
  }
}
//*************
int menu()
{
  int choice;
  cout << "1. Entre a student.\n"
       << "2. Delete a student. \n"
       << "3. Display list.\n"
       << "4. End of program.\n";
  cout << "\n Enter your select(1-4):";
  cin >> choice;
  return choice;
}





