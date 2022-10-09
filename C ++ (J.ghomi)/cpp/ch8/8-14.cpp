#include <iostream.h>
#include <conio.h>
#include <assert.h>
#include <stdlib.h>
class array {
   friend ostream &operator << (ostream&, const array &);
   friend istream &operator >> (istream&, array &);
public:
   array(int = 10);   //default constructor
   array(const array&);   //copy constructor
   ~array();   //destructor
   int getSize() const;   //return size
   const array &operator = (const array &); //assign arrays
   int operator == (const array &);   //compare equal
   // determine if two arrays are not equal and
   // return true, otherwise return false
   int operator != (const array &right)
   {
      return !(*this == right);
   }
   int &operator[] (int);   //subscript operator
   const int &operator[] (int) const; //subscript operator
   static int getArrayCount();   //return count of arrays instantation
private:
   int size; //size of the array
   int *ptr;
   static int arrayCount; // # of arrays instantiated
};
//******************8
//initialize static data member at file scope
int array::arrayCount = 0; //no objects yet
//default constructor for class array(default size = 10)
array::array(int arraySize)
{
   size = (arraySize > 0 ? arraySize : 10);
   ptr = new int[size];   //create space for array
   assert(ptr != 0);   //terminate if memory not allocated
   ++arrayCount;   //count one more object
   for(int i= 0; i < size; i++)
      ptr[i] = 0;   //initialize array
}
//copy constructor for class array
array::array(const array &init) : size(init.size)
{
   ptr = new int[size];   //create space for array
   assert(ptr != 0);
   ++arrayCount;
   for(int i = 0; i < size; i++)
   ptr[i] = init.ptr[i];   //copy into object
}
//*********************
array::~array()
{
   delete[] ptr;
   --arrayCount;
}
//*********************
//get the size of array
int array::getSize() const { return size;}
//overload assignment operator
//const return avoids:(a1 = a2) = a3
const array &array::operator=(const array &right)
{
   if(&right != this) {   //check for self assignment
      if(size != right.size) {
         delete[] ptr;   //reclaim space
         size = right.size;   //resize this object
         ptr = new int[size];   //create spase for array copy
         assert(ptr != 0);
      }
      for(int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];   //copy array into object
   }//end of if
   return *this;// enable x = y = z;
}
//*********************
//determine if two arrays are equal
int array::operator==(const array &right)
{
   if(size != right.size)
      return 0;   //arrays of different size
   for(int i = 0; i < size; i++)
   if(ptr[i] != right.ptr[i])
     return 0;   //array are not equal
   return 1;   //array are equal
}
//overload subscript
int &array::operator[] (int subscript)
{
//check for subscript out of range
if(subscript < 0 && subscript > size)
   exit(1);
return ptr[subscript];   //reference return
}
//**overloded subscript operator for cons array
const int &array::operator[](int subscript) const
{
   //check for subscript out of range error
   assert(0 <= subscript && subscript < size);
   return ptr[subscript];   //constant regerence return
}
//return the number of array objects instantiated
int array::getArrayCount() { return arrayCount;}
//overload input operator for class array
istream &operator >> (istream &input, array &a)
{
  for(int i = 0; i < a.size; i++)
      input >> a.ptr[i];
  return input; //enable cin >> x >> y;
}
// overload output operator for class array
ostream &operator<< (ostream &output, const array &a)
{
  int i;
  for(i = 0; i < a.size; i++)
  {
     output << "    " << a.ptr[i];
     if((i + 1) %4 == 0)   //for numbers per row of output
         output << endl;
  }
  if(i % 4 != 0)
     output << endl;
  return output;
}
//***************
int main()
{
   clrscr();
   cout << "Number of array objects = " << array::getArrayCount() << endl;
   //create two arrays and print array count
   array integers1(7), integers2;
   cout << "Number of array objects = " << array::getArrayCount() << "\n\n";
   cout << "Size of array integers1 is: " << integers1.getSize();
   cout << "\nArray after initialization:\n" << integers1 << "\n";
   cout << "Size of array integers2 is: " << integers2.getSize();
   cout << "\nArray after initialization:" << integers2 << "\n";
   //input arrays integers1, integers2
   cout << "Input 17 integer values \n";
   cin >> integers1 >> integers2;
   cout << "After input, the arrays contain: \n";
   cout << "integers1: " << integers1;
   cout << "integers2: " << integers2;
   //use overloaded inequality(!=) operator
   cout << "Evaluating : integers1 != integers2\n";
   if(integers1 != integers2)
       cout << "They are not equal";
   //create array integers3 using integers1 as an initializer...
   array integers3(integers1);
   cout << "\nSize of array integers3 is: " << integers3.getSize();
   cout << "\n Array after initialization :\n" << integers3 << endl;
   //use overloaded assignment(=) operator
   cout << "Assigning integers2 to integers1:"  ;
   integers1 = integers2;
   cout << "integers1:\n" << integers1 ;
   cout << "integers2:\n" << endl;
   //use overloaded equality (==) operator
   cout << "Evaluating : integers1 == integers2 \n";
   if(integers1 == integers2)
     cout << "They are equal.\n";
   //use overloaded subscript operator to create rvalue
   cout << "integers1[5] is :" << integers1[5] << "\n";
   //use overloaded subscript operator to create lvalue
   cout << "Assigning 1000 to integers1[5] \n";
   integers1[5] = 100;
   cout << "intgers1:\n" << integers1 << "\n";
   //attempt to use out of range subscript
   cout << "Attempt to assign 1000 to integers1[15]" << endl;
   integers1[15] = 1000; //Error out of range
   getch();
   return 0;
}



