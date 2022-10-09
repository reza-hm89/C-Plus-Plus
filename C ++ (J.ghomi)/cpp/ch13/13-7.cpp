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
      listNode< NODETYPE >  *lastptr;
      listNode< NODETYPE >  *getnewnode (const NODETYPE &);
};
//******************
template <class NODETYPE>
list <NODETYPE>::list() : firstPtr(0), lastptr(0) {}
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
  listNode<NODETYPE> *newPtr = getnewnode(value);
  if(isEmpty())  //list is empty
      firstPtr = lastptr = newPtr;
  else {    //list is not empty
      newPtr -> nextPtr = firstPtr;
      firstPtr = newPtr;
  }
}
//*insert a node at the back of the list********
template <class NODETYPE >
void list < NODETYPE >::insertAtBack(const NODETYPE &value)
{
  listNode<NODETYPE> *newPtr = getnewnode(value);
  if(isEmpty())
     firstPtr = lastptr = newPtr;
  else {
     lastptr -> nextPtr = newPtr;
     lastptr = newPtr;
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
      if(firstPtr == lastptr)
	       firstPtr = lastptr = 0;
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
      listNode <NODETYPE> *tempPtr = lastptr;
      if(firstPtr == lastptr)
	      firstPtr = lastptr = 0;
      else {
	      listNode <NODETYPE> *currentPtr =firstPtr;
	      while(currentPtr -> nextPtr != lastptr)
	         currentPtr = currentPtr -> nextPtr;
	      lastptr = currentPtr;
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
listNode<NODETYPE> *list <NODETYPE>::getnewnode(const NODETYPE &value)
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
      cout << "The list is empty.";
      getch();
      return;
   }
   listNode <NODETYPE> *currentPtr = firstPtr;
   cout << "the list is:";
   while(currentPtr != 0) {
      cout << currentPtr -> data << "   ";
      currentPtr = currentPtr -> nextPtr;
   }
   cout << "\n";
}
//***********************
template<class QUEUETYPE>
class queue:private list<QUEUETYPE> {
   public:
      void enqueue(const QUEUETYPE &d) { insertAtBack(d); }
      int dequeue(QUEUETYPE &d)
      {
	      return removeFromFront(d);
      }
      int isQueueEmpty() const  { return isEmpty(); }
      void prntQueue() const { print() ;}
};
//**************
int main()
{
  queue<int> intQueue;
  int i, dequeueint;
  clrscr();
  cout << "processing an integer queue " << endl;
  for(i = 0; i < 4; i ++) {
      intQueue.enqueue(i);
      intQueue.prntQueue();
  }
  while(!intQueue.isQueueEmpty()) {
      intQueue.dequeue(dequeueint);
      cout << dequeueint << " dequeued " << endl;
      intQueue.prntQueue();
  }
  queue<double> doubleQueue;
  double val = 1.1, dequeuedouble;
  cout << "\nprocessing a double queue " << endl;
  for(i = 0; i < 4; i ++) {
      doubleQueue.enqueue(val);
      doubleQueue.prntQueue();
      val += 1.1;
  }
  while(!doubleQueue.isQueueEmpty()) {
      doubleQueue.dequeue(dequeuedouble);
      cout << dequeuedouble << " dequeued " << endl;
      doubleQueue.prntQueue();
  }
  return 0;
}
