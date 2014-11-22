			    //RAILWAY ENQUIRY//
 /*
-----------------------------------------------------------------------------------------------------
DATA STRUCTURE PROJECT
-----------------------
JAYPEE CONNECT.COM
-------------------
SUBMITTED BY-
-------------
SR NO.	       NAME                        ENROLLEMNET NUMBER
------         -----                       -------------------
 1.            Prakhar Gupta                  13103608
 2.            Yugal Jain                     13103611
 3.            Monik Bansal                   13103596
 4.	       Rishabh Jain		      13103594
--------------------------------------------------------------------------------------------------------

*/
 //HEADER FILES USED

 #include<stdio.h>
 #include<stdlib.h>
 #include<dos.h>
 #include<conio.h>
 #include<graphics.h>
 #include<string.h>
 #include<alloc.h>

 //STRUCTURES USED
 struct det
 {
 char name[50];
 char pass[5];
 };

 struct node
 {
 char tname;
 char st;
 struct node *down;
 struct node *next;
 };

 //USER DEFINED FUNCTIONS

 void gotoxy(int x ,int y); //this function take our cursor position to (x,y)coordinates
 void file();
 void create(int);
 void welcome();
 void loading();
 void loadbitmap(char *,int,int);
 void home();
 void common(int);
 void back(int);
 void admin();
 void admin1();
 void user();
 void user1();
 void user2();
 void traverse();
 void insert();
 void insert1(int);
 void Delete();
 void Delete1(int);
 void push(int);
 void pop(int);
 void searching();
 void detail(struct node *);
 void common2();
 void zone();
 void zone1();
 void Exit();

 //GLOBAL VARIABLES DECLARED

 struct node *start=NULL,*temp,*end,*p=NULL;
 struct node *startn=NULL,*starts=NULL,*starte=NULL,*startw=NULL;
 struct det s[5];

 FILE *ptr;
 char a[20],c[20],ch='U',d[2],st2[5],st1[5],st3[5],initial[2],final[2];
 int m=-1,f=0,h=0,u,r2=-1,r1=-1;

 //MOUSE FUNCTIONS
 int initmouse();
 void showmouseptr();
 void restrictmouseptr(int, int, int, int);
 void getmousepos(int*,int*,int*);
 union REGS i, o;


