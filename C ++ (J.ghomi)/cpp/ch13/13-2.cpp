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
     NODETYPE getdata() const;     //return data in the node
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
NODETYPE listNode<NODETYPE>::getdata() const { return data; }
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
      listNode < NODETYPE > *currentPtr = firstPtr, *tempptr;
      while(currentPtr != 0) {   //delete remaining nodes
	 tempptr = currentPtr;
	 cout << tempptr -> data << "\n";
	 currentPtr = currentPtr -> nextPtr;
	 delete tempptr;
      }
    }
    cout << "All nodes destroyed\n\n";
}
//**************
//insert a node at the front of list
template<class NODETYPE>
void list< NODETYPE >::insertAtFront(const NODETYPE &value)
{
  listNode<NODETYPE> *newptr = getnewnode(value);
  if(isEmpty())  //list is empty
      firstPtr = lastptr = newptr;
  else {    //list is not empty
      newptr -> nextPtr = firstPtr;
      firstPtr = newptr;
  }
}
//*insert a node at the back of the list********
template <class NODETYPE >
void list < NODETYPE >::insertAtBack(const NODETYPE &value)
{
  listNode<NODETYPE> *newptr = getnewnode(value);
  if(isEmpty())
     firstPtr = lastptr = newptr;
  else {
     lastptr -> nextPtr = newptr;
     lastptr = newptr;
  }
}
//**delete a node from the front of the list
template <class NODETYPE >
int list <NODETYPE>::removeFromFront(NODETYPE &value)
{
   if(isEmpty())
       return 0;
   else {
      listNode <NODETYPE> *tempptr = firstPtr;
      if(firstPtr == lastptr)
	 firstPtr = lastptr = 0;
      else
	 firstPtr = firstPtr -> nextPtr;
      value = tempptr -> data;   //data being removed
      delete tempptr;
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
      listNode <NODETYPE> *tempptr = lastptr;
      if(firstPtr == lastptr)
	 firstPtr = lastptr = 0;
      else {
	  listNode <NODETYPE> *currentPtr =firstPtr;
	  while(currentPtr -> nextPtr != lastptr)
	      currentPtr = currentPtr -> nextPtr;
	  lastptr = currentPtr;
	  currentPtr -> nextPtr = 0;
      } //end of else
      value = tempptr -> data;
      delete tempptr;
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
   cout << "The list is:\n";
   while(currentPtr != 0) {
      cout << currentPtr -> data << "\n";
      currentPtr = currentPtr -> nextPtr;
   }
   getch();
   cout << "\n";
}
//******************
template <class T>
void testList(list <T> &listobject, char *type)
{
  int choice;
  T value;
  do {
     clrscr();
     instructions();
     cout << "Enter your choice ? ";
     cin >> choice;
     switch(choice) {
	case 1:
	   cout << "Enter " << type << ": ";
	   cin >> value;
	   listobject.insertAtFront(value);
	   break;
	case 2:
	   cout << "Enter " << type << ": ";
	   cin >> value;
	   listobject.insertAtBack(value);
	   break;
	case 3:
	   if ( listobject.removeFromFront(value))
	      cout << value << " Remove from list\n";
	   break;
	case 4:
	   if ( listobject.removeFromBack(value))
	      cout << value << " Removed from list\n";
	   break;
	case 5:
	   listobject.print();
	   break;
     }
   } while(choice != 6);
   cout << "End list test.\n";
}
//*********************
void instructions()
{
  cout << "1. Insert at begining of list\n"
       << "2. Insert at the end of list\n"
       << "3. To delete from begining of list\n"
       << "4. To delete from end of list\n"
       << "5. Display of list \n"
       << "6. End of list processing\n";
}
//*************
int main()
{
  char ans;
  clrscr();
  cout << "int list or float list(i or f):";
  cin  >> ans;
  if ( ans == 'i') {
     list<int> integerList;
     testList(integerList, "Integer");
   }
  else if ( ans == 'f') {
     list<float> floatList;
     testList(floatList, "Float");
  }
  return 0;
}









