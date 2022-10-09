#include <iostream.h>
#include <conio.h>
class memStates {
     private :
	    unsigned bytesAlloc;
	    unsigned bytesDel;
	    unsigned callsToNewArray;
	    unsigned callsToDelArray;
     public:
	    memStates()
	    {
	       bytesAlloc = 0;
	       bytesDel = 0;
	       callsToNewArray = 0;
	       callsToDelArray = 0;
	    }
	    void newArrayCalled(size_t size)
       {
	       callsToNewArray ++;
	       bytesAlloc += size;
	    }
	    void delArrayCalled(size_t size)
	    {
	       callsToDelArray ++;
	       bytesDel += size;
       }
   ~memStates()
	{
	   cout << "Memory allocation statistics : "  << endl
		<< "bytes allocated  : " << bytesAlloc << endl
		<< "bytes deleted    : " << bytesDel   << endl
		<< "calls to new[]   : " << callsToNewArray   << endl
		<< "calls to delete[]: " << callsToDelArray   << endl ;
	}
}; //end of class memstats
memStates states;
//***************
class sample_data {
    int x;
  public:
    sample_data (int a) { x = a;}
    sample_data() {x = 0; }
    void *operator  new[](size_t size)
    {
       states.newArrayCalled(size);
       return (void *) :: new char[size]; //allocate specified
		     //number of bytes with the actual new operator
    }
    //****************
    void operator delete[](void *mem, size_t size)
    {
      states.delArrayCalled(size);
      ::delete[] mem;
    }
    void show()
    {
       cout << x << ",  " << endl;
    }
};
//*****************
int main()
{
   int i, s = 0;
   clrscr();
   const arraySize = 5;
   sample_data a(50);
   //declare an array
   sample_data *dataArray = new sample_data[arraySize];
   //declare an array of pointers
   sample_data *pdArray[arraySize];
   //initialize the array
   for(i = 0; i < arraySize; i ++)
       pdArray[i] = new sample_data(i);
   //now work with the data some
   dataArray[0] = a;
   delete[] dataArray;
   for(i = 1; i < arraySize; i ++)
      delete pdArray[i];
   cout << " s = " << s << endl;
   getch();
   return 0;
}



