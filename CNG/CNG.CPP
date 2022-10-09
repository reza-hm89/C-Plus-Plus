#include <iostream.h>
#include <conio.h>
#include <dos.h>

class Car
{
	int distance;//unit of metter
	float liter;
	unsigned int locX,locY;//lcation (x,y)

	public:
		Car(int x,int y)
		{
			locX=x;
			locY=y;
			distance=0;
		}

		void Set_Liter(float l)
		{
			liter=l;
		}

		float Get_Liter()
		{
			return liter;
		}

		void Set_Distance()
		{
			distance++;
			if (distance%100==0)
				liter--;
		}

		int Get_Distance()
		{
			return distance;
		}

		void Set_Location(int x,int y)
		{
			locX=x;
			locY=y;
		}

		unsigned int Get_locX()
		{
			return locX;
		}

		unsigned int Get_locY()
		{
			return locY;
		}
};

class Motorcycle
{
	int distance;//unit of metter
	float liter;
	unsigned int locX,locY;//location (x,y)

	public:
		Motorcycle(int x,int y)
		{
			locX=x;
			locY=y;
			distance=0;
		}

		void Set_Location(int x,int y)
		{
			locX=x;
			locY=y;
		}

		unsigned int Get_locX()
		{
			return locX;
		}

		unsigned int Get_locY()
		{
			return locY;
		}

		void Set_Liter(float l)
		{
			liter=l;
		}

		float Get_Liter()
		{
			return liter;
		}

		void Set_Distance()
		{
			distance++;
			if (distance%100==0)
				liter-=0.5;
		}

		int Get_Distance()
		{
			return distance;
		}
};

class Traffic_Light
{
	int status;
	int locX,locY;//location (x,y)

	public:

		Traffic_Light(int x,int y)
		{
			status=-1;
			locX=x;
			locY=y;
		}

		int Get_locX()
		{
			return locX;
		}

		int Get_locY()
		{
			return locY;
		}

		int Check()
		{
			status=(status+1)%3;

			if (status==0)// light is green
				return 0;
			else if (status==1)// light is yellow
				return 1;
			else if (status==2)// light is red
				return 2;
			return -1;
		}
};

class CNG
{
	float maxliter;//maximum liter of CNG
	int locX,locY;//location (x,y)

	public:
		CNG(int x,int y,float l)
		{
			maxliter=l;
			locX=x;
			locY=y;
		}

		int Get_locX()
		{
			return locX;
		}

		int Get_locY()
		{
			return locY;
		}

		float Get_Liter(int l)
		{
			if (maxliter+l>0)
			{
				maxliter-=l;
				return maxliter;
			}

			cout<<"station is empty of liter!";
			getch();
			return -1;
		}
};

void main()
{
	clrscr();

	char ch;
	unsigned int  x1=30,y1=5,x2=5,y2=15;
	int cur; //cur==1 car   cur==2 motor

	CNG c1(10,10,100);//location(10,10) liter=100
	Traffic_Light t1(20,20);//location (20,20)
	Car car1(x1,y1);//location (30,5)
	Motorcycle m1(x2,y2);//location (5,15)
	car1.Set_Liter(10);
	m1.Set_Liter(5);

	cout<<"car1:\nLiter: \nDistance: \nLocation: \n\n";
	cout<<"motor1:\nLiter: \nDistance: \nLocation: \n";
	gotoxy(1,24);
	cout<<"traffic Light location: ("<<t1.Get_locX()<<","<<t1.Get_locY()<<")";
	gotoxy(1,25);
	cout<<"Enter '1' for Car and '2' for Motor";

	cur=2;

	while (ch!=27)
	{
		if ((ch=getch())==0)
			ch=getch();

		if (ch==72)
		{
			if (cur==1)
			{
				x1--;
			}
			else if (cur==2)
			{
				x2--;
			}
		}
		else if (ch==80)
		{
			 if (cur==1)
			{
				x1++;
			}
			else if (cur==2)
			{
				x2++;
			}
		}
		else if (ch==75)
		{
			 if (cur==1)
			{
				y1--;
			}
			else if (cur==2)
			{
				y2--;
			}
		}
		else if (ch==77)
		{
			 if (cur==1)
			{
				y1++;
			}
			else if (cur==2)
			{
				y2++;
			}
		}
		else if (ch=='1')
		{
			cur=1;
		}
		else if (ch=='2')
		{
			cur=2;
		}

		gotoxy(8,2);
		cout<<"     ";
		gotoxy(8,2);
		cout<<car1.Get_Liter();
		gotoxy(11,3);
		cout<<car1.Get_Distance();
		gotoxy(11,4);
		cout<<"              ";
		gotoxy(11,4);
		cout<<"("<<car1.Get_locX()<<","<<car1.Get_locY()<<")";

		gotoxy(8,7);
		cout<<"     ";
		gotoxy(8,7);
		cout<<m1.Get_Liter();
		gotoxy(11,8);
		cout<<m1.Get_Distance();
		gotoxy(11,9);
		cout<<"                ";
		gotoxy(11,9);
		cout<<"("<<m1.Get_locX()<<","<<m1.Get_locY()<<")";

		if (cur==1)
		{
			car1.Set_Location(x1,y1);
			car1.Set_Distance();
			if (car1.Get_Liter()<=0)
			{
				gotoxy(20,10);
				cout<<"                                 ";
				gotoxy(20,10);
				cout<<"Liter of car is empty!...goto CNG";
				getch();
				gotoxy(20,10);
				cout<<"                                 ";

				car1.Set_Location(10,10);//goto cng
				car1.Set_Liter(10);
				c1.Get_Liter(10);
			}
			if (car1.Get_locX()==t1.Get_locX() && car1.Get_locY()==t1.Get_locY())
			{
				if (t1.Check()==2)
				{
					gotoxy(20,10);
					cout<<"                               ";
					gotoxy(20,10);
					cout<<"Light is RED...5 seconds wait!:";
					delay(5000);
					gotoxy(20,10);
					cout<<"                               ";

				}
			}
		}
		else if (cur==2)
		{
			m1.Set_Location(x2,y2);
			m1.Set_Distance();
			if (m1.Get_Liter()<=0)
			{
				gotoxy(10,10);
				cout<<"Liter of motor is empty!...goto CNG";
				m1.Set_Location(10,10);
				m1.Set_Liter(5);
				c1.Get_Liter(5);
			}
			if (m1.Get_locX()==t1.Get_locX() && m1.Get_locY()==t1.Get_locY())
			{
				if (t1.Check()==2)
				{
					gotoxy(20,10);
					cout<<"                               ";
					gotoxy(20,10);
					cout<<"Light is RED...5 seconds wait!:";
					delay(5000);
					gotoxy(20,10);
					cout<<"                               ";

				}
			}
		}
	}

}