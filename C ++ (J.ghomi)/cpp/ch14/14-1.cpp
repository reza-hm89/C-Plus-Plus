#include <iostream.h>
//using namespace std;
class divexcp {
   public:
      divexcp() : message("Attempt to ddivide by zero") {}
      const char *what() const { return message; }
   private:
      const char *message;
};
//*****************
double quote(int numerator, int denum)
{
  if(denum == 0)
      throw divexcp();
  return (double) (numerator) / denum;
}
//************
int main()
{
   int num1, num2;
   double result;
   cout << "Enter two integers:";
   while(cin >> num1 >> num2) {
       try {
	 result = quote(num1, num2);
	 cout << "The quotient is: "  << result << endl;
       }
       catch (divexcp ex) {
	  cout << "Exception occured :" << ex.what() << "\n";
       }
       cout << "\nEnter two integers:";
   }
   cout << endl;
   return 0;
}


