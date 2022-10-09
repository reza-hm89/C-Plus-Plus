#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//------------------------------------------------
struct Queue{
	int Num, Parent[3][3], Self[3][3], Heuristic, G;
};
//------------------------------------------------
int Puzzle [3][3], Cur_Num;
Queue Open[700], Close[700];
int Row,Col;
//------------------------------------------------
void Initial ();
void ShowPuzzle ();
void Play(void);
int Heuristic1 (int [3][3]);
int Heuristic2 (int [3][3]);
int FindPath (int,int,int);
void Copy_Arrays(int [3][3], int [3][3]);
int Compare_Arrays(int [3][3], int [3][3]);
void Set_Col_Row(int[3][3]);
int Search_Open(Queue [700],int [3][3]);
int Select_Min(void);
//------------------------------------------------
void main ()
{
	Initial();
	ShowPuzzle();
	Row = Col = 1;
	cout<<"\nG()+H()= "<<Heuristic1(Puzzle) + Heuristic2(Puzzle);
	Play();
	getch();
}
//------------------------------------------------
void Initial ()
{
	int i,j,k,rand,sw,temp;
	int Row=0,Col=0;
	Puzzle[0][0]=-1;Puzzle[0][1]=-1;Puzzle[0][2]=-1;
	Puzzle[1][0]=-1;Puzzle[1][1]=0 ;Puzzle[1][2]=-1;
	Puzzle[2][0]=-1;Puzzle[2][1]=-1;Puzzle[2][2]=-1;
	for(i = 0; i<700; i++){
		Open[i].Num = -1;
		Close[i].Num = -1;
	}
	randomize();
	for (k=0;k<9; )
	{
		rand=random(9);
		sw=0;
		for (i=0;i<3;i++)
			for (j=0;j<3;j++)
				if (rand==Puzzle[i][j])
					sw=1;
		if (sw==0)
		{
			Puzzle[Row][Col++]=rand;
			if (Col==3)
			{
				Row++;
				Col=0;
			}
			k++;
		}
	}
	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
			if (Puzzle[i][j]==0)
			{
				temp=Puzzle[i][j];
				Puzzle[i][j]=Puzzle[1][1];
				Puzzle[1][1]=temp;
				break;
			}
}
//------------------------------------------------
void ShowPuzzle ()
{
	clrscr();
	int i,j;
	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
		{
			cout<<Puzzle[i][j]<<"   ";
			if (j==2)
				cout<<"\n";
		}
}
//------------------------------------------------
int Heuristic1 (int arr[3][3])
{
	int cnt=0;
	if (arr[0][0]!=0)
		cnt++;
	if (arr[0][1]!=1)
		cnt++;
	if (arr[0][2]!=2)
		cnt++;
	if (arr[1][0]!=3)
		cnt++;
	if (arr[1][1]!=4)
		cnt++;
	if (arr[1][2]!=5)
		cnt++;
	if (arr[2][0]!=6)
		cnt++;
	if (arr[2][1]!=7)
		cnt++;
	if (arr[2][2]!=8)
		cnt++;
	return cnt;
}
//------------------------------------------------
int Heuristic2 (int arr[3][3])
{
	int i,j,sum=0;
	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
			sum+=FindPath(arr[i][j],i,j);
	return sum;
}
//------------------------------------------------
int FindPath (int x,int i,int j)
{
	switch (x)
	{
		case 0:
			return abs(i-0)+abs(j-0);
		case 1:
			return abs(i-0)+abs(j-1);
		case 2:
			return abs(i-0)+abs(j-2);
		case 3:
			return abs(i-1)+abs(j-0);
		case 4:
			return abs(i-1)+abs(j-1);
		case 5:
			return abs(i-1)+abs(j-2);
		case 6:
			return abs(i-2)+abs(j-0);
		case 7:
			return abs(i-2)+abs(j-1);
		case 8:
			return abs(i-2)+abs(j-2);
	}
	return 0;
}
//------------------------------------------------
void Play(){
	Queue Temp;
	Cur_Num = Close[0].Num = 0;
	Copy_Arrays(Puzzle, Close[0].Self);
	int i,j, Last_Close = 0, Last_Open = 0, Src_Op, Src_Cl;
	for(i = 0; i<3; i++)
		for(j = 0; j<3; j++)
			Close[0].Parent[i][j] = -1;
	Close[0].Heuristic = Heuristic2(Puzzle);
	Close[0].G = 0;
	// while g()!=0
	while(Heuristic1(Close[Last_Close].Self) != 0){
		Set_Col_Row(Close[Last_Close].Self);
		if(Row < 2){//move to down
			Copy_Arrays(Close[Last_Close].Self, Temp.Parent);
			Copy_Arrays(Temp.Parent, Temp.Self);
			//swap space
			Temp.Self[Row][Col] = Temp.Self[Row][Col] + Temp.Self[Row + 1][Col];
			Temp.Self[Row + 1][Col] = Temp.Self[Row][Col] - Temp.Self[Row + 1][Col];
			Temp.Self[Row][Col] = Temp.Self[Row][Col] - Temp.Self[Row + 1][Col];
			//...        CAl G && H
			Temp.Heuristic = Heuristic2(Temp.Self);
			Temp.G = Heuristic1(Close[Last_Close].Self);
			//...
			Src_Op = Search_Open(Open, Temp.Self);
			Src_Cl = Search_Open(Close, Temp.Self);
			//add to open
			if(Src_Op == -1 && Src_Cl == -1){
				Open[Last_Open] = Temp;
				Open[Last_Open++].Num = ++Cur_Num;
			}
			//exist open not close
			else if(Src_Op != -1 && Open[Src_Op].G + Open[Src_Op].Heuristic > Temp.G + Temp.Heuristic){
				Open[Src_Op].G = Temp.G;
				Open[Src_Op].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Open[Src_Op].Parent);
			}
			else if(Src_Cl != -1 && Close[Src_Cl].G + Close[Src_Cl].Heuristic > Temp.G + Temp.Heuristic){
				for(i = 0; i < 700 && Open[i].Num != -1;i++)
					if(Compare_Arrays(Open[i].Parent,Close[Src_Cl].Self) == 1)
						Open[i].G = Open[i].G - Close[Src_Cl].G + Temp.G;
				Close[Src_Cl].G = Temp.G;
				Close[Src_Cl].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Close[Src_Cl].Parent);
			}
		}
		if(Row > 0){      //move Up
			Copy_Arrays(Close[Last_Close].Self, Temp.Parent);
			Copy_Arrays(Temp.Parent, Temp.Self);
			Temp.Self[Row][Col] = Temp.Self[Row][Col] + Temp.Self[Row - 1][Col];
			Temp.Self[Row - 1][Col] = Temp.Self[Row][Col] - Temp.Self[Row - 1][Col];
			Temp.Self[Row][Col] = Temp.Self[Row][Col] - Temp.Self[Row - 1][Col];
			Temp.Heuristic = Heuristic2(Temp.Self);
			Temp.G = Heuristic1(Close[Last_Close].Self);
			Src_Op = Search_Open(Open, Temp.Self);
			Src_Cl = Search_Open(Close, Temp.Self);
			if(Src_Op == -1 && Src_Cl == -1){
				Open[Last_Open] = Temp;
				Open[Last_Open++].Num = ++Cur_Num;
			}
			else if(Src_Op != -1 && Open[Src_Op].G + Open[Src_Op].Heuristic > Temp.G + Temp.Heuristic){
				Open[Src_Op].G = Temp.G;
				Open[Src_Op].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Open[Src_Op].Parent);
			}
			else if(Src_Cl != -1 && Close[Src_Cl].G + Close[Src_Cl].Heuristic > Temp.G + Temp.Heuristic){
				for(i = 0; i < 700 && Open[i].Num != -1;i++)
					if(Compare_Arrays(Open[i].Parent,Close[Src_Cl].Self) == 1)
						Open[i].G = Open[i].G - Close[Src_Cl].G + Temp.G;
				Close[Src_Cl].G = Temp.G;
				Close[Src_Cl].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Close[Src_Cl].Parent);
			}
		}
		if(Col < 2){   //move right
			Copy_Arrays(Close[Last_Close].Self, Temp.Parent);
			Copy_Arrays(Temp.Parent, Temp.Self);
			Temp.Self[Row][Col] = Temp.Self[Row][Col] + Temp.Self[Row][Col + 1];
			Temp.Self[Row][Col + 1] = Temp.Self[Row][Col] - Temp.Self[Row][Col + 1];
			Temp.Self[Row][Col] = Temp.Self[Row][Col] - Temp.Self[Row][Col + 1];
			Temp.Heuristic = Heuristic2(Temp.Self);
			Temp.G = Heuristic1(Close[Last_Close].Self);
			Src_Op = Search_Open(Open, Temp.Self);
			Src_Cl = Search_Open(Close, Temp.Self);
			if(Src_Op == -1 && Src_Cl == -1){
				Open[Last_Open] = Temp;
				Open[Last_Open++].Num = ++Cur_Num;
			}
			else if(Src_Op != -1 && Open[Src_Op].G + Open[Src_Op].Heuristic > Temp.G + Temp.Heuristic){
				Open[Src_Op].G = Temp.G;
				Open[Src_Op].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Open[Src_Op].Parent);
			}
			else if(Src_Cl != -1 && Close[Src_Cl].G + Close[Src_Cl].Heuristic > Temp.G + Temp.Heuristic){
				for(i = 0; i < 700 && Open[i].Num != -1;i++)
					if(Compare_Arrays(Open[i].Parent,Close[Src_Cl].Self) == 1)
						Open[i].G = Open[i].G - Close[Src_Cl].G + Temp.G;
				Close[Src_Cl].G = Temp.G;
				Close[Src_Cl].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Close[Src_Cl].Parent);
			}
		}
		if(Col > 0){     //move left
			Copy_Arrays(Close[Last_Close].Self, Temp.Parent);
			Copy_Arrays(Temp.Parent, Temp.Self);
			Temp.Self[Row][Col] = Temp.Self[Row][Col] + Temp.Self[Row][Col - 1];
			Temp.Self[Row][Col - 1] = Temp.Self[Row][Col] - Temp.Self[Row][Col - 1];
			Temp.Self[Row][Col] = Temp.Self[Row][Col] - Temp.Self[Row][Col - 1];
			Temp.Heuristic = Heuristic2(Temp.Self);
			Temp.G = Heuristic1(Close[Last_Close].Self);
			Src_Op = Search_Open(Open, Temp.Self);
			Src_Cl = Search_Open(Close, Temp.Self);
			if(Src_Op == -1 && Src_Cl == -1){
				Open[Last_Open] = Temp;
				Open[Last_Open++].Num = ++Cur_Num;
			}
			else if(Src_Op != -1 && Open[Src_Op].G + Open[Src_Op].Heuristic > Temp.G + Temp.Heuristic){
				Open[Src_Op].G = Temp.G;
				Open[Src_Op].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Open[Src_Op].Parent);
			}
			else if(Src_Cl != -1 && Close[Src_Cl].G + Close[Src_Cl].Heuristic > Temp.G + Temp.Heuristic){
				for(i = 0; i < 700 && Open[i].Num != -1;i++)
					if(Compare_Arrays(Open[i].Parent,Close[Src_Cl].Self) == 1)
						Open[i].G = Open[i].G - Close[Src_Cl].G + Temp.G;
				Close[Src_Cl].G = Temp.G;
				Close[Src_Cl].Heuristic = Temp.Heuristic;
				Copy_Arrays(Temp.Parent, Close[Src_Cl].Parent);
			}
		}
		Src_Op = Select_Min();//in open find minimum
		Close[++Last_Close] = Open[Src_Op];
		for(i = 0; i< 3; i++)
			for(j=0; j<3; j++)
			{
				gotoxy(i+1,j+1);
				cout<<Close[Last_Close].Self[i][j]<<"   ";
			}
		for(i = Src_Op; i < 700 && Open[i].Num != -1; i++)
			Open[i] = Open[i + 1];
		Last_Open --;
		Open[i - 1].Num = -1;
	}
