#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include<Windows.h>

using namespace std;

struct Proccess
{
	int id;
	int RandomEnter;//takhsise raghame vorude tasadofi
	int RandomServiceTime;
	int BetweenTime;
	int arrival;//zamane vorud
	int burst;//zamane servis
	int start;//zamanse shoru be servis gereftan
	int wait;//zamane entezar
	int finish;//zaman etmame servis
	int turnaround;
	bool serviced;
	bool InQueue;
}process[100];

int n;//tedade kole proccessha

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

};

void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}

void GetData()
{
	srand(time(NULL));
	n = 1+(rand()%10);//tolide tedade processha beyne 1 ta 10
	

	for(int i = 1; i <= n; i++)// dar in halghe etelate zamane vorud va zamane servis moshkhas mishavad
	{
		process[i].id = i;
		process[i].RandomEnter=1+(rand()%100);
		process[i].RandomServiceTime=1+(rand()%100);
		process[i].arrival=1+(rand()%100);
		process[i].burst=1+(rand()%10);
	}	

	Proccess temp;

	for(int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
			if(process[i].arrival>process[j].arrival)
			{
				temp=process[i];
				process[i]=process[j];
				process[j]=temp;
			}
	}
	for (int i=2;i<=n;i++)
	{
		process[i].BetweenTime=process[i].arrival-process[i-1].arrival;
	}
}

//FCFS Algorithm
void fcfs()
{
	int time=0,index;
	Queue queue;//eijade shey az kelase saff
	bool server=true;

	while (time<1000)//shabih sazi baraye 1000 sanie
	{
		
		for (int i=0;i<n;i++)// be tedade kole proccessa ejra mishe
		{
			if (process[i].arrival==time && i==0)//vorude avalin proccess baraye sevis greftan
			{
				process[i].serviced=true;
				process[i].start=time;
				server=false;//server busy
			}
			if (process[i].arrival==time && process[i].InQueue==false && process[i].serviced==false && server==true)
			{
				process[i].serviced=true;
				process[i].start=time;
				server=false;
			}
			if (process[i].arrival<=time && process[i].serviced==false && process[i].InQueue==false)
			{//agar zamane vorude yek proccess shoru shode bashad ama proccesi dar hale ejra ast ke varede saf mishavad
				queue.Add(i);
				process[i].InQueue=true;
			}
			if (process[i].arrival<=time && process[i].serviced==false)
			{//proccesshi ke dar saf ast dar har sanie zamane entezarash yeki ezafe mishavad
				process[i].wait++;
			}
			if ((process[i].arrival+process[i].burst+process[i].wait)==time && process[i].serviced==true)
			{//zamani ke yek proccess zamane servisash be etmam reside va bayad ye proccess az saf kharej shavad va servis begirad
				server=true;
				process[i].finish=time;
				if (queue.IsEmpty()==false)
				{
					index=queue.Delete();	
					process[index].start=time;
					process[index].serviced=true;
					process[index].InQueue=false;
					server=false;
				}
			}
		}
		time++;//ezafe shodane time dar har dor az charkheshe halghe while
	}

	       cout<<"\n\n\t\t\t---First come first serve ---";
 
	cout<<"\n Process  Arrival Between Burst  Starting  Waiting  Finishing turnaround  \n";
	printf("%5s %9s %7s %7s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time", "time","time");
 
	float tt=0,wtt=0;
	for(int i = 1; i <= n; i++)
	{
 
		process[i].turnaround = process[i].wait + process[i].burst;
	
 
		printf("%5d %7d %8d %7d %7d %8d %10d %9d %10 ", process[i].id, process[i].arrival,process[i].BetweenTime,
						  process[i].burst, process[i].start,
						  process[i].wait, process[i].finish,
						  process[i].turnaround);
 
		cout<<"\n\n";
	//	wtt+=process[i].ratio;
		tt+=process[i].turnaround;
	}
 //cout<<"\nAverage Wating time: "<<wtt/n;
 cout<<"\nAverage Turnaround time: "<<tt/n;
}


int no;//

void HRRN()
{
	int i, j, time = 0,index;//time zamane kolie shabih sazi ast
	struct Proccess temp;
	int chkprocess(int);// tarife 2 tabe
	int nextprocess(int);//     "	"
	
	for (i=1;i<=n;i++)
	{
		
		process[i].id=i;
		process[i].finish=process[i].start=process[i].turnaround=process[i].wait=0;
	}
		 
	no = 0;//tedad proccess haei ke servis gerefte and ke dar avale kar bayad 0 bashad
	j = 1;
 
 bool server=true;
    process[1].start = process[1].arrival;


	while(time<1000)//ta zamani ke hame proccess ha be etmam nareside and ejra mishavad..mitavan bejaye in hakghe zamane 1000 sanie ra moshakhas kard
	{
		for (int i=1;i<=n;i++)// be tedade kole proccessa ejra mishe
		{
			if (process[i].arrival==time && server==true)//vorude avalin proccess baraye sevis greftan
			{
				process[i].serviced=true;
				process[i].start=time;
				server=false;//server busy
			}
			if (process[i].arrival==time && process[i].serviced==false && server==false)
			{
				//raftan be safe entezar
			}
			if (process[i].arrival<=time && process[i].serviced==false)
			{//proccesshi ke dar saf ast dar har sanie zamane entezarash yeki ezafe mishavad
				process[i].wait++;
			}
			if ((process[i].arrival+process[i].burst+process[i].wait)==time && process[i].serviced==true)
			{//zamani ke yek proccess zamane servisash be etmam reside va bayad ye proccess az saf kharej shavad va servis begirad
				server=true;
				process[i].finish=time;
				if (nextprocess(time)!=-1)
				{
					index=nextprocess(time);
					process[index].start=time;
					process[index].serviced=true;
					server=false;
				}
			}
		}
		time++;//ezafe shodane time dar har dor az charkheshe halghe while
	}
	//process[j].finish = time;
 
 
 
        cout<<"\n\n\t\t\t---HIGHEST RESPONSE RATIO NEXT ---";
 
	cout<<"\n Process  Arrival Between Burst  Starting  Waiting  Finishing turnaround  \n";
	printf("%5s %9s %7s %7s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time", "time","time");
 
	float tt=0,wtt=0;
	for(i = 1; i <= n; i++)
	{
 
		process[i].turnaround = process[i].wait + process[i].burst;
	
 
		printf("%5d %7d %8d %7d %7d %8d %10d %9d %10 ", process[i].id, process[i].arrival,process[i].BetweenTime,
						  process[i].burst, process[i].start,
						  process[i].wait, process[i].finish,
						  process[i].turnaround);
 
		cout<<"\n\n";
	//	wtt+=process[i].ratio;
		tt+=process[i].turnaround;
	}
 //cout<<"\nAverage Wating time: "<<wtt/n;
 cout<<"\nAverage Turnaround time: "<<tt/n;
 
}
 
int nextprocess(int time)// mohase HRRN baraye process haei ke dar safe entezar hastand va bistarin anhaa entekhab mishavad
{
	int  l=-1, i;
	float min,r;
	min = 0;//baraye bishtarin HRRn , var l baraye andis proccess dar saff
	for(i = 1; i <= n; i++)
	{
		if( process[i].serviced==false && process[i].arrival<time)
		{
 			r=(float)((process[i].wait+process[i].burst)/process[i].burst);
			if(r>min)
 			{
			  min = r;
			  l = i;
			}
		}
	}
	return l;//dar enteha index proccess entekhab shode return mishavad.
}

void main()
{
	GetData();
	fcfs();
	HRRN();
	getch();
}