#include <iostream.h>const int DefaultSize = 10;
// define the exception classes
class xBoundary {};
class xSize
{
   public:
     xSize(int size):itsSize(size) {}
     ~xSize(){}
     virtual int GetSize() { return itsSize; }
     virtual void PrintError()
     {
        cout << "Size error. Received: " << itsSize << endl;
     }
   protected:
     int itsSize;
};
class xTooBig : public xSize
{
   public:
      xTooBig(int size):xSize(size){}
      virtual void PrintError()
      {
          cout << "Too big! Received: ";
          cout << xSize::itsSize << endl;
      }
};
//*****************
class xTooSmall : public xSize
{
    public:
       xTooSmall(int size):xSize(size){}
        virtual void PrintError()
        {
            cout << "Too small! Received: ";
            cout << xSize::itsSize << endl;
        }
};
//*****************
class xZero  : public xTooSmall{
   public:
     xZero(int size):xTooSmall(size){}
     virtual void PrintError()
     {
        cout << "Zero!!. Received: ";
        cout << xSize::itsSize << endl;
     }
};
class xNegative : public xSize
{
    public:
      xNegative(int size):xSize(size){}
      virtual void PrintError()
      {
          cout << "Negative! Received: ";
          cout << xSize::itsSize << endl;
      }
};
//*******************
class Array
{
   public:
        // constructors
        Array(int itsSize = DefaultSize);
        Array(const Array &rhs);
        ~Array() { delete [] pType;}
        // operators
        Array& operator=(const Array&);
        int& operator[](int offSet);
        const int& operator[](int offSet) const;
        // accessors
        int GetitsSize() const { return itsSize; }
        // friend function
        friend ostream& operator<< (ostream&, const Array&);
      private:
        int *pType;
        int  itsSize;
};
//***************
Array::Array(int size):itsSize(size)
{
    if (size == 0)
    throw xZero(size);
    if (size < 0)
       throw xNegative(size);
    if (size < 10)
       throw xTooSmall(size);
    if (size > 30000)
       throw xTooBig(size);
    pType = new int[size];
    for (int i = 0; i<size; i++)
       pType[i] = 0;
}
int& Array::operator[] (int offset)
{
//  int size = GetitsSize();
  if (offset >= 0 && offset < GetitsSize())
     return pType[offset];
  throw xBoundary();
  return pType[offset];
}
const int& Array::operator[] (int offset) const
{
    if (offset >= 0 && offset < GetitsSize())
        return pType[offset];
    throw xBoundary();
    return pType[offset];

}int main()
{
   try
   {
     int choice;
     cout << "Enter the array size: ";
     cin >> choice;
     Array intArray(choice);
     for (int j = 0; j< 100; j++)
     {
       intArray[j] = j;
       cout << "intArray[" << j << "] okay..." << endl;
     }
   }
   catch (xBoundary)
   {
      cout << "Unable to process your input!\n";
   }
   catch (xSize& theException)
   {
     theException.PrintError();
   }
   catch (...)
   {
     cout << "Something went wrong, but I've no idea what!" << endl;
   }
   cout << "Done.\n";
   return 0;
}