cout<<endl<<"\nCompleted\n"<<endl;
for(i = 0; i< 3; i++){
	for(j=0; j<3; j++)
		cout<<Close[Last_Close].Self[i][j]<<"   ";
	cout<<endl;
}
}
//------------------------------------------------
int Select_Min(){
	int i,j, index;
	Queue Min;
	Min = Open[0];
	index = 0;
	for(i = 1; i < 700 && Open[i].Num != -1; i++)
		if(Open[i].G + Open[i].Heuristic < Min.G + Min.Heuristic){
			Min = Open[i];
			index = i;
		}
	return index;
}
//-------------------------------------------------

void Set_Col_Row(int arr[3][3]){
	int i,j;
	for(i = 0; i<3; i++)
		for(j = 0; j<3; j++)
			if(!arr[i][j]){
				Row = i;
				Col = j;
				return;
			}
}
//-----------------------------------------------
void Copy_Arrays(int src[3][3],int dest[3][3]){
	int i,j;
	for(i = 0; i< 3; i++)
		for(j = 0; j<3; j++)
			dest[i][j] = src[i][j];
}
//------------------------------------------------
int Compare_Arrays(int first[3][3],int second[3][3]){
	int i,j;
	for(i = 0; i< 3; i++)
		for(j = 0; j<3; j++)
			if (first[i][j] != second[i][j])
				return -1;
	return 1;
}
//-------------------------------------------------
int Search_Open(Queue Ar[700],int arr[3][3]){
	int i;
	for(i = 0; i < 700 && Ar[i].Num != -1; i++)
		//if equal return index
		if (Compare_Arrays(Ar[i].Self, arr) != -1)
			return i;
	return -1;
}