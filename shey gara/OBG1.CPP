#include<iostream.h>
#include<conio.h>
class 	pieceoffabric {
	public:
		void readsqmeter();
		float tosqyards();
		void displayfabric();
	private:
		float sqmeter;
	};
	void pieceoffabric::readsqmeter()
	{
		cout<<"Enter size in square meters: ";
		cin>>sqmeter;
	}
	float pieceoffabric::tosqyards()
	{
		return 1.196 * sqmeter;
	}
	void pieceoffabric::displayfabric()
	{
		cout<<sqmeter<<" square meters is "<<tosqyards()<<" squareyards";
	}
	void main()
	{
		clrscr();
		pieceoffabric fabric;
		fabric.readsqmeter();
		fabric.displayfabric();
		getch();
	}
