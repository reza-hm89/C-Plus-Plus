/* This is a demo on how to display a bitmap file */

#include<bitmap.h>
#include<stdlib.h>
#include<conio.h>


void main(void)
{      // cleardevice();
	int driver=VGA,mode=VGAHI,errorcode;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	errorcode=graphresult();
	if(errorcode!=grOk)
	{
		printf("\n\nGRAPHICS ERROR: %s.\nPress any key to abort. . .",grapherrormsg(errorcode));
		getch();
		exit(EXIT_FAILURE);
	}
	displaybitmap(0,0,"e:\\2.BMP");
	getch();
	closegraph();
}