#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
template <class T>
class stack {
    public:
	  stack(int = 10);   //default constructor(stack size 10)
	  ~stack() { delete [] stackPtr; }
	  int push(const T &); // push an element onto the stack
	  int pop(T&);        //pop an element off the stack
    private:
	  int size;
	  int top;
	  T *stackPtr;
	  int isEmpty() const { return top == - 1; }
	  int isFull() const { return top == size - 1; }
};
//**********
template <class T>
stack <T>::stack(int s)
{
  size = s > 0 ? s : 10;
  top = -1;             //stack is empty
  stackPtr = new T[size];
}
//********
template <class T>
int stack <T>::push(const T &pushValue)
{
  if(!isFull()) {
      stackPtr[ ++top ] = pushValue;
      return 1;
  }
  return 0;
}
//******************
template <class T>
int stack <T>::pop(T &popValue)
{
  if(!isEmpty()) {
       popValue = stackPtr[top--];
       return 1;
  }
  return 0;
}
//**********************
int main()
{
   clrscr();
   stack<double> doubleStack(5);
   double f = 1.1;
   cout << "Pushing elements onto doubleStack\n";
   while(doubleStack.push(f)) {
      cout << f << " ";
      f += 1.1;
   }
   cout << "\nStack is full. Cannot push " << f
	<< "\nPopping elements from doubleStack\n";
   while(doubleStack.pop(f))
       cout << f << "  ";
   cout << "\nStack is empty. Cannot pop \n";
   stack<int> intStack;
   int i = 1;
   cout << "Pushing elements onto intStack\n";
   while(intStack.push(i)) {
      cout << i << " ";
      ++ i;
   }
   cout << "\nStack is full. Cannot push " << i
	<< "\nPopping elements from intStack\n";
   while(intStack.pop(i))
       cout << i << "  ";
   cout << "\nStack is empty. cannot pop \n";
   getch();
   return 0;
}