int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void restrictmouseptr(int x1, int y1, int x2, int y2)
{
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0X33,&i,&o);

   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0X33,&i,&o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}

 int getcol(int col)
 {
   switch(col)
   {
      case 0: return 0;     //BLACK;
      case 1: return 4;     //RED;
      case 2: return 2;     //GREEN
      case 3: return 6;     //BROWN
      case 4: return 1;     //BLUE;
      case 5: return 5;     //MAGENTA;
      case 6: return 3;     //CYAN;
      case 7: return 7;     //LIGHTGRAY;
      case 8: return 8;     //DARKGRAY;
      case 9: return 12;    //LIGHTRED;
      case 10:return 10;    //LIGHTGREEN
      case 11:return 14;    //YELLOW;
      case 12:return 9;     //LIGHTBLUE;
      case 13:return 13;    //LIGHTMAGENTA
      case 14:return 11;    //LIGHTCYAN;
      case 15:return 15;    //WHITE;
   }
   return col;
 }

 void main()
 {
 int gd=DETECT,gm;
 clrscr();
 initgraph(&gd,&gm,"C:\\turboc3\\BGI");
 file();
 welcome();
 cleardevice();
 loading();
 cleardevice();
 home();
 getch();
 }

 void file()
 {
 FILE *fp;               //declared local file pointr variable
 int q=-1;
 char *g[4],ch;          //We have four zone wise trains
 g[0]="north.txt";       //north
 g[1]="south.txt";       //south
 g[2]="east.txt";        //east
 g[3]="west.txt";        //west
 for(h=0;h<4;h++)
 {
 start=NULL;              //p and start is the node pointer declared globally
 p=NULL;                  //we make f=0 when every new file is open
 f=0;
 fp=fopen(g[h],"r");          //File opening
 while((ch=getc(fp))!=EOF)
 {
 q++;
 c[q]=ch;
  if(ch=='0')
  {
  create(q);                  //calling create fn
  q=-1;
  f++;
  }
 }
 fclose(fp);               //file close
 }
 }

 void create(int q)            //q is the length of our array
 {
 int l=0;
 while(l<q)
 {
 temp=(struct node*)malloc(sizeof(struct node));
 temp->tname=NULL;
 temp->st=NULL;
 temp->next=NULL;
 temp->down=NULL;
 if(l==0)                 //l is the length we are incrementing from 0 to q
 {
 start=temp;
 end=temp;
 temp->tname=c[l];
 if(p!=NULL)             //p is the node pointer declared globally
 p->down=temp;
 p=start;
 }
 else
 {
 temp->st=c[l];
 end->next=temp;
 end=temp;
 }
 l++;
 }
 if(f==0)                  //f=0,it means a new file is open ,i.e.,we are on the first postion in our new file
			   //so,we make it our start pointer
 {
 if(h==0)
 startn=start;             //startn means head pointer of NORTH ZONE
 else if(h==1)
 starts=start;             //starts means head pointer of SOUTH ZONE
 else if(h==2)
 starte=start;             //same for east
 else if(h==3)
 startw=start;             //same for west
 }
 f++;
 }

 void welcome()           //our first presenting page
 {
	float i;
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,getmaxx(),getmaxy());
	setcolor(BLUE);
	for(i=120.0;i>115.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(BROWN);
	for(i=114.0;i>109.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(CYAN);
	for(i=108.0;i>103.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(RED);
	for(i=102.0;i>97.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(MAGENTA);
	for(i=96.0;i>91.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(GREEN);
	for(i=90.0;i>85.0;i=i-0.05)
	{
		circle(325,240,i);
	}
       setcolor(YELLOW);
	for(i=84.0;i>79.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(BROWN);
	for(i=78.0;i>73.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(LIGHTBLUE);
	for(i=72.0;i>67.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(LIGHTGREEN);
	for(i=66.0;i>61.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setcolor(RED);
	for(i=60.0;i>55.0;i=i-0.05)
	{
		circle(325,240,i);
	}
	setfillstyle(SOLID_FILL,BLUE);
	bar(145,175,505,305);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(150,180,500,300);
	outtextxy(300,225,"WELCOME");
	outtextxy(320,235,"TO");
	outtextxy(262,245," RAILWAY ENQUIRY");
	delay(500);
	setcolor(RED);
	outtextxy(230,275,"Press any key to continue");
	getch();

}

void loading()
{
int j,i;
loadbitmap("tra.bmp",150,120); //tra.bmp is our image file
setcolor(WHITE);
settextstyle(2,HORIZ_DIR,7);
outtextxy(260,310,"LOADING");

for(i=0;i<3;i++)
{
	for(j=0;j<2;j++)
	{
		setcolor(WHITE);
		circle(353,327,j);
		delay(500);
		circle(363,327,j);
		delay(500);
		circle(373,327,j);
	}
	setcolor(BLACK);
	for(j=0;j<2;j++)
	{
		circle(353,327,j);
		circle(363,327,j);
		circle(373,327,j);
	}
}
 setcolor(WHITE);
 circle(353,327,2);
 circle(363,327,2);
 circle(373,327,2);
 outtextxy(155,340,"Press Any Key To Continue");
 getch();
 cleardevice();
 setcolor(BROWN);
 setfillstyle(1,BROWN);
 rectangle(0,5,5,25);
 setcolor(7);
}

void loadbitmap(char *a,int x,int y)
 {int width,height;
	       //width and height of the bitmap
   unsigned long temp=0,k=0,j=0;  //some variables i need
   unsigned long ww;
   int ch,ch1,ch2;
   ptr=fopen(a,"rb");      //open the bitmap file
	      //if its not there return

   width=0;height=0;              //initialise wisth and height to zero
   fseek(ptr,18,SEEK_SET);        //got to offset 18 in file
   for(k=0x1;k<=0x10000;k*=0x100) //read the width
   {
	   temp=fgetc(ptr);
	   width+=(temp*k);
   }
   fseek(ptr,22,SEEK_SET);        //go	 to offset 22 in file
   for(k=0x1;k<=0x10000;k*=0x100) //read the height
   {
	   temp=fgetc(ptr);
	   height+=(temp*k);
   }

   ww=width;         //ww is the number of reads to make for each horizontal line
   if(ww%2)          //ww has to be half of width - since each pixel is only 4 bits of information
  { ww++;ww/=2;}       //just getting the correct value
   if(ww%4)          //now - ww is stored as sets of 4 pixels each - i think !?! :so this is the adjustment    made
   ww=(ww/4)*4+4;    //if width is less than ww*2 we ignore what we read

   fseek(ptr,119,SEEK_SET);   //Ok! offset 119 - lets read the pixels -
			      //remember the bitmap is stroed up - side - down

   for(k=0;k<height;k++)
   for(j=0;j<ww;j++)
   {
	   ch=fgetc(ptr);    //each character read is 2 pixels - yes 4 bits per pixel - so 16 colors
	   ch1=ch;ch2=ch;                                //find those colors using bitwise ops
	   ch1=ch1&(0xf0);ch1=ch1>>4;                    // ~~
	   ch2=ch2&(0x0f);                               // ~~
	   if(j*2<width)                                 //ok so put the first pixel read on screen
	   putpixel((j*2)+x,(height-1-k)+y,getcol(ch1));
	   if(j*2+1<width)                               //put the second pixel read on screen
	   putpixel((j*2)+1+x,(height-1-k)+y,getcol(ch2));
   }
   fclose(ptr);
					 //close the file handle
  }

 void home()                     //page=0
 {
 int status,k,j=0,x,y;
 setbkcolor(BROWN);
 rectangle(0,0,getmaxx(),getmaxy());
 setcolor(GREEN);
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");
 status = initmouse();        //checking if mouse pointer available or not

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();
      restrictmouseptr(1,5,600,420);
      settextstyle(3,HORIZ_DIR,2);
      setcolor(RED);

      for(k=0;k<3;k++)
      {
	rectangle(10,120+j,250,150+j);
	j=j+70;
      }

      setfillstyle(INTERLEAVE_FILL,RED);
      floodfill(11,121,RED);
      floodfill(11,191,RED);
      floodfill(11,261,RED);
      setcolor(YELLOW);
      outtextxy(20,120,"1) Administrator Login");
      outtextxy(20,190,"2) User's Login");
      outtextxy(20,260,"3) Exit");
      strcpy(s[1].name,"PRAKHAR");
      strcpy(s[1].pass,"3608");
      strcpy(s[2].name,"YUGAL");
      strcpy(s[2].pass,"3611");
      strcpy(s[3].name,"MONIK");
      strcpy(s[3].pass,"3585");
      strcpy(s[4].name,"RISHABH");
      strcpy(s[4].pass,"3583");
      delay(1000);
      common(0);
     }
 }

 void common(int pg)           //pg=page from which common is called
 {                             //here pg is the page from which the function
  int button,x,y;             //is called  or on which we are in output
  getmousepos(&button,&x,&y);

  while(!kbhit())
  {
   getmousepos(&button,&x,&y);
      if(pg==0)
      {
	 if(button == 1 && x>=10 && x<=250 && y>=120 && y<=150)
	 {
	    button = -1;
	    cleardevice();
	    admin();           //admin fn or page 1
	 }
	 else if(button==1 && x>=10 && x<=250 && y>=190 && y<=220)
	 {
	    button = -1;
	    cleardevice();
	    user();            //page 2
	 }
	 else if(button==1 && x>=10 && x<=250 && y>=260 && y<=290)
	 {
	    button=-1;
	    cleardevice();
	    Exit();
	 }
      }
      //single condition for all REturn main menu
      else if(button==1 && x>=410 && x<=635 && y>=380 && y<=410)
      {
	    button=-1;
	    cleardevice();
	    back(0);           //page 0 or home()
      }
       else if(pg==1)
       {
	 if(button==1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button=-1;
	    cleardevice();
	    back(0);            // home()
	 }
       }
       else if(pg==2)
       {
	 if(button == 1 && x>=10 && x<=320 && y>=120 && y<=150)
	 {
	    button = -1;
	    cleardevice();
	    user1();       //page 10
	 }
	 else if(button==1 && x>=10 && x<=180 && y>=190 && y<=220)
	 {
	    button = -1;
	    cleardevice();
	    user2();       //page 13
	 }
	 else if(button==1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button=-1;
	    cleardevice();
	    home();//home or back(0) same thing
	 }
       }
       else if(pg==3)
       {
	 if(button==1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button=-1;
	    cleardevice();
	    back(1);             //page 1 or admin
	 }

	 else if(button == 1 && x>=10 && x<=250 && y>=120 && y<=150)
	 {
	    button = -1;
	    cleardevice();
	    traverse();         //page 4
	 }
	 else if(button==1 && x>=10 && x<=250 && y>=190 && y<=220)
	 {
	    button = -1;
	    cleardevice();
	    insert();           // page 5
	 }
	 else if(button==1 && x>=10 && x<=250 && y>=260 && y<=290)
	 {
	    button=-1;
	    cleardevice();
	    Delete();           // page 8
	    return;
	 }
       }

       else if(pg==4)
       {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(3);           // admin1()
	 }
       }
      else if(pg==5)
      {
	 if(button == 1 && x>=10 && x<=150 && y>=120 && y<=150)
	 {
	     button=-1;
	     cleardevice();
	     insert1(1);        // page 6
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=190 && y<=220)
	 {
	     button=-1;
	     cleardevice();
	     insert1(2);       // page 6
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=260 && y<=290)
	 {
	     button=-1;
	     cleardevice();
	     insert1(3);       // page 6
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=330 && y<=360)
	 {
	     button=-1;
	     cleardevice();
	     insert1(4);       // page 6
	 }
	 else if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(3);            // page admin1()
	 }

      }
      else if(pg==6)
      {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(5);            // page admin()
	 }
      }
      else if(pg==8)
      {
	 if(button == 1 && x>=10 && x<=150 && y>=120 && y<=150)
	 {
	     button=-1;
	     cleardevice();
	     Delete1(1);        //page 9
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=190 && y<=220)
	 {
	     button=-1;
	     cleardevice();
	     Delete1(2);        //page 9
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=260 && y<=290)
	 {
	     button=-1;
	     cleardevice();
	     Delete1(3);        //page 9
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=330 && y<=360)
	 {
	     button=-1;
	     cleardevice();
	     Delete1(4);        //page 9
	 }
	 else if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(3);            //admin1() or page 3
	 }

      }
      else if(pg==9)     //delete 1
      {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(3);      //   admin1() or page 3
	 }
      }

      else if(pg==10)
       {    if(button == 1 && x>=10 && x<=200 && y>=120 && y<=150)
	    {
	      button=-1;
	      cleardevice();
	      searching();      //page 11
	    }
	    else if(button == 1 && x>=10 && x<=260 && y>=190 && y<=220)
	    {
	      button=-1;
	      cleardevice();
	      pop(1);          //page 12
	    }
	    else if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	    {
	      button=-1;
	      cleardevice();
	      back(2);         //page 2  or user()
	    }
	}

      else if(pg==11)
      {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	   {
	     button = -1;
	    cleardevice();
	    back(10);         //page 10
	   }
      }
      else if(pg==12)
      {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	   {
	     button = -1;
	    cleardevice();
	    if(u==1)
	    back(10);
	    else if(u==2)
	    back(13);
	   }
      }
      else if(pg==13)        //called from user2()
      {
	if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(2);
	 }
	else if(button == 1 && x>=10 && x<=200 && y>=120 && y<=150)
	 {
	    button = -1;
	    cleardevice();
	    zone1();         // page 14
	 }
	 else if(button == 1 && x>=10 && x<=260 && y>=190 && y<=220)
	 {
	   button = -1;
	   cleardevice();
	   pop(2);          //page 12
	 }
      }
      else if(pg==14)
      {
	 if(button == 1 && x>=10 && x<=150 && y>=120 && y<=150)
	 {
	     button=-1;
	     cleardevice();
	     detail(startn);      // page 15
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=190 && y<=220)
	 {
	     button=-1;
	     cleardevice();
	     detail(starts);       //page 15
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=260 && y<=290)
	 {
	     button=-1;
	     cleardevice();
	     detail(starte);       //page 15
	 }
	 else if(button == 1 && x>=10 && x<=150 && y>=330 && y<=360)
	 {
	     button=-1;
	     cleardevice();
	     detail(startw);       //page 15
	 }
	 else if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(13);              //page 13
	 }
      }
      else if(pg==15)
      {
	 if(button == 1 && x>=540 && x<=635 && y>=330 && y<=360)
	 {
	    button = -1;
	    cleardevice();
	    back(14);
	 }
       }
     }
   }

 void back(int pg)
 {
	    if(pg==0)
	    home();
	    else if(pg==1)
	    admin();
	    else if(pg==2)
	    user();
	    else if(pg==3)
	    admin1();
	    else if(pg==5)
	    insert();
	    else if(pg==8)
	    Delete();
	    else if(pg==10)
	    user1();
	    else if(pg==11)
	    searching();
	    else if(pg==13)
	    user2();
	    else if(pg==14)
	    zone1();

 }

 void common2()             //creates back and return main menu button
 {
     setcolor(RED);
     rectangle(540,330,635,360);
     setfillstyle(INTERLEAVE_FILL,RED);
     floodfill(541,331,RED);
     setcolor(YELLOW);
     settextstyle(3,HORIZ_DIR,2);
     outtextxy(560,330,"Back");
     setcolor(RED);
     rectangle(410,380,635,410);
     setfillstyle(INTERLEAVE_FILL,RED);
     floodfill(411,381,RED);
     setcolor(YELLOW);
     settextstyle(3,HORIZ_DIR,2);
     outtextxy(420,382,"Return To Main Menu");
  }

  void zone()                 //simply creates 4 rectangles for zones
  {   int j=0,k;
      settextstyle(3,HORIZ_DIR,2);
      setcolor(RED);
      for(k=0;k<4;k++)
      {
	rectangle(10,120+j,150,150+j);
	j=j+70;
      }

      setfillstyle(INTERLEAVE_FILL,RED);
      floodfill(12,122,RED);
      floodfill(12,192,RED);
      floodfill(12,262,RED);
      floodfill(12,332,RED);
      setcolor(YELLOW);
      outtextxy(20,120,"1) NORTH");
      outtextxy(20,190,"2) SOUTH");
      outtextxy(20,260,"3) EAST");
      outtextxy(20,330,"4) WEST");
  }

 void admin()                    //page=1
 {
     int l=0,k,m=1,j,button,x,y;
     char v[5],b=NULL;
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");

     common2();
     outtextxy(200,50,"MEMBER'S LOGIN");
     outtextxy(10,86,"Enter Username-");
     gotoxy(24,7);
     delay(1000);
     common(1);                      //calling common from page 1
     gets(a);
   for(k=1;k<=4;k++)
   {
   m=strcmp(a,s[k].name);
   if(m==0)
   break;
   }
   outtextxy(10,118,"Enter Password-");
   gotoxy(24,9);
   common(1);                        //calling common from page 1
   while(b!=13)
   {
   b=getch();
   if(b==13)
   break;
   v[l]=b;
   printf("*");
   l++;
   }
   v[l]=NULL;

   if(m==0 && (strcmp(v,s[k].pass)==0)) //checking for correct condition of Username and Password
   {
   cleardevice();
   admin1();
   }
   else
   printf("\nWrong Input");
   common(1);                    //calling common from page 1
}

 void user()                          //page=2
 {   setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");

    common2();              //calling common 2 for(Back and Return main menu)
    setcolor(RED);
    rectangle(10,120,320,150);
    rectangle(10,120+70,180,150+70);
    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(11,121,RED);
    floodfill(11,191,RED);
    setcolor(YELLOW);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(20,120,"1)Train between two stations");
    outtextxy(20,190,"2)Train details");
    delay(1000);
    common(2);                //calling common from page 2
 }


 void admin1()                 //page=3
 {
   int j,k,button,x,y;
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");

   setcolor(RED);
      j=0;
      for(k=0;k<3;k++)
      {
	rectangle(10,120+j,250,150+j);
	j=j+70;
      }

    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(11,121,RED);
    floodfill(11,191,RED);
    floodfill(11,261,RED);

    setcolor(YELLOW);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(20,120,"1)Print Train Details");
    outtextxy(20,190,"2)Insert a New Train");
    outtextxy(20,260,"3)Delete a Train");
    setcolor(RED);
    rectangle(540,330,635,360);
    floodfill(541,331,RED);
    setcolor(YELLOW);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(560,331,"Logout");
    delay(1000);
    gotoxy(0,0);
    common(3);                        //calling common from page 3
 }

