#include<iostream.h>
#include<conio.h>
#include<fstream.h>
int main(int argc,char *argv[])
{
	if (argc<2) {
		cout<<"Usage : program<filename>\n";
		getch();
		return 1;
	}
	ifstream in(argv[1]);
	char str[255];
	in.getline(str,255);
	while(!in.eof()) {
		cout<<str<<endl;
		in.getline(str,255);
	}
	in.close();
	getch();
	return 0;
}