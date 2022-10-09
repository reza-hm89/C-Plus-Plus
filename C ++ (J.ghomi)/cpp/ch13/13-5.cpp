#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
//void instruction();
template <class NODETYPE> class list; //forward declaration
template <class NODETYPE>
class   listNode {
     friend class list<NODETYPE>;  //make list a friend
  public:
     listNode(const NODETYPE &);   //constructor
     NODETYPE getData() const;     //return data in the node
  private:
     NODETYPE  data;
     listNode<NODETYPE> *nextPtr;
};
//****constructor*******
template<class NODETYPE>
listNode<NODETYPE>::listNode(const NODETYPE &info)
		  : data(info), nextPtr(0) { }

//return a copy of the data in the node
template<class NODETYPE>
NODETYPE listNode<NODETYPE>::getData() const { return data; }
//************
template <class NODETYPE>
class list {
   public:
      list();
      ~list();
      void insertAtFront(const NODETYPE &);
      void insertAtBack(const NODETYPE &);
      int  removeFromFront(NODETYPE &);
      int  removeFromBack(NODETYPE &);
      int  isEmpty() const;
      void print() const;
   private:
   listNode< NODETYPE >  *firstPtr;
   listNode< NODETYPE >  *lastPtr;
   listNode< NODETYPE >  *getNewNode (const NODETYPE &);
};
//******************
template <class NODETYPE>
list <NODETYPE>::list() : firstPtr(0), lastPtr(0) {}
//**************
template <class NODETYPE>
list <NODETYPE>::~list()
{
   if(!isEmpty())  { //list is not empty
      cout << "Destructing nodes ...\n";
      listNode < NODETYPE > *currentPtr = firstPtr, *tempPtr;
      while(currentPtr != 0) {   //delete remaining nodes
	 tempPtr = currentPtr;
	 cout << tempPtr -> data << "\n";
	 currentPtr = currentPtr -> nextPtr;
	 delete tempPtr;
      }
    }
    cout << "All nodes destroyed\n\n";
}
//**************
//insert a node at the front of list
template<class NODETYPE>
void list< NODETYPE >::insertAtFront(const NODETYPE &value)
{
  listNode<NODETYPE> *newptr = getNewNode(value);
  if(isEmpty())  //list is empty
      firstPtr = lastPtr = newptr;
  else {    //list is not empty
      newptr -> nextPtr = firstPtr;
      firstPtr = newptr;
  }
}
//*insert a node at the back of the list********
template <class NODETYPE >
void list < NODETYPE >::insertAtBack(const NODETYPE &value)
{
  listNode<NODETYPE> *newptr = getNewNode(value);
  if(isEmpty())
     firstPtr = lastPtr = newptr;
  else {
     lastPtr -> nextPtr = newptr;
     lastPtr = newptr;
  }
}
//**delete a node from the front of the list
template <class NODETYPE >
int list <NODETYPE>::removeFromFront(NODETYPE &value)
{
   if(isEmpty())
       return 0;
   else {
      listNode <NODETYPE> *tempPtr = firstPtr;
      if(firstPtr == lastPtr)
	 firstPtr = lastPtr = 0;
      else
	 firstPtr = firstPtr -> nextPtr;
      value = tempPtr -> data;   //data being removed
      delete tempPtr;
      return 1;  //delete successfully
   }
}
//**delete a node from back of list*********
template <class NODETYPE >
int list <NODETYPE>::removeFromBack(NODETYPE &value)
{
   if(isEmpty())
       return 0;
   else {
      listNode <NODETYPE> *tempPtr = lastPtr;
      if(firstPtr == lastPtr)
	 firstPtr = lastPtr = 0;
      else {
	  listNode <NODETYPE> *currentPtr =firstPtr;
	  while(currentPtr -> nextPtr != lastPtr)
	      currentPtr = currentPtr -> nextPtr;
	  lastPtr = currentPtr;
	  currentPtr -> nextPtr = 0;
      } //end of else
      value = tempPtr -> data;
      delete tempPtr;
      return 1;  //delete successfully
   }
}
//***************
template <class NODETYPE >
int list<NODETYPE>::isEmpty() const
{
   return firstPtr == 0;
}
//****************
template <class NODETYPE >
listNode<NODETYPE> *list <NODETYPE>::getNewNode(const NODETYPE &value)
{
  listNode <NODETYPE> *ptr = new listNode <NODETYPE> (value);
  if(ptr == 0) {
      cout << "Allocation failure...";
      getch();
      exit(1);
  }
  return ptr;
}
//*********************
template <class NODETYPE >
void list<NODETYPE>:: print() const
{
   if(isEmpty()) {
      cout << " The list is empty.\n";
      getch();
      return;
   }
   listNode <NODETYPE> *currentPtr = firstPtr;
   cout << "The list is:";
   while(currentPtr != 0) {
      cout << currentPtr -> data << "  ";
      currentPtr = currentPtr -> nextPtr;
   }
   getch();
   cout << "\n";
}
//**************
template <class STACKTYPE>
class stack : private list<STACKTYPE> {
   public:
      void push(const STACKTYPE &d)
      {
	insertAtFront(d);
      }
      int pop(STACKTYPE &d)
      {
	return removeFromFront(d);
      }
      int isStackEmpty() const
      {
	return isEmpty();
      }
      void printStack()
      {
	print();
      }
};
//***************
int main()
{
   stack <int> intStack;
   int popInt, i;
   clrscr();
   cout << "Processing an integer stack" << endl;
   for(i = 0; i < 4; i ++) {
      intStack.push(i);
      intStack.printStack();
   }
   while(!intStack.isStackEmpty()) {
      intStack.pop(popInt);
      cout << popInt << " Poped from stack " << endl;
      intStack.printStack();
   }
   stack <double> doubleStack;
   double val = 1.1, popDouble;
   cout << "Processing an double stack" << endl;
   for(i = 0; i < 4; i ++) {
      doubleStack.push(val);
      doubleStack.printStack();
      val += 1.1;
   }
   while(!doubleStack.isStackEmpty()) {
      doubleStack.pop(popDouble);
      cout << popDouble << " Poped from stack " << endl;
      doubleStack.printStack();
   }
   return 0;
}
