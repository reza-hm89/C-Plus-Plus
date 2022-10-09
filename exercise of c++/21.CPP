# include<iostream.h>
# include<conio.h>
void hanoi(int n,int from,int dest,int help)
{
if(n==1)
	cout<<'\n'<<n<<" : "<<from<<" -----> "<<dest<<'\n';
else
	{
	hanoi(n-1,from,help,dest);
	cout<<'\n'<<n<<" : "<<from<<" -----> "<<dest<<'\n';
	hanoi(n-1,help,dest,from);
	}//Esle
}//Hanoi
void main()
{
int m;
clrscr();
cout<<"Please Enter Number Of Your Rings : ";
cin>>m;
hanoi(m,1,3,2);
getch();
}//Main
