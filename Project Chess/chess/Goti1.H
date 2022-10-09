
//#include<math.h>

int wwins=0,bwins=0;
void clear(char ,char );
void bishop(int x,int y,char color)
    {
     if(color=='b')   //Code to draw BLACK BISHOP
       {
	// set fill pattern
	setfillstyle(SOLID_FILL,DARKGRAY);
	// draw a filled ellipse
	setcolor(BLUE);
	fillellipse(x+25,y+10,5,5);
	fillellipse(x+25,y+26,6,11);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,BLUE);
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,11);
	putpixel(x+24,y+24,12);
       }
     else      //Code to draw WHITE BISHOP
       {
	// set fill pattern
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	// draw a filled ellipse
	setcolor(CYAN);
	fillellipse(x+25,y+10,5,5);
	fillellipse(x+25,y+26,6,11);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,CYAN);
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,11);
	putpixel(x+24,y+24,12);
       }
    }


void pawn(int x,int y,char color)
    {
     if(color=='b')   //Code to draw BLACK PAWN
       {
	setfillstyle(SOLID_FILL,DARKGRAY);
	setcolor(BLUE);
	/* draw a filled ellipse */
	 {
	  fillellipse(x+22,y+12,3,3);
	  fillellipse(x+22,y+23,4,8);
	  fillellipse(x+22,y+33,8,2);
	 }
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,1);
	putpixel(x+24,y+24,1);
       }
     else       //Code to draw WHITE PAWN
       {
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	setcolor(CYAN);
	/* draw a filled ellipse */
	 {
	  fillellipse(x+22,y+12,3,3);
	  fillellipse(x+22,y+23,4,8);
	  fillellipse(x+22,y+33,8,2);
	 }
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,1);
	putpixel(x+24,y+24,1);
       }
    }

void rookh(int x,int y,char color)
    {
     if(color=='b')
       {
	//Code to draw BLACK ROOKH

	/* set fill pattern */
	setfillstyle(SOLID_FILL,DARKGRAY);

	setcolor(BLUE);
	rectangle(x+10,y+12,x+50-10,y+16);
	floodfill(x+11,y+13,BLUE);
	rectangle(x+15,y+16,x+50-15,y+38);
	floodfill(x+16,y+17,BLUE);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,BLUE);
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,7);
	putpixel(x+24,y+24,7);
       }
     else
       {
	//Code to draw WHITE ROOKH
	/* set fill pattern */
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	setcolor(CYAN);
	rectangle(x+10,y+12,x+50-10,y+16);
	floodfill(x+13,y+13,CYAN);
	rectangle(x+15,y+16,x+50-15,y+38);
	floodfill(x+16,y+17,CYAN);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,CYAN);
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,7);
	putpixel(x+24,y+24,7);
       }
    }

void horse(int x,int y,char color)
    {
     if(color=='b')
       {
	//Code to draw Black Horse
	//Set fill pattern
	setfillstyle(SOLID_FILL,DARKGRAY);
	//Draw a filled ellipse
	setcolor(BLUE);
	fillellipse(x+14,y+14,8,5);
	putpixel(x+16,y+13,BLUE);
	fillellipse(x+24,y+26,8,12);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,BLUE);
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,12);
	putpixel(x+24,y+24,12);
       }
     else
       {
	//Code to draw WHITE Horse
	/* set fill pattern */
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	/* draw a filled ellipse */
	setcolor(CYAN);
	fillellipse(x+14,y+14,8,5);
	putpixel(x+16,y+13,CYAN);
	fillellipse(x+24,y+26,8,12);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,CYAN);
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,12);
	putpixel(x+24,y+24,12);
       }
    }

