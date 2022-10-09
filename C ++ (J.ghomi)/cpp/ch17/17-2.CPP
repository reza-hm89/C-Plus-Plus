#include <iostream>
using namespace std; 
namespace cns {
	int up;
	int low;
	class counter {
		int count;
	  public:
		counter(int n) {
			if(n <= up ) 
				count = n;
			else
				count = up;
		}
		void reset(int n) {
			if(n <= up)
				count = n;
		}
		int run() {
			if(count > low)
				return count --;
			else
				return low;
		}

	};
}

//********************	  

int main()
{

	using cns::up;
	up = 100;
	cns::low = 0;
	cns::counter ob1(10);
	int i;
	do {
		i = ob1.run();
		cout << i << "  ";
	} while(i > cns::low);
    cout << endl; 
	using namespace cns;
	counter ob2(20);
	do {
		i = ob2.run();
		cout << i << "  ";
	} while(i > low);
	cout << endl;
	ob2.reset(100);
	low = 90;
	do {
		i = ob2.run();
		cout << i << "  ";
	} while (i > low);
    cout << endl; 
	return 0;
}






		

