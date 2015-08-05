#ifndef nishant
#define nishant
#include<stdio.h>
typedef short Xposition  ;
typedef short Yposition ;
typedef short COLOUMN ;
typedef short ROW ;
typedef short COLWIDTH ;
typedef short ROWWIDTH ;
typedef short X1position;
typedef short Y1position;
void gotoxy(short int col,short int row)
{
	printf("%c[%d;%df",0x1B,row,col);
}
void GRIDS(Xposition x,Yposition y,COLOUMN c,ROW r,COLWIDTH cw,ROWWIDTH rw)
{
	int i,j,k,l;
	system("clear");
	for(j=0,l=0;j<=r;l+=rw,j++)
	   for(i=0;i<=c*cw;i++)
	   {
		   gotoxy(x+i,y+l);
		   printf("%c",196);
	   }
	for(i=0,k=0;i<=c;k+=cw,i++)
	{
		for(j=0;j<=r*rw;j++)
		{
			gotoxy(x+k,y+j);
			printf("%c",179);
		}
	}
	for(i=0,k=cw;i<c-1;k+=cw,i++)
	{
		for(j=0,l=rw;j<r-1;l+=rw,j++)
		{
			gotoxy(x+k,y+l);
			printf("%c",197);
		}
	}
	for(i=0,k=cw;i<c-1;k+=cw,i++)
	{
		gotoxy(x+k,y);
		printf("%c",194);
		gotoxy(x+k,y+r*rw);
		printf("%c",193);
	}
	for(j=0,l=rw;j<r-1;l+=rw,j++)
	{
		gotoxy(x,y+l);
		printf("%c",195);
		gotoxy(x+c*cw,y+l);
		printf("%c",180);
	}
	gotoxy(x,y);
	printf("%c",218);
	gotoxy(x,y+r*rw);
	printf("%c",192);
	gotoxy(x+c*cw,y);
	printf("%c",191);
	gotoxy(x+c*cw,y+r*rw);
	printf("%c",217);
}
void BOX(Xposition x,Yposition y,X1position l,Y1position b)
{
	int i;
	for(i=x;i<=l;i++)
	{
		gotoxy(i,y);
		printf("%c",205);
		gotoxy(i,b);
		printf("%c",205);
	}
	for(i=y;i<=b;i++)
	{
		gotoxy(x,i);
		printf("%c",186);
		gotoxy(l,i);
		printf("%c",186);
	}
	gotoxy(x,y);
	printf("%c",201);
	gotoxy(x,b);
	printf("%c",200);
	gotoxy(l,y);
	printf("%c",187);
	gotoxy(l,b);
	printf("%c",188);
}
#endif