void king(int x,int y,char color)
    {
     if(color=='b')
       {
	//Code to draw BLACK KING

	/* set fill pattern */
	setfillstyle(SOLID_FILL,DARKGRAY);
	/* draw a filled ellipse */
	setcolor(BLUE);
	rectangle(x+21,y+2,x+27,y+14);
	floodfill(x+23,y+3,BLUE);
	rectangle(x+15,y+6,x+50-16,y+10);
	floodfill(x+16,y+7,BLUE);
	floodfill(x+50-17,y+9,BLUE);
	rectangle(x+10,y+14,x+50-10,y+18);
	floodfill(x+11,y+15,BLUE);
	rectangle(x+15,y+18,x+50-15,y+38);
	floodfill(x+16,y+19,BLUE);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,BLUE);
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,2);
	putpixel(x+24,y+24,2);
       }
     else
       {
	//Code to draw WHITE KING

	/* set fill pattern */
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	/* draw a filled ellipse */
	setcolor(CYAN);
	rectangle(x+22,y+2,x+26,y+14);
	floodfill(x+23,y+3,CYAN);
	rectangle(x+15,y+6,x+50-16,y+10);
	floodfill(x+16,y+7,CYAN);
	floodfill(x+50-17,y+9,CYAN);
	rectangle(x+10,y+14,x+50-10,y+18);
	floodfill(x+11,y+15,CYAN);
	rectangle(x+15,y+18,x+50-15,y+38);
	floodfill(x+16,y+19,CYAN);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,CYAN);
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,2);
	putpixel(x+24,y+24,2);
       }
    }

void queen(int x,int y,char color)
    {
     if(color=='b')
       {
	//Code to draw BLACK QUEEN

	/* set fill pattern */
	setfillstyle(SOLID_FILL,DARKGRAY);
	/* draw a filled ellipse */
	setcolor(BLUE);
	pieslice(x+25,y+14,0,180,10);
	rectangle(x+10,y+14,x+50-10,y+18);
	floodfill(x+11,y+15,BLUE);
	rectangle(x+15,y+18,x+50-15,y+38);
	floodfill(x+16,y+19,BLUE);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,BLUE);
	putpixel(x+25,y+25,DARKGRAY);
	putpixel(x+23,y+24,6);
	putpixel(x+24,y+24,6);
       }
     else
       {
	//Code to draw WHITE QUEEN

	/* set fill pattern */
	setfillstyle(SOLID_FILL,LIGHTCYAN);
	/* draw a filled ellipse */
	setcolor(CYAN);
	pieslice(x+25,y+14,0,180,10);
	rectangle(x+10,y+14,x+50-10,y+18);
	floodfill(x+11,y+15,CYAN);
	rectangle(x+15,y+18,x+50-15,y+38);
	floodfill(x+16,y+19,CYAN);
	rectangle(x+10,y+38,x+50-10,y+42);
	floodfill(x+11,y+39,CYAN);
	putpixel(x+25,y+25,LIGHTCYAN);
	putpixel(x+23,y+24,6);
	putpixel(x+24,y+24,6);
       }
    }

