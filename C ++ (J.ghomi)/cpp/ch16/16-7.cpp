#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std; 
class reciprocal: unary_function<double, double> {
   public:
	   result_type operator() (argument_type i)
	   {
	     return (result_type) 2.0 * i ;  //return reciprocal
	   }
};
//*****************
int main()
{
	list<double> vals;
	int i;
	for(i = 0; i < 10; i ++)
		vals.push_back((double) i);
	cout << "Original contents: \n";
	list<double>::iterator p = vals.begin();
	while(p != vals.end()) {
		cout << *p << "  ";
		p ++;
	}
	cout << endl;
	//use reciprocal function object

	p = transform(vals.begin(), vals.end(), vals.begin(),reciprocal());
    cout << "Transformed contents of vals:\n";
	p = vals.begin();

	while(p != vals.end()) {
		cout << *p << "  ";
		p ++;
	}
	cout << endl;
    return 0;
}
   