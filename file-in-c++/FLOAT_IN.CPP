#include<iostream.h>
#include<conio.h>
void main() {
	clrscr();
	double n,fn;
	double intn,f,in;
	cin>>n;
	intn=(int)n;
	fn=n-intn;
	//cout<<intn<<"\t"<<fn;
	while(intn>=1)
		intn/=10;
	cout<<intn;
	while (f) {
		fn*=10;
		in=(int)fn;
		f=fn-in;
		//in=(float)in;
		 }
	cout<<endl<<fn+intn;
	getch();
}