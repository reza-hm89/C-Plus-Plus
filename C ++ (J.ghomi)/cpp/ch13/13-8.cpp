#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <assert.h>
template <class NODETYPE> class tree;
template <class NODETYPE>
class treeNode {
    friend class tree <NODETYPE>;
 public:
    treeNode(const NODETYPE &d) : leftPtr(0), data(d), rightPtr(0) {}
    NODETYPE  getData() const { return data ; }
 private:
    treeNode<NODETYPE> *leftPtr;
    NODETYPE data;
    treeNode<NODETYPE> *rightPtr;
};
//*******************
template <class NODETYPE>
class tree {
    public:
       tree();
       void insertNode(const NODETYPE &);
       void preorder() const;
       void inorder() const;
       void postorder() const;
    private:
       treeNode <NODETYPE>  *rootPtr;
       void insertHelp(treeNode<NODETYPE> **,  const NODETYPE &);
       void preHelp(treeNode <NODETYPE> *) const;
       void inHelp(treeNode <NODETYPE> *) const;
       void postHelp(treeNode <NODETYPE> *) const;
};
//***************
template<class NODETYPE>
tree<NODETYPE>::tree() { rootPtr = 0; }
//****************
template <class NODETYPE>
void  tree <NODETYPE>::insertNode(const NODETYPE &value)
{
  insertHelp(&rootPtr, value);
}
//***************
template<class NODETYPE>
void  tree <NODETYPE>::insertHelp(treeNode< NODETYPE> **ptr,
				  const NODETYPE &value)
{
  if(*ptr == 0) { //tree is empty
      *ptr = new treeNode <NODETYPE> (value);
       assert(*ptr !=0);
  }
  else
      if(value < (*ptr) -> data)
	 insertHelp( & ( (*ptr) -> leftPtr), value);
      else
	 if( value > ( *ptr ) -> data)
	    insertHelp( & ( (*ptr) -> rightPtr), value);
	 else
	    cout << value << " is duplicated" << endl;
}
//*****************
template<class NODETYPE>
void tree <NODETYPE>::preorder() const
{
   preHelp(rootPtr);
}
//*****************
template <class NODETYPE>
void tree <NODETYPE>::preHelp(treeNode  <NODETYPE> *ptr) const
{
   if(ptr != 0) {
       cout << ptr -> data << " ";
       preHelp(ptr -> leftPtr);
       preHelp(ptr -> rightPtr);
   }
}
//**************
template<class NODETYPE>
void tree <NODETYPE>::inorder() const
{
   inHelp(rootPtr);
}
//******************
template <class NODETYPE>
void tree <NODETYPE>::inHelp(treeNode  <NODETYPE> *ptr) const
{
   if(ptr != 0) {
       inHelp(ptr -> leftPtr);
       cout << ptr -> data << " ";
       inHelp(ptr -> rightPtr);
   }
}
//**************
template<class NODETYPE>
void tree <NODETYPE>::postorder() const
{
   postHelp(rootPtr);
}
//******************
template <class NODETYPE>
void tree <NODETYPE>::postHelp(treeNode  <NODETYPE> *ptr) const
{
   if(ptr != 0) {
       postHelp(ptr -> leftPtr);
       postHelp(ptr -> rightPtr);
       cout << ptr -> data << " ";
   }
}
//*********************
int main()
{
   clrscr();
   tree <int> inttree;
   int i, intval;
   cout << "Enter 10 integer values:\n";
   for(i = 0; i < 10; i ++) {
       cin >> intval;
       inttree.insertNode(intval);
   }
   cout << "\nPreorder traversal\n";
   inttree.preorder();
   cout << "\nInorder traversal\n";
   inttree.inorder();
   cout << "\nPostorder traversal\n";
   inttree.postorder();
   tree<double> doubleTree;
   double doubleval;
   cout << "\nEnter 10 double values:\n"
	<< setiosflags(ios::fixed | ios::showpoint)
	<< setprecision(1);
   for(i = 0; i < 10; i ++) {
       cin >> doubleval;
       doubleTree.insertNode(doubleval);
   }
   cout << "\nPreorder traversal\n";
   doubleTree.preorder();
   cout << "\nInorder traversal\n";
   doubleTree.inorder();
   cout << "\nPostorder traversal\n";
   doubleTree.postorder();
   getch();
   return 0;
}


