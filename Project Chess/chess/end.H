//Program to print a character on the perimeters of the screen
//Delete each line after completing it
//Program should quit if a key is pressed

void end()
    {
     clrscr();
     char name[]={" Chess Game in C "};
     char arr[]={"- by Niket Nilay & Nitin S. Rajput"};
     int col=1,i,r;
     char far *p=(char far *) 0xB0008000;
     i=(10*160)+50;
     for(r=0;r<17;r++)
	{
	 *(p+i)=name[r];
	 *(p+i+1)=78;
	 i=i+2;
	}

     i=(12*160)+56;
     for(r=0;r<34;r++)
	{
	 *(p+i)=arr[r];
	 *(p+i+1)=CYAN+BLINK;
	 i=i+2;
	}

     while(!kbhit())
	{
	 for(i=0;i<160;i=i+2)
	   {
	    if(col==16)
	    col=1;
	    *(p+i)=3;
	    *(p+i+1)=col;
	    col++;
	    delay(7);
	   }

	 for(i=0;i<160;i=i+2)
	   {
	    *(p+i)=' ';
	    delay(7);
	   }

	 for(r=0;r<=25;r++)
	   {
	    if(col==16)
	    col=1;
	    i=r*160-2;
	    *(p+i)=3;
	    *(p+i+1)=col;
	    col++;
	    delay(10);
	   }

	 for(r=0;r<=25;r++)
	   {
	    i=r*160-2;
	    *(p+i)=' ';
	    delay(10);
	   }

	 for(i=3998;i>3998-160;i=i-2)
	   {
	    if(col==16)
	    col=1;
	    *(p+i)=3;
	    *(p+i+1)=col;
	    col++;
	    delay(7);
	   }
	 for(i=3998;i>3998-160;i=i-2)
	   {
	    *(p+i)=' ';
	    delay(7);
	   }

	 for(r=24;r>=0;r--)
	   {
	    if(col==16)
	    col=1;
	    i=r*160;
	    *(p+i)=3;
	    *(p+i+1)=col;
	    col++;
	    delay(10);
	   }

	 for(r=24;r>=0;r--)
	   {
	    i=r*160;
	    *(p+i)=' ';
	    delay(10);
	   }
	}
     exit(0);
    }