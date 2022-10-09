void graphic();
void introduce();
void button();
int arrow();
//////////////////////////////////
void graphic()
{
	int d=DETECT,m=0;
	initgraph(&d,&m,"c:\\tc\\bgi");
       //	introduce();
	button();
}
/////////////////////////////////
void introduce()
{
	int i,j,k,z;
	cleardevice();
	setbkcolor(1);
	settextstyle(1,0,7);
	setfillstyle(1,1);
	delay(2000);
	for (i=-20,j=500;i<150,j>250;i+=3,j-=5) {
		bar (50,i,450,i+60);
		outtextxy(170,i,"WELCOME");
		outtextxy(170,i,"WELCOME");
		bar (0,j,640,j+70);
		outtextxy(70,j,"SPORT COMPLEX");
		delay(5);
		}
		delay(500);
		outtextxy(270,190,"TO");
		delay(100);
		///////////////////////////////////
		setcolor(2);
		outtextxy(170,i-3,"WELCOME");
		delay(350);
		setcolor(15);
		outtextxy(170,i-3,"WELCOME");
		//////////////////////////////////
		setcolor(2);
		outtextxy(270,190,"TO");
		delay(250);
		setcolor(15);
		outtextxy(270,190,"TO");
		//////////////////////////////////
		setcolor(2);
		outtextxy(70,j+5,"SPORT COMPLEX");
		delay(350);
		setcolor(15);
		outtextxy(70,j+5,"SPORT COMPLEX");
		//////////////////////////////////
		for (i=0,z=640;i,640,z>=0;i++,z--)
		{
			for (j=0,k=479;j<240,k>=240;j++,k--)
			{
				putpixel(i,j,0);
				putpixel(z,k,0);
			}
		}
}
//////////////////////////////////////////////////////////////
void button()
{
	int i,j,k;
	int x,y=10;
	setbkcolor(0);
	setfillstyle(1,1);
	bar (0,0,639,470);
	setfillstyle(1,7);
	for (i=0,j=640;i<220,j>=420;i++,j--)
	{
		setfillstyle(1,1);
		bar (i-200,y+10,i,y+40);
		setfillstyle(1,7);
		bar (i,y+10,i+200,y+40);
		setcolor(15);
		line (i,y+10,i,y+40);
		line (i,y+10,i+200,y+10);
		setcolor(0);
		line (i,y+40,i+200,y+40);
		line (i+200,y+10,i+200,y+40);
		////////////////////////
		setfillstyle(1,1);
		bar (j,y+60,j+200,y+90);
		setfillstyle(1,7);
		bar (j-200,y+60,j,y+90);
		setcolor(15);
		line (j-200,y+60,j-200,y+90);
		line (j-200,y+60,j,y+60);
		setcolor(0);
		line (j-200,y+90,j,y+90);
		line (j,y+60,j,y+90);
		/////////////////////////
		setfillstyle(1,1);
		bar (i-200,y+110,i,y+140);
		setfillstyle(1,7);
		bar (i,y+110,i+200,y+140);
		setcolor(15);
		line (i,y+110,i,y+140);
		line (i,y+110,i+200,y+110);
		setcolor(0);
		line (i,y+140,i+200,y+140);
		line (i+200,y+110,i+200,y+140);
		////////////////////////
		setfillstyle(1,1);
		bar (j,y+160,j+200,y+190);
		setfillstyle(1,7);
		bar (j-200,y+160,j,y+190);
		setcolor(15);
		line (j-200,y+160,j-200,y+190);
		line (j-200,y+160,j,y+160);
		setcolor(0);
		line (j-200,y+190,j,y+190);
		line (j,y+160,j,y+190);
		/////////////////////////
		setfillstyle(1,1);
		bar (i-200,y+210,i,y+240);
		setfillstyle(1,7);
		bar (i,y+210,i+200,y+240);
		setcolor(15);
		line (i,y+210,i,y+240);
		line (i,y+210,i+200,y+210);
		setcolor(0);
		line (i,y+240,i+200,y+240);
		line (i+200,y+210,i+200,y+240);
		////////////////////////
		setfillstyle(1,1);
		bar (j,y+260,j+200,y+290);
		setfillstyle(1,7);
		bar (j-200,y+260,j,y+290);
		setcolor(15);
		line (j-200,y+260,j-200,y+290);
		line (j-200,y+160,j,y+160);
		setcolor(0);
		line (j-200,y+290,j,y+290);
		line (j,y+260,j,y+290);
		/////////////////////////
		setfillstyle(1,1);
		bar (i-200,y+310,i,y+340);
		setfillstyle(1,7);
		bar (i,y+310,i+200,y+340);
		setcolor(15);
		line (i,y+310,i,y+340);
		line (i,y+310,i+200,y+310);
		setcolor(0);
		line (i,y+340,i+200,y+340);
		line (i+200,y+310,i+200,y+340);
		////////////////////////
		setfillstyle(1,1);
		bar (j,y+360,j+200,y+390);
		setfillstyle(1,7);
		bar (j-200,y+360,j,y+390);
		setcolor(15);
		line (j-200,y+360,j-200,y+390);
		line (j-200,y+360,j,y+360);
		setcolor(0);
		line (j-200,y+390,j,y+390);
		line (j,y+360,j,y+390);
		/////////////////////////
		setfillstyle(1,1);
		bar (i-200,y+410,i,y+440);
		setfillstyle(1,7);
		bar (i,y+410,i+200,y+440);
		setcolor(15);
		line (i,y+410,i,y+440);
		line (i,y+410,i+200,y+410);
		setcolor(0);
		line (i,y+440,i+200,y+440);
		line (i+200,y+410,i+200,y+440);
	}
	settextstyle(2,0,6);
	outtextxy(270,20,"Add member");
	outtextxy(260,70,"Delete member");
	outtextxy(235,120,"Extend date credit");
	outtextxy(270,170,"Edit member");
	outtextxy(250,220,"Show all member");
	outtextxy(230,270,"Show special member");
	outtextxy(230,320,"Show teminal member");
	outtextxy(290,370,"Search");
	outtextxy(300,420,"Exit");
}
//////////////////////////////////////////////////////////////////
int arrow()
{
char ch=5;
int y=1;
while (1)
{
	ch=getch();
	if (ch==80 || ch==72)
	{
		setcolor(0);
		switch (y) {
		case 1:outtextxy(270,20,"Add member");
		break;
		case 2:outtextxy(260,70,"Delete member");
		break;
		case 3:outtextxy(235,120,"Extend date credit");
		break;
		case 4:outtextxy(270,170,"Edit member");
		break;
		case 5:outtextxy(250,220,"Show all member");
		break;
		case 6:outtextxy(230,270,"Show special member");
		break;
		case 7:outtextxy(230,320,"Show teminal member");
		break;
		case 8:outtextxy(290,370,"Search");;
		break;
		case 9:outtextxy(300,420,"Exit");
	}
	switch (ch){
	case 80:y++;
		break;
	case 72:y--;
		break;
	}
	if (y>9)
		y=1;
	if (y<1)
		y=9;
	}
	setcolor(14);
	switch (y) {
		case 1:outtextxy(270,20,"Add member");
		break;
		case 2:outtextxy(260,70,"Delete member");
		break;
		case 3:outtextxy(235,120,"Extend date credit");
		break;
		case 4:outtextxy(270,170,"Edit member");
		break;
		case 5:outtextxy(250,220,"Show all member");
		break;
		case 6:outtextxy(230,270,"Show special member");
		break;
		case 7:outtextxy(230,320,"Show teminal member");
		break;
		case 8:outtextxy(290,370,"Search");;
		break;
		case 9:outtextxy(300,420,"Exit");
	}
	if (ch==13)
		return y;
}//end of while
}
//////////////////////////////////////////////////////////
