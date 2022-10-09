#include <iostream.h>
#include <conio.h>
class memStates {
     private :
	    unsigned bytesAlloc;
	    unsigned bytesDel;
	    unsigned callsNew;
	    unsigned callsDel;
     public:
	memStates()
	{
	       bytesAlloc = 0;
	       bytesDel = 0;
	       callsNew = 0;
	       callsDel = 0;
	}
	void newCalled(size_t size)
	{
	   callsNew ++;
	   bytesAlloc += size;
	}
	void delCalled(size_t size)
	{
	   callsDel ++;
	   bytesDel += size;
	}
       ~memStates()
	{
	   cout << "memory allocation statistics : "  << endl
		<< "bytes allocated : " << bytesAlloc << endl
		<< "bytes deleted   : " << bytesDel   << endl
		<< "calls to new    : " << callsNew   << endl
		<< "calls to delete : " << callsDel   << endl ;
	}
}; //end of class memstats
memStates states;
//***************
class sample_data {
    int x;
    int y;
  public:
    sample_data (int a, int b) { x = a; y = b;}
    void *operator  new(size_t size)
    {
       states.newCalled(size);
       return (void *) :: new char[size]; //allocate specified
		     //number of bytes with the actual new operator
    }
    //****************
    void operator delete(void *mem, size_t size)
    {
     states.delCalled(size);
     ::delete[] mem;
    }
    void show() {
       cout << x << ",  " << y << endl;
    }
};
//*****************
int main()
{
   clrscr();
   float *f;
   sample_data *p = new sample_data(10, 20);
   sample_data *q = new sample_data(30, 40);
   f = new float;
   *f = 10.10;
   cout << "p -> x, p -> y = " ;
   p -> show();
   cout << "q -> x, q -> y = " ;
   q -> show();
   cout << "*f = " << *f << endl;
   delete p;
   delete q;
   delete f;
   getch();
   return 0;
}