void traverse()                      //page 4
 {
 int button,x,y;
 gotoxy(1,1);
 for(h=0;h<4;h++)
 {
 if(h==0)
 {
 printf("\n\nNorth Zone-\n");
 temp=startn;
 }
 else if(h==1)
 {
 temp=starts;
 printf("\n\nSouth Zone-\n");
 }
 else if(h==2)
 {
 temp= starte;
 printf("\n\nEast Zone-\n");
 }
 else if(h==3)
 {
 temp=startw;
 printf("\n\nWest Zone-\n");
 }
 while(temp!=NULL)
 {
 p=temp->next;
 printf("%c ",temp->tname);
 while(p!=NULL)
 {
 printf("%c ",p->st);
 p=p->next;
 }
 printf("\n");
 temp=temp->down;
 }
 getch();
 }
   common2();                //calling common2 for(Back and Return main menu)
   common(4);                //calling common from page 4
 }

void insert ()                  //page 5
 {    setcolor(GREEN);
      settextstyle(0,HORIZ_DIR,2);
      outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");
      setcolor(YELLOW);
      settextstyle(3,HORIZ_DIR,2);
      outtextxy(210,50,"INSERT:-SELECT ZONE");
      zone();
      common2();             //calling common 2 for(Back and Return main menu)
      delay(1000);
      common(5);             //calling common from page 5
   }

 void insert1(int h)             //page 6
 {
 struct node *temp1=NULL,*temp=NULL;
 int n,i;
 char b[2];
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAY ENQUIRY");

 gotoxy(1,6);

 if(h==1)
 temp=startn;
 else if(h==2)
 temp=starts;
 else if(h==3)
 temp= starte;
 else if(h==4)
 temp=startw;

 setcolor(YELLOW);
 while((temp->down)!=NULL)
 temp=temp->down;

 temp1=(struct node *)malloc(sizeof(struct node));
 temp1->tname=ch;
 temp->down=temp1;
 temp1->st=NULL;
 temp1->down=NULL;
 temp1->next=NULL;
 printf("NOTE-Stations should lie between 1-9\n\n");
 printf("Enter number of stations in new train");
 scanf("%d",&n);
 printf("Enter path of new train-\nEx.     if your train moves from station 2 to 6 leaving 3 then,\n\tinput data as, \n\tInput 2 than press Enter key than Input 4 than press Enter key and so on upto your last data\n\nENTER NOW\n\n");
 for(i=0;i<n;i++)
 {
 temp=(struct node *)malloc(sizeof(struct node));
 scanf("%s",b);
 temp->st=b[0];
 temp->tname=NULL;

 temp->next=NULL;
 temp->down=NULL;
 temp1->next=temp;
 temp1=temp;
 }
 ch++;
   gotoxy(22,17);
   printf("The TraiN has BeeN Iserted");
   gotoxy(22,19);
   printf("  Your NeW TraiN Name is %c",--ch);
   ch++;
   common2();               //calling common2 for(Back and Return main menu)
   common(6);               //calling common from page 6
 }

 void Delete()               //page 8
 {
   setcolor(GREEN);
   settextstyle(0,HORIZ_DIR,2);
   outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");
   setcolor(YELLOW);
   settextstyle(3,HORIZ_DIR,2);
   outtextxy(210,50,"DELETE:-SELECT ZONE ");
   zone();
   common2();              //calling common 2 for(Back and Return main menu)
   common(8);              //calling common from page 8
   }


 void Delete1(int h)             //page 9
 {
 struct node *temp1=NULL,*temp=NULL,*start=NULL;
 char del[2],d;
 int flag=0;
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");

 gotoxy(1,5);
 p=NULL;
 if(h==1)           //if user clicks on 1st block we go for NORTH zone
 temp=startn;
 else if(h==2)      //if user clicks on 2nd block we go for NORTH zone
 temp=starts;
 else if(h==3)      //and so on
 temp= starte;
 else if(h==4)
 temp=startw;
 temp1=temp;
 start=temp;
 while(temp!=NULL)
 {                            //p is simply a node type pointer as *p
 p=temp->next;                //p is declared globally
 printf("%c ",temp->tname);
 while(p!=NULL)
 {
 printf("%c ",p->st);
 p=p->next;
 }
 printf("\n");
 temp=temp->down;
 }
 temp=temp1;
 printf("\n\nEnter train to DELETE-");
 scanf("%s",del);
 d=del[0];            //d is the first character of del[0],i.e.,our train name
 temp=start;
 p=NULL;
 while(temp!=NULL)
 {
   if(d==start->tname)
   {
     start=temp->down;
     flag=1;
     break;
   }
   else if(d==temp->tname)
   {
     if((temp->down)!=NULL)
       p->down=temp->down;
     if((temp->down)==NULL)
       p->down=NULL;
     flag=1;
   }
   p=temp;
   temp=temp->down;
 }
 if(h==1)
 startn=start;
 else if(h==2)
 starts=start;
 else if(h==3)
 starte=start;
 else if(h==4)
 startw=start;
   gotoxy(20,17);
   if(flag==1)
   printf("Train '%c' has Been Deleted",d);
   else
   printf("No Such Train is Found in this Zone");
   common2();              //calling common 2 for(Back and Return main menu)
   common(9);             //calling common from page 9
 }



  void user1()           //page 10
  {
    u=1;
    setcolor(GREEN);
    settextstyle(0,HORIZ_DIR,2);
    outtextxy(100,20,"WELCOME TO RAILWAY ENQUIRY");

    setcolor(RED);
    rectangle(10,120,200,150);
    rectangle(10,120+70,260,150+70);
    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(11,121,RED);
    floodfill(11,191,RED);
    setcolor(YELLOW);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(20,120,"1)Enter Stations");
    outtextxy(20,190,"2)Recent Five Searches");
    common2();             //calling common 2 for(Back and Return main menu)
    delay(1000);
    common(10);            //calling common from page 10
  }

 void searching()         //page 11
 {                                  //This page is to search for train between
  struct node *temp1=NULL,*temp=NULL;  //two stations and print them
  int j=0,m,flag=0;
  char store[10];

  setcolor(GREEN);
  settextstyle(0,HORIZ_DIR,2);
  outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");
  gotoxy(1,5);
  printf("Enter Beginning Station of Your Journey-> ");
  scanf("%s",initial);
  printf("\nEnter Ending Station oF Your Journey-> ");
  scanf("%s",final);
  push(1);
  for(h=1;h<=4;h++)
  {
      if(h==1)
      temp=startn;
      else if(h==2)
      temp=starts;
      else if(h==3)
      temp= starte;
      else if(h==4)
      temp=startw;
      temp1=temp;
      m=0;
      while(temp1!=NULL)
      {         flag=0;
		temp=temp1->next;
		while(temp!=NULL)
		{
			if(temp->st==initial[0] || temp->st==final[0])
			flag++;
			temp=temp->next;
		}
			if(flag==2)
			{
				store[m]=temp1->tname;
				m++;
			}


		temp1=temp1->down;
      }
      if(h==1)
      {
		printf("North Zone Trains ->");
		for(j=0;j<m;j++)
		printf("%c ",store[j]);
		printf("\n");
      }
      else if(h==2)
      {
		printf("South Zone Trains ->");
		for(j=0;j<m;j++)
		printf("%c ",store[j]);
		printf("\n");
      }
      else if(h==3)
      {
		printf("East Zone Trains ->");
		for(j=0;j<m;j++)
		printf("%c ",store[j]);
		printf("\n");
      }
      else if(h==4)
      {
		printf("West Zone Trains ->");
		for(j=0;j<m;j++)
		printf("%c ",store[j]);
		printf("\n");
      }
  }
   common2();              //calling common 2 for(Back and Return main menu)
   common(11);             //calling common from page 11
}


 void user2()           //page 13
 {
    u=2;
    setcolor(GREEN);
    settextstyle(0,HORIZ_DIR,2);
    outtextxy(100,20,"WELCOME TO RAILWAY ENQUIRY");

    setcolor(RED);
    rectangle(10,120,180,150);
    rectangle(10,120+70,260,150+70);
    setfillstyle(INTERLEAVE_FILL,RED);
    floodfill(11,121,RED);
    floodfill(11,191,RED);
    setcolor(YELLOW);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(20,120,"1)Select Zone");
    outtextxy(20,190,"2)Recent Five Searches");
    common2();             //calling common 2 for(Back and Return main menu)
    delay(1000);
    common(13);            //calling common from page 13
  }

 void zone1()              //page 14
 {

     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAY ENQUIRY");
     zone();
     common2();             //calling common 2 for(Back and Return main menu)
     delay(1000);
     common(14);            //calling common from page 14
 }
				       // page 15
   void detail(struct node *start)     //train detail
   {
     struct node *p=NULL;
     int flag=0;
     gotoxy(1,6);
     setcolor(GREEN);
     settextstyle(0,HORIZ_DIR,2);
     outtextxy(100,20,"WELCOME TO RAILWAYS ENQUIRY");
     temp=start;

     printf("Enter Train Name-");
     scanf("%s",d);
     push(2);
     while(temp!=NULL)
     {
       if(temp->tname==d[0])
	{
	 flag=1;
	 break;
	}
     temp=temp->down;
     }
     if(flag==1)
     {
       printf("%c->",temp->tname);
       p=temp->next;
       while(p!=NULL)
       {
	 printf("%c ",p->st);
	 p=p->next;
       }
     }
     else
       printf("\n\n\t\tNo such train found in this zone");

   common2();              //calling common 2 for(Back and Return main menu)
   common(15);             //calling common from page 15
   }

   void push(int u)
   {
     int j=0,k=0;
     if(u==1)
     {
       if(r2<5)
       {
	 r1++;
	 st1[r1]=initial[0];
	 st3[r1]=final[0];
       }
       else
       {
	 for(k=0;k<4;k++)
	   st1[k]=st1[++k];
	 st1[k]=d[0];
       }
     }
     if(u==2)
     {
       if(r2<5)
       {
	 r2++;
	 st2[r2]=d[0];
       }
       else
       {
	 for(j=0;j<4;j++)
	   st2[j]=st2[++j];
	 st2[j]=d[0];
       }
     }
   }

   void pop(int u)         //page 12
   {
     int j;
     gotoxy(1,1);
     printf("Recent five searches-\n");
     if(u==1)
     {
       printf("Source Station  Destination Station\n");
       for(j=r1;j>=0;j--)
       printf("\t\b%c\t\t%c\n",st1[j],st3[j]);

     }
     if(u==2)
     {
     printf("Train Name-\n");
       for(j=r2;j>=0;j--)
	 printf("%c\n",st2[j]);
     }
   common2();               //calling common 2 for(Back and Return main menu)
   common(12);              //calling common from page 12
   }

 void Exit()
  {
   setcolor(YELLOW);
   settextstyle(3,HORIZ_DIR,5);
   outtextxy(160,180,"!!  THANK YOU   !!");
   outtextxy(120,280," Press any key to EXIT");
   //getch();
  }

/*
-------------------------------------------------------------------------------------------------
FINISH
*/





