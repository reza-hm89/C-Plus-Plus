#include <iostream>
#include <conio.h>
#include <queue>
//==================================================
using namespace std;
//==================================================
struct Event
{
	int Consumer_ID;
	char events[30];
	int time;
}t[100];

int k=0;
//==================================================
class Consumer
{
	int ServiceTime,WaitTime,EnterTime;
	
public:

	bool Serviced;

	Consumer()
	{
		ServiceTime=WaitTime=EnterTime=0;
		Serviced=false;
	}

	int Get_ServiceTime()
	{
		return ServiceTime;
	}

	void Set_ServiceTime(int time)
	{
		ServiceTime=time;
	}

	int Get_WaitTime()
	{
		return WaitTime;
	}

	void Set_WaitTime()
	{
		WaitTime++;
	}

	int Get_EnterTime()
	{
		return EnterTime;
	}

	void Set_EnterTime(int time)
	{
		EnterTime=time;
	}

};
//==================================================

class Stylist
{
	bool Busy;
	int NumOfConsumer;
	int GetStart,BusyTime,TotalBusyTime;
	int FreeTime;
	

public:
	Stylist()
	{
		Busy=false;
		BusyTime=TotalBusyTime=FreeTime=NumOfConsumer=0;
	}

	inline bool Get_CheckStatus()
	{
		return Busy;
	}
	inline void Set_CheckStatus(bool sw)
	{
		Busy=sw;
	}
	inline void Set_Start(int t)
	{
		GetStart=t;
	}
	inline int Get_Start()
	{
		return GetStart;
	}
	inline void Set_NumberOfConsumer()
	{
		NumOfConsumer++;
	}
	inline int Get_NumberOfConsumer()
	{
		return NumOfConsumer;
	}
	inline void Set_BusyTime(int time)
	{
		BusyTime=time;
		TotalBusyTime+=BusyTime;
	}
	inline int Get_BusyTime()
	{
		return BusyTime;
	}
	inline void Set_FreeTime()
	{
		FreeTime++;
	}
	inline int Get_FreeTime()
	{
		return FreeTime;
	}
	inline int Get_TotalBusyTime()
	{
		return TotalBusyTime;
	}
};
//==================================================
class Chair
{
	int front,rear;
	int q[100];
	
public:	
	
	Chair()
	{
		front=rear=-1;
	}
	void Add (int index)
	{
		if (rear==99)
			return;
		q[++rear]=index;
	}
	int Delete ()
	{
		if (front==rear)
			return -1;
		return q[++front];
	}

};
//==================================================
int NumOfConsumer,NumOfStylist;
int SizeOfQueue;
int Time,OutOfService;
Chair chair;
Stylist *s;
Consumer *c;

//==================================================

void InputData()
{
	int t1,t2;

	system("cls");
	cout<<"Enter number of Stylists: ";
	cin>>NumOfStylist;

	cout<<"\nEnter number of Consumers: ";
	cin>>NumOfConsumer;

	cout<<"\nEnter Number of Chairs: ";
	cin>>SizeOfQueue;

	s=new Stylist [NumOfStylist];
	c=new Consumer [NumOfConsumer];	
	
	for (int i=0;i<NumOfConsumer;i++)
	{
		cout<<"\nInput EnterTime && ServiceTime for Consumer "<<i+1<<" : ";
		cin>>t1>>t2;
		c[i].Set_EnterTime(t1);
		c[i].Set_ServiceTime(t2);
		c[i].Serviced=false;
	}
};
//==================================================
void Simulation()
{
	bool check,sw=false;
	int cnt=0,temp,index;
	Time=0;
	while (1)
	{
		for (int i=0;i<NumOfConsumer;i++)
		{
			
			if (c[i].Get_EnterTime()==Time)
			{
				check=false;

				for (int j=0;j<NumOfStylist;j++)
				{
					
					if (s[j].Get_CheckStatus()==false && c[i].Serviced==false)
					{
						check=true;
						c[i].Serviced=true;
						s[j].Set_CheckStatus(true);
						s[j].Set_Start(Time);
						s[j].Set_NumberOfConsumer();
						s[j].Set_BusyTime(c[i].Get_ServiceTime());
						t[k].Consumer_ID=i;
						t[k].time=Time;
						strcpy(t[k].events,"Start to service");
						k++;
					}
				}

				if (check==false && Time>=c[i].Get_EnterTime())
				{
					chair.Add(i);
					cnt++;
					strcpy( t[k].events , "enter to queue");
					t[k].time = Time;
                    t[k++].Consumer_ID = i;
				}
			}
			
			if (Time>=c[i].Get_EnterTime() && c[i].Serviced==false)
			{
				c[i].Set_WaitTime();
			}
			

		}

		for (int i=0;i<NumOfStylist;i++)
		{
			if (Time == (s[i].Get_Start() + s[i].Get_BusyTime()))
                    {
						s[i].Set_CheckStatus(false);
                        if (cnt > 0)
                        {
							index = chair.Delete();
							c[index].Serviced = true;
							s[i].Set_CheckStatus(true);
							s[i].Set_Start(Time);
							s[i].Set_BusyTime(c[index].Get_ServiceTime());
							s[i].Set_NumberOfConsumer();
                            cnt--;
                            strcpy( t[k].events , "delete from queue");
							t[k].time = Time;
                            t[k++].Consumer_ID = index;
                        }

                    }
			if (s[i].Get_CheckStatus()==false)
			{
				s[i].Set_FreeTime();
			}
		}

		sw=false;
		for (int i=0;i<NumOfConsumer;i++)
		{
			if (c[i].Serviced==false)
					sw=true;
		}
		if (sw==false)
		{
			for (int j = 0; j < NumOfStylist; j++)
                    {
						if (s[j].Get_CheckStatus() == true)
                        {
                            sw = true;
                        }
                    }
		}
                if (sw == false)
                {
                    break;
                }

		Time++;

	}
}
//==================================================
void Output()
{
	float ave=0;
	cout<<"\nWait Time for Consumers:\n";
	for (int i=0;i<NumOfConsumer;i++)
	{
		cout<<"Consumer "<<i+1<<":"<<c[i].Get_WaitTime()<<"\n";
		ave+=c[i].Get_WaitTime();
	}

	cout<<"\n\nBusy Time for Stylists:\n";
	for (int i=0;i<NumOfStylist;i++)
	{
		cout<<"Stylist "<<i+1<<":"<<s[i].Get_TotalBusyTime()<<"\n";
	}

	cout<<"\n\nFree Time for Stylists:\n";
	for (int i=0;i<NumOfStylist;i++)
	{
		cout<<"Stylist "<<i+1<<":"<<s[i].Get_FreeTime()<<"\n";
	}
	cout<<"\n\nAverage Waiting: "<<ave/NumOfConsumer;
	cout<<"\n\nSimlulation Time: "<<Time;
	cout<<"\n\nEvents list:\n";
	cout<<"Time\tConsumer_ID\tEvent\n\n";
	for (int i=0;i<k;i++)
	{
		cout<<t[i].time<<"\t"<<t[i].Consumer_ID<<"\t"<<t[i].events<<"\n";
	}
}
//==================================================
void main()
{
	InputData();
	Simulation();
	Output();
	getch();
}