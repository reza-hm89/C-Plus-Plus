#include<iostream.h>
#include<conio.h>
int areacube(int length,int width=25,int height=1);
void main()
{
	int area,length=100,width=50,height=2;
	clrscr();
	area=areacube(length,width,height);
	cout<<"First time area equals: "<<area<<endl;
	area=areacube(length,width);
	cout<<"Second time area equals: "<<area<<endl;
	area=areacube(length);
	cout<<"Third time area equals: "<<area;
	getch();
}
int areacube(int length,int width,int height)
{
	return(length*width*height);
}

