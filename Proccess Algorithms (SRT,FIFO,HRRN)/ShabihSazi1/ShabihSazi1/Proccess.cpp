#include <iostream>
#include <conio.h>
#include<time.h>
#include<Windows.h>

using namespace std;

struct Proccess
{
	int RandomEnter;//takhsise raghame vorude tasadofi
	int BetweenTime;//zamane beyne 2 vorud
	int EnterTime;//zamane vorud
	int RandomServiceTime;//zamane khedmatdehi be surate tasadofi;
	int ServiceTime;//zamane servis
	int StartTime;//zamane shoru be kar
	int FinishTime;//zamane payane kar
	int WaitTime;//zamane entezar
	float Probability;//ehtemal
	float Cumulative_Probability;//ehtemale tajamoei
	bool Serviced;//servise gerfte ya na
	bool InQueue;//dar saff entezar has ya na
}p[100];

class Queue
{//piyade sazi saff baraye zakhire sazie proccessa
	
public:	
	int front,rear;
	int q[100];

	Queue()
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
	bool IsEmpty()
	{
		if (front==rear)
			return true;
		else
			return false;
	}
	void Shift(int k)
	{//baraye sjf ke bayad proccess ke kamtarin zamane serviso dare hazf beshe az saf ke ba shift dadan in kar anjam mishe
		for (int i=k;i<rear;i++)
			q[i]=q[i+1];
		rear--;
	}

};
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}
void main()
{
	int n;
	int randNumber;
	Proccess temp;

	srand(time(NULL));
	randNumber = 1+(rand()%10);//tolide tedade processha beyne 1 ta 10
	n=randNumber;
	cout<<"Number of proccess: "<<n;
		
	for (int i=0;i<n;i++)//daryafte etelaate proccessha
	{
		p[i].RandomEnter=1+(rand()%100);
		p[i].RandomServiceTime=1+(rand()%100);
		p[i].EnterTime=1+(rand()%100);
		p[i].ServiceTime=1+(rand()%10);
	}

	for(int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
			if(p[i].EnterTime>p[j].EnterTime)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
	}

	p[0].BetweenTime=0;
	for (int i=1;i<n;i++)
	{
		p[i].BetweenTime=p[i].EnterTime-p[i-1].EnterTime;
	}
	// FIFO Algorithm
	int time=0,index;
	Queue queue;//eijade shey az kelase saff
	bool server=true;

	while (time<1000)//shabih sazi baraye 1000 sanie
	{
		
		for (int i=0;i<n;i++)// be tedade kole proccessa ejra mishe
		{
			if (p[i].EnterTime==time && i==0)//vorude avalin proccess baraye sevis greftan
			{
				p[i].Serviced=true;
				p[i].StartTime=time;
				server=false;//server busy
			}
			if (p[i].EnterTime==time && p[i].InQueue==false && p[i].Serviced==false && server==true)
			{
				p[i].Serviced=true;
				p[i].StartTime=time;
				server=false;
			}
			if (p[i].EnterTime<=time && p[i].Serviced==false && p[i].InQueue==false)
			{//agar zamane vorude yek proccess shoru shode bashad ama proccesi dar hale ejra ast ke varede saf mishavad
				queue.Add(i);
				p[i].InQueue=true;
			}
			if (p[i].EnterTime<=time && p[i].Serviced==false)
			{//proccesshi ke dar saf ast dar har sanie zamane entezarash yeki ezafe mishavad
				p[i].WaitTime++;
			}
			if ((p[i].EnterTime+p[i].ServiceTime+p[i].WaitTime)==time && p[i].Serviced==true)
			{//zamani ke yek proccess zamane servisash be etmam reside va bayad ye proccess az saf kharej shavad va servis begirad
				server=true;
				p[i].FinishTime=time;
				if (queue.IsEmpty()==false)
				{
					index=queue.Delete();	
					p[index].StartTime=time;
					p[index].Serviced=true;
					p[index].InQueue=false;
					server=false;
				}
			}
		}
		time++;//ezafe shodane time dar har dor az charkheshe halghe while
	}
	//badaz etmame tamame proccess ha
	system("cls");
	cout<<"*** FIFO Algorithm ***\n\n";
	float Avetime=0,WaitTime=0;
	cout<<"Rand Enter-Between-Enter T-Rand service-Start T-Service T-Finish T-Wait T";
	cout<<"\n";
	for (int i=1;i<80;i++)
			cout<<"-";
	for (int i=0;i<n;i++)
	{//mohasebe miyangine zamane entezar va zamane etmam
		gotoxy(1,i+7);
		cout<<p[i].RandomEnter;
		gotoxy(11,i+7);
		cout<<p[i].BetweenTime;
		gotoxy(19,i+7);
		cout<<p[i].EnterTime;
		gotoxy(27,i+7);
		cout<<p[i].RandomServiceTime;
		gotoxy(40,i+7);
		cout<<p[i].StartTime;
		gotoxy(48,i+7);
		cout<<p[i].ServiceTime;
		gotoxy(58,i+7);
		cout<<p[i].FinishTime;
		gotoxy(67,i+7);
		cout<<p[i].WaitTime;
		Avetime+= (p[i].ServiceTime+p[i].WaitTime);
		WaitTime+= p[i].WaitTime;
	}
	cout<<"\n\nAerage total time: "<<Avetime/n;
	cout<<"\nAverage Wating time: "<<WaitTime/n;
	getch();
	//------- SJF algorithm -------

	int time1=0,min=0,indexQ;
	Queue queue1;
	for (int i=0;i<n;i++)
	{//baraye sjf bayad parametr haye zir 0 shavand
		p[i].WaitTime=0;
		p[i].StartTime=0;
		p[i].FinishTime=0;
		p[i].Serviced=false;
		p[i].InQueue=false;
	}
	server=true;
	//moshabe balaei ba kami taghirat
	while (time1<1000)
	{
		
		for (int i=0;i<n;i++)
		{
			if (p[i].EnterTime==time1 && i==0)
			{
				p[i].Serviced=true;
				p[i].StartTime=time1;
				server=false;
			}
			if (p[i].EnterTime==time1 && p[i].InQueue==false && p[i].Serviced==false && server==true)
			{
				p[i].Serviced=true;
				p[i].StartTime=time1;
				server=false;
			}
			if (p[i].EnterTime<=time1 && p[i].Serviced==false && p[i].InQueue==false)
			{
				queue1.Add(i);
				p[i].InQueue=true;
			}
			if (p[i].EnterTime<time1 && p[i].Serviced==false)
			{
				p[i].WaitTime++;
			}
		}
		for (int i=0;i<n;i++)
		{
			if ((p[i].EnterTime+p[i].ServiceTime+p[i].WaitTime)==time1 && p[i].Serviced==true)
			{//zamani ke servise yek proccess tamam mishavad bayad kutah tarin proccess entekhab shavad
				p[i].FinishTime=time1;
				server=true;
				if (queue1.IsEmpty()==false)
				{
				min=queue1.q[queue1.front+1];//ebtedaye saf dar min gharar migirad
				indexQ=queue1.front+1;
				for (int j=queue1.front+1;j<=queue1.rear;j++)//az ebteda ta entehaye saff
				{
					if (p[min].ServiceTime>p[queue1.q[j]].ServiceTime)//proccess ba kamtarin zamane servis peyda mishavad
					{
						min=queue1.q[j];
						indexQ=j;
					}
				}
				// proccess peyda shode bayad amade servis gereftan shavad
				queue1.Shift(indexQ);
				index=min;
				p[index].StartTime=time1;
				p[index].Serviced=true;
				p[index].InQueue=false;
				server=false;
				}
			}
		}
		time1++;
	}
	Avetime=0,WaitTime=0;
	cout<<"\n\n *** SJF Algorithm ***\n\n";
	cout<<"Rand Enter-Between-Enter T-Rand service-Start T-Service T-Finish T-Wait T";
	cout<<"\n";
	for (int i=1;i<80;i++)
			cout<<"-";
	for (int i=0;i<n;i++)
	{//mohasebe miyangine zamane entezar va zamane etmam
		gotoxy(1,i+25);
		cout<<p[i].RandomEnter;
		gotoxy(11,i+25);
		cout<<p[i].BetweenTime;
		gotoxy(19,i+25);
		cout<<p[i].EnterTime;
		gotoxy(27,i+25);
		cout<<p[i].RandomServiceTime;
		gotoxy(40,i+25);
		cout<<p[i].StartTime;
		gotoxy(48,i+25);
		cout<<p[i].ServiceTime;
		gotoxy(58,i+25);
		cout<<p[i].FinishTime;
		gotoxy(67,i+25);
		cout<<p[i].WaitTime;
		Avetime+= (p[i].ServiceTime+p[i].WaitTime);
		WaitTime+= p[i].WaitTime;
	}
	
	cout<<"\nAerage total time: "<<Avetime/n;
	cout<<"\nAverage Wating time: "<<WaitTime/n;
	getch();
}
