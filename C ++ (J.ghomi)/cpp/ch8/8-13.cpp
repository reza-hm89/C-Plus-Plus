#include <iostream.h>
#include <conio.h>
class phoneNumber {
    friend ostream &operator<<(ostream&, const phoneNumber &);
    friend istream &operator>>(istream&, phoneNumber &);
  private:
    char areaCode[4]; // 3-digit area code and null
    char exchange[4];  //3-digit exchane and null
    char line[5];     // 4-digit line and null
};
//**************
ostream &operator<<(ostream &output, const phoneNumber &num)
{
  output << "(" << num.areaCode << ") "
	 << num.exchange << "-" << num.line;
  return output;   //enable cout << a << b << c
}
//************
istream &operator>>(istream &input, phoneNumber &num)
{
  input >> num.areaCode;   //input areacode
  input >> num.exchange;   //input exchange
  input >> num.line;       //input line
  return input;                       //enable cin >> a >> b >> c
}
//***************
int main()
{
  clrscr();
  phoneNumber phone;   //create object phone
  cout << "Enter phoneNumber :";
  cin >> phone;
  cout << "The phone number entered was : " << phone << endl;
  getch();
  return 0;
}