int move(char col,char a1,char b1,char a2,char b2)
   {

    int i,x1,y1,x2,y2;
    unsigned gcolor1,gcolor2,gcolor3,gcolor4,pixcol,goticol;
    int flag,tempX,tempY,tempcol;
    static int rookhchkw=0,rookhchkb=0,kingchkw=0,kingchkb=0;


    //co-ordinate setting from parameter  (x1,y1)(initial co-ordinates)
    if(a1=='a')
    x1=100;
    if(a1=='b')
    x1=150;
    if(a1=='c')
    x1=200;
    if(a1=='d')
    x1=250;
    if(a1=='e')
    x1=300;
    if(a1=='f')
    x1=350;
    if(a1=='g')
    x1=400;
    if(a1=='h')
    x1=450;

    if(b1=='8')
    y1=50;
    if(b1=='7')
    y1=100;
    if(b1=='6')
    y1=150;
    if(b1=='5')
    y1=200;
    if(b1=='4')
    y1=250;
    if(b1=='3')
    y1=300;
    if(b1=='2')
    y1=350;
    if(b1=='1')
    y1=400;

    //co-ordinate setting from parameter  (x2,y2)(Final co-ordinates)
    if(a2=='a')
    x2=100;
    if(a2=='b')
    x2=150;
    if(a2=='c')
    x2=200;
    if(a2=='d')
    x2=250;
    if(a2=='e')
    x2=300;
    if(a2=='f')
    x2=350;
    if(a2=='g')
    x2=400;
    if(a2=='h')
    x2=450;

    if(b2=='8')
    y2=50;
    if(b2=='7')
    y2=100;
    if(b2=='6')
    y2=150;
    if(b2=='5')
    y2=200;
    if(b2=='4')
    y2=250;
    if(b2=='3')
    y2=300;
    if(b2=='2')
    y2=350;
    if(b2=='1')
    y2=400;

    goticol=getpixel(x1+25,y1+25);
    pixcol=getpixel(x2+25,y2+25);

    if((col=='b'&&goticol!=DARKGRAY)||(col=='w'&&goticol!=LIGHTCYAN))
    return 1;


    //Goti identification color code
    char gname[6][8]={
		       "bishop",
		       "pawn",
		       "rookh",
		       "horse",
		       "king",
		       "queen"
		     };

    gcolor1=getpixel(x1+23,y1+24);
    gcolor2=getpixel(x1+24,y1+24);
    gcolor3=getpixel(x2+23,y2+24);
    gcolor4=getpixel(x2+24,y2+24);


    if(gcolor1==11&&gcolor2==12)
    i=0;
    if(gcolor1==1&&gcolor2==1)
    i=1;
    if(gcolor1==7&&gcolor2==7)
    i=2;
    if(gcolor1==12&&gcolor2==12)
    i=3;
    if(gcolor1==2&&gcolor2==2)
    i=4;
    if(gcolor1==6&&gcolor2==6)
    i=5;

    if(stricmp(&gname[i][0],"pawn")==0)
      {
       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       // Sets rule for pawn for cutting opponents goti
       if(goticol==LIGHTCYAN&&pixcol==DARKGRAY)
	 {
	  if((x1-x2==50||x2-x1==50)&&(y1-y2==50))
	    {
	     if(gcolor3==2&&gcolor4==2)
	     wwins=1;
	     clear(a1,b1);
	     clear(a2,b2);
	     pawn(x2,y2,col);
	    }
	  else
	  return 1;
	 }
       if(goticol==DARKGRAY&&pixcol==LIGHTCYAN)
	 {
	  if((x2-x1==50 || x1-x2==50)&&(y2-y1==50))
	    {
	     if(gcolor3==2&&gcolor4==2)
	     bwins=1;
	     clear(a1,b1);
	     clear(a2,b2);
	     pawn(x2,y2,col);
	    }
	  else
	  return 1;
	 }

       //Sets rule for movement of pawn
       if((pixcol==BLACK||pixcol==WHITE)&&goticol==LIGHTCYAN)
	 {
	  if((y1-y2==50)&&(x2==x1))
	    {
	     clear(a1,b1);
	     pawn(x2,y2,col);
	    }
	  else
	  return 1;
	 }
       if((pixcol==BLACK||pixcol==WHITE)&&goticol==DARKGRAY)
	 {
	  if((y2-y1==50)&&x2==x1)
	    {
	     clear(a1,b1);
	     pawn(x2,y2,col);
	    }
	  else
	  return 1;
	 }
      }

    if(stricmp(&gname[i][0],"rookh")==0)
      {
       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       //sets rule for vertical movement of rookh
       if(x1==x2)
	 {
	  if(y1>y2)
	    {
	     tempX=x1;
	     tempY=y1-50;
	     for(tempY-50;tempY>y2;tempY=tempY-50)
		{
		 tempcol=getpixel(tempX+25,tempY+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempY=y2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		rookh(x2,y2,col);
	       }
	    }
	  if(y1<y2)
	    {
	     tempY=y1+50;
	     tempX=x1;
	     for(tempY+50;tempY<y2;tempY=tempY+50)
		{
		 tempcol=getpixel(tempX+25,tempY+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempY=y2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		rookh(x2,y2,col);
	       }
	    }
	 }
       //sets rule for horizontal movement of rookh
       if(y1==y2)
	 {
	  if(x1>x2)
	    {
	     tempX=x1-50;
	     for(tempX-50;tempX>x2;tempX=tempX-50)
		{
		 tempcol=getpixel(tempX+25,y1+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempX=x2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		rookh(x2,y2,col);
	       }
	    }
	  if(x1<x2)
	    {
	     tempX=x1+50;
	     for(tempX+50;tempX<x2;tempX=tempX+50)
		{
		 tempcol=getpixel(tempX+25,y1+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempX=x2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		rookh(x2,y2,col);
	       }
	    }
	 }

      }

    if(stricmp(&gname[i][0],"horse")==0)
      {
       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       //Sets rule for movement of horse
       if(((x2-x1==50||x1-x2==50)&&(y2-y1==100||y1-y2==100))||((x2-x1==100||x1-x2==100)&&(y2-y1==50||y1-y2==50)))
	 {
	  clear(a1,b1);
	  clear(a2,b2);
	  horse(x2,y2,col);
	 }
       else
       return 1;
      }

    if(stricmp(&gname[i][0],"king")==0)
      {
       //sets rule for Cashling of King
       if((x1-x2==150)&&(y1==y2))
	 {
	  if((gcolor3==7&&gcolor4==7)&&(gcolor1==2&&gcolor2==2))
	   {
	    if(getpixel(x1-50+25,y1+25)!=BLACK && getpixel(x1-50+25,y1+25)!=WHITE)
	    return 1;

	    if(getpixel(x1-100+25,y1+25)!=BLACK && getpixel(x1-100+25,y1+25)!=WHITE)
	    return 1;

	    if(goticol==LIGHTCYAN)
	      {
	       if(kingchkw==1||rookhchkw==1)
	       return 1;

	       if(kingchkw==0&&rookhchkw==0)
		 {
		    clear(a1,b1);
		    clear(a2,b2);
		    king(x1-100,y1,col);
		    rookh(x2+100,y2,col);
		    kingchkw=1;
		    rookhchkw=1;
		 }
	      }
	    if(goticol==DARKGRAY)
	      {
	       if(kingchkb==1||rookhchkb==1)
	       return 1;

	       if(kingchkb==0&&rookhchkb==0)
		 {
		    clear(a1,b1);
		    clear(a2,b2);
		    king(x1-100,y1,col);
		    rookh(x2+100,y2,col);
		    kingchkb=1;
		    rookhchkb=1;
		 }
	      }
	   }
	  return 0;
	 }

       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       //Sets rule for straight movement of king
       if(((x2-x1)==50||(x1-x2)==50)&&y2==y1)
	 {
	  clear(a1,b1);
	  clear(a2,b2);
	  king(x2,y2,col);
	 }

       if(((y2-y1)==50||(y1-y2)==50)&&x2==x1)
	 {
	  clear(a1,b1);
	  clear(a2,b2);
	  king(x2,y2,col);
	 }

       //Sets rule for transverse movement of king
       if(x2-x1==50||x1-x2==50)
	 {
	  if(y2-y1==50||y1-y2==50)
	    {
	     clear(a1,b1);
	     clear(a2,b2);
	     king(x2,y2,col);
	    }
	 }
      }

    if(stricmp(&gname[i][0],"queen")==0)
      {
       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       //sets rule for vertical movement of queen
       if(x1==x2)
	 {
	  if(y1>y2)
	    {
	     tempX=x1;
	     tempY=y1-50;
	     for(tempY-50;tempY>y2;tempY=tempY-50)
		{
		 tempcol=getpixel(tempX+25,tempY+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempY=y2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		queen(x2,y2,col);
	       }
	    }
	  if(y1<y2)
	    {
	     tempY=y1+50;
	     tempX=x1;
	     for(tempY+50;tempY<y2;tempY=tempY+50)
		{
		 tempcol=getpixel(tempX+25,tempY+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempY=y2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		queen(x2,y2,col);
	       }
	    }
	 }
       //sets rule for horizontal movement of queen
       if(y1==y2)
	 {
	  if(x1>x2)
	    {
	     tempX=x1-50;
	     for(tempX-50;tempX>x2;tempX=tempX-50)
		{
		 tempcol=getpixel(tempX+25,y1+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempX=x2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		queen(x2,y2,col);
	       }
	    }
	  if(x1<x2)
	    {
	     tempX=x1+50;
	     for(tempX+50;tempX<x2;tempX=tempX+50)
		{
		 tempcol=getpixel(tempX+25,y1+25);
		 if(tempcol==BLACK||tempcol==WHITE)
		 flag=1;
		 if(tempcol==goticol)
		   {
		    flag=0;
		    tempX=x2;
		    return 1;
		   }
		}
	     if(flag!=0)
	       {
		clear(a1,b1);
		clear(a2,b2);
		queen(x2,y2,col);
	       }
	    }
	 }
       //Sets rule for tranverse movement of queen
       if(x2-x1==y2-y1||x2-x1==y1-y2)
	 {
	  if(x1>x2)
	    {
	     if(y1>y2)
	       {
		tempX=x1-50;
		tempY=y1-50;
		for(tempX-50,tempY-50;tempY>y2;tempX=tempX-50,tempY=tempY-50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   queen(x2,y2,col);
		  }
	       }
	     if(y1<y2)
	       {
		tempX=x1-50;
		tempY=y1+50;
		for(tempX-50,tempY+50;tempY<y2;tempX=tempX-50,tempY=tempY+50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   queen(x2,y2,col);
		  }
	       }
	    }
	  if(x1<x2)
	    {
	     if(y1<y2)
	       {
		tempX=x1+50;
		tempY=y1+50;
		for(tempX+50,tempY+50;tempY<y2;tempX=tempX+50,tempY=tempY+50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   queen(x2,y2,col);
		  }
	       }
	     if(y1>y2)
	       {
		tempX=x1+50;
		tempY=y1-50;
		for(tempX+50,tempY-50;tempY>y2;tempX=tempX+50,tempY=tempY-50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   queen(x2,y2,col);
		  }
	       }
	    }
	 }

      }

    if(stricmp(&gname[i][0],"bishop")==0)
      {
       // Doesn't allow a goti to cut another goti of same color
       if(pixcol==goticol)
       return 1;

       //Sets rule for movement of Bishop
       if(x2-x1==y2-y1||x2-x1==y1-y2)
	 {
	  if(x1>x2)
	    {
	     if(y1>y2)
	       {
		tempX=x1-50;
		tempY=y1-50;
		for(tempX-50,tempY-50;tempY>y2;tempX=tempX-50,tempY=tempY-50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   bishop(x2,y2,col);
		  }
	       }
	     if(y1<y2)
	       {
		tempX=x1-50;
		tempY=y1+50;
		for(tempX-50,tempY+50;tempY<y2;tempX=tempX-50,tempY=tempY+50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   bishop(x2,y2,col);
		  }
	       }
	    }
	  if(x1<x2)
	    {
	     if(y1<y2)
	       {
		tempX=x1+50;
		tempY=y1+50;
		for(tempX+50,tempY+50;tempY<y2;tempX=tempX+50,tempY=tempY+50)
		  {
		   tempcol=getpixel(tempX+25,tempY+25);
		   if(tempcol==BLACK||tempcol==WHITE)
		   flag=1;
		   if(tempcol==goticol)
		     {
		      flag=0;
		      tempY=y2;
		      return 1;
		     }
		  }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   bishop(x2,y2,col);
		  }
	       }
	     if(y1>y2)
	       {
		tempX=x1+50;
		tempY=y1-50;
		for(tempX+50,tempY-50;tempY>y2;tempX=tempX+50,tempY=tempY-50)
		   {
		    tempcol=getpixel(tempX+25,tempY+25);
		    if(tempcol==BLACK||tempcol==WHITE)
		    flag=1;
		    if(tempcol==goticol)
		      {
		       flag=0;
		       tempY=y2;
		       return 1;
		      }
		   }
		if(flag!=0)
		  {
		   clear(a1,b1);
		   clear(a2,b2);
		   bishop(x2,y2,col);
		  }
	       }
	    }
	 }
       else
       return 1;
      }

    if(gcolor3==2&&gcolor4==2)
      {
       if(goticol==LIGHTCYAN)
       wwins=1;
       else
       bwins=1;
      }
    if((a1=='a'||a1=='d')&&(b1=='1'))
    kingchkw=1;
    if((a1=='a'||a1=='d')&&(b1=='8'))
    kingchkb=1;
    return 0;
   }

void clear(char a1,char b1)
    {
     char col;
     int fillcol;
     int x1,y1;

     //fill color code and co ordinates for each 64 blocks
     if((a1=='a')&&(b1=='8'))
	{
	 x1=100;
	 y1=50;
	 col='w';
	}

     if((a1=='a')&&(b1=='7')  )
	{
	 x1=100;
	 y1=100;
	 col='b';
	}

     if((a1=='a')  &&(b1=='6')  )
	{
	 x1=100;
	 y1=150;
	 col='w';
	}

     if((a1=='a')  &&(b1=='5')  )
	{
	 x1=100;
	 y1=200;
	 col='b';
	}

     if((a1=='a')  &&(b1=='4')  )
	{
	 x1=100;
	 y1=250;
	 col='w';
	}

     if((a1=='a')  &&(b1=='3')  )
	{
	 x1=100;
	 y1=300;
	 col='b';
	}

     if((a1=='a')  &&(b1=='2')  )
	{
	 x1=100;
	 y1=350;
	 col='w';
	}

     if((a1=='a')  &&(b1=='1')  )
	{
	 x1=100;
	 y1=400;
	 col='b';
	}

     if((a1=='b')&&(b1=='8')  )
	{
	 x1=150;
	 y1=50;
	 col='b';
	}

     if((a1=='b')&&(b1=='7')  )
	{
	 x1=150;
	 y1=100;
	 col='w';
	}

     if((a1=='b')  &&(b1=='6')  )
	{
	 x1=150;
	 y1=150;
	 col='b';
	}

     if((a1=='b')  &&(b1=='5')  )
	{
	 x1=150;
	 y1=200;
	 col='w';
	}

     if((a1=='b')  &&(b1=='4')  )
	{
	 x1=150;
	 y1=250;
	 col='b';
	}

     if((a1=='b')  &&(b1=='3'))
	{
	 x1=150;
	 y1=300;
	 col='w';
	}

     if((a1=='b')  &&(b1=='2')  )
	{
	 x1=150;
	 y1=350;
	 col='b';
	}

     if((a1=='b')  &&(b1=='1'))
	{
	 x1=150;
	 y1=400;
	 col='w';
	}

     if((a1=='c')&&(b1=='8')  )
	{
	 x1=200;
	 y1=50;
	 col='w';
	}

     if((a1=='c')  &&(b1=='7')  )
	{
	 x1=200;
	 y1=100;
	 col='b';
	}

     if((a1=='c')&&(b1=='6')  )
	{
	 x1=200;
	 y1=150;
	 col='w';
	}

     if((a1=='c')  &&(b1=='5')  )
	{
	 x1=200;
	 y1=200;
	 col='b';
	}

     if((a1=='c')  &&(b1=='4')  )
	{
	 x1=200;
	 y1=250;
	 col='w';
	}

     if((a1=='c')  &&(b1=='3')  )
	{
	 x1=200;
	 y1=300;
	 col='b';
	}

     if((a1=='c')  &&(b1=='2')  )
	{
	 x1=200;
	 y1=350;
	 col='w';
	}

     if((a1=='c')  &&(b1=='1')  )
	{
	 x1=200;
	 y1=400;
	 col='b';
	}

     if((a1=='d')  &&(b1=='8')  )
	{
	 x1=250;
	 y1=50;
	 col='b';
	}

     if((a1=='d')  &&(b1=='7')  )
	{
	 x1=250;
	 y1=100;
	 col='w';
	}

     if((a1=='d')  &&(b1=='6')  )
	{
	 x1=250;
	 y1=150;
	 col='b';
	}

     if((a1=='d')  &&(b1=='5')  )
	{
	 x1=250;
	 y1=200;
	 col='w';
	}

     if((a1=='d')  &&(b1=='4')  )
	{
	 x1=250;
	 y1=250;
	 col='b';
	}

     if((a1=='d')  &&(b1=='3')  )
	{
	 x1=250;
	 y1=300;
	 col='w';
	}

     if((a1=='d')  &&(b1=='2')  )
	{
	 x1=250;
	 y1=350;
	 col='b';
	}

     if((a1=='d')  &&(b1=='1')  )
	{
	 x1=250;
	 y1=400;
	 col='w';
	}

     if((a1=='e')  &&(b1=='8')  )
	{
	 x1=300;
	 y1=50;
	 col='w';
	}

     if((a1=='e')  &&(b1=='7')  )
	{
	 x1=300;
	 y1=100;
	 col='b';
	}

     if((a1=='e')  &&(b1=='6')  )
	{
	 x1=300;
	 y1=150;
	 col='w';
	}

     if((a1=='e')  &&(b1=='5')  )
	{
	 x1=300;
	 y1=200;
	 col='b';
	}

     if((a1=='e')  &&(b1=='4')  )
	{
	 x1=300;
	 y1=250;
	 col='w';
	}

     if((a1=='e')  &&(b1=='3')  )
	{
	 x1=300;
	 y1=300;
	 col='b';
	}

     if((a1=='e')  &&(b1=='2')  )
	{
	 x1=300;
	 y1=350;
	 col='w';
	}

     if((a1=='e')  &&(b1=='1')  )
	{
	 x1=300;
	 y1=400;
	 col='b';
	}

     if((a1=='f')  &&(b1=='8')  )
	{
	 x1=350;
	 y1=50;
	 col='b';
	}

     if((a1=='f')  &&(b1=='7')  )
	{
	 x1=350;
	 y1=100;
	 col='w';
	}

     if((a1=='f')  &&(b1=='6')  )
	{
	 x1=350;
	 y1=150;
	 col='b';
	}

     if((a1=='f')  &&(b1=='5')  )
	{
	 x1=350;
	 y1=200;
	 col='w';
	}

     if((a1=='f')  &&(b1=='4')  )
	{
	 x1=350;
	 y1=250;
	 col='b';
	}

     if((a1=='f')  &&(b1=='3')  )
	{
	 x1=350;
	 y1=300;
	 col='w';
	}

     if((a1=='f')  &&(b1=='2')  )
	{
	 x1=350;
	 y1=350;
	 col='b';
	}

     if((a1=='f')  &&(b1=='1')  )
	{
	 x1=350;
	 y1=400;
	 col='w';
	}

     if((a1=='g')  &&(b1=='8')  )
	{
	 x1=400;
	 y1=50;
	 col='w';
	}

     if((a1=='g')  &&(b1=='7')  )
	{
	 x1=400;
	 y1=100;
	 col='b';
	}

     if((a1=='g')  &&(b1=='6')  )
	{
	 x1=400;
	 y1=150;
	 col='w';
	}

     if((a1=='g')  &&(b1=='5')  )
	{
	 x1=400;
	 y1=200;
	 col='b';
	}

     if((a1=='g')  &&(b1=='4')  )
	{
	 x1=400;
	 y1=250;
	 col='w';
	}

     if((a1=='g')  &&(b1=='3')  )
	{
	 x1=400;
	 y1=300;
	 col='b';
	}

     if((a1=='g')  &&(b1=='2')  )
	{
	 x1=400;
	 y1=350;
	 col='w';
	}

     if((a1=='g')  &&(b1=='1')  )
	{
	 x1=400;
	 y1=400;
	 col='b';
	}

     if((a1=='h')  &&(b1=='8')  )
	{
	 x1=450;
	 y1=50;
	 col='b';
	}

     if((a1=='h')  &&(b1=='7')  )
	{
	 x1=450;
	 y1=100;
	 col='w';
	}

     if((a1=='h')  &&(b1=='6')  )
	{
	 x1=450;
	 y1=150;
	 col='b';
	}

     if((a1=='h')  &&(b1=='5')  )
	{
	 x1=450;
	 y1=200;
	 col='w';
	}

     if((a1=='h')  &&(b1=='4')  )
	{
	 x1=450;
	 y1=250;
	 col='b';
	}

     if((a1=='h')  &&(b1=='3')  )
	{
	 x1=450;
	 y1=300;
	 col='w';
	}

     if((a1=='h')  &&(b1=='2')  )
	{
	 x1=450;
	 y1=350;
	 col='b';
	}

     if((a1=='h')  &&(b1=='1')  )
	{
	 x1=450;
	 y1=400;
	 col='w';
	}

     if(col=='b')
       {
	fillcol=BLACK;
	setfillstyle(SOLID_FILL,fillcol);
	floodfill(x1+1,y1+1,LIGHTBLUE);
       }

     if(col=='w')
       {
	fillcol=BLACK;
	setfillstyle(SOLID_FILL,fillcol);
	floodfill(x1+1,y1+1,LIGHTBLUE);
	fillcol=WHITE;
	setfillstyle(SOLID_FILL,fillcol);
	floodfill(x1+1,y1+1,LIGHTBLUE);
       }
    }