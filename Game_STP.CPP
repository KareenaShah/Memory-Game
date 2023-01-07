#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>

//---------------------------FUNCTIONS-----------------------------//
void title();
void levels();
void credits();
void loading();
void instructions();
void productions();
void introduction();
void dialbox();
void dialbox1();
void dialbox2();

void countDown();
void result();
void paintGrid1();               //This will paint the Grid for Level 1
void paintCard(int, int, int, int);         //This will paint the card
void paintLegend(int, int, int); //This will paint legend on each card
void fill1();
int  chooseCard();
void showCard(int, char[]);
void playGame();
void paintLevelOptions();
void playLevel(int);

//-------------------------GLOBAL VARIABLES------------------------------------------------------------------------------------------------------------------------------

int midx,midy,b;
int N,M;
char msg[40];
char m[4],n[4];
int x=40,y=30,x1=0,y1=0,x2=0,y2=0;
char cardLegend[20][3]={"1","2","3","4","5","6","7","8","9","10","11","12","13", "14", "15", "16", "17", "18", "19", "20"};
char holder1[20][4]={"\0"};
int holder1showpos[12][2]={40, 30, 130, 30, 220, 30, 310, 30, 40, 150, 130, 150, 220, 150, 310, 150, 40, 270, 130, 270, 220, 270, 310, 270};
int cardPos[12][2]={20, 20, 110, 20, 200, 20, 290, 20, 20, 140, 110, 140, 200, 140, 290, 140, 20, 260, 110, 260, 200, 260, 290, 260 };
int legendPos[12][2]={85, 115, 175, 115, 265, 115, 355, 115, 85, 235, 175, 235, 265, 235, 355, 235, 85, 355, 175, 355, 265, 355, 355, 355};

int levelSelected=0;
int levelAttained=0;
int levelSize;
int const level1Size=12;
int const level2Size=16;
int const level3Size=20;

int const level1Duration=60;    //in seconds
int const level2Duration=180;
int const level3Duration=300;

int const LEVEL1STARTNO=1;
int const LEVEL1ENDNO=12;
int const LEVEL2STARTNO=1;
int const LEVEL2ENDNO=16;
int const LEVEL3STARTNO=1;
int const LEVEL3ENDNO=20;
int cardsMatch;
int levelStartTime, levelCurrentDuration;
int levelStartNo, levelEndNo;


//Level-2 Arrays
//cardPos2 Array will store the positions of the cards
//holder2showpos will store the positions of the letters to be shown when the card is selected
//legendPos2 will store the poistions of the legends to be shown on the card
int cardPos2[16][2] = {20, 20, 100, 20, 180, 20, 260, 20, 20, 120, 100, 120, 180, 120, 260, 120, 20, 220, 100, 220, 180, 220, 260, 220, 20, 320, 100, 320, 180, 320, 260, 320};
int holder2showpos[16][2] = {30, 30, 110, 30, 190, 30, 270, 30, 30, 130, 110, 130, 190, 130, 270, 130, 30, 230, 110, 230, 190, 230, 270, 230, 30, 330, 110, 330, 190, 330, 270, 330};
int legendPos2[16][2] = {75, 95, 155, 95, 235, 95, 315, 95, 75, 195, 155, 195, 235, 195, 315, 195, 75, 295, 155, 295, 235, 295, 315, 295, 75, 395, 155, 395, 235, 395, 315, 395};

//Level-3 Arrays
int cardPos3[20][2] = {20, 20, 100, 20, 180, 20, 260, 20, 20, 110, 100, 110, 180, 110, 260, 110, 20, 200, 100, 200, 180, 200, 260, 200, 20, 290, 100, 290, 180, 290, 260, 290, 20, 380, 100, 380, 180, 380, 260, 380};
int legendPos3[20][2] = {75, 85, 155, 85, 235, 85, 315, 85, 75, 175, 155, 175, 235, 175, 315, 175, 75, 265, 155, 265, 235, 265, 315, 265, 75, 355, 155, 355, 235, 355, 315, 355, 75, 445, 155, 445, 235, 445, 315, 445};
int holder3showpos[20][2] = {30, 30, 110, 30, 190, 30, 270, 30, 30, 120, 110, 120, 190, 120, 270, 120, 30, 210, 110, 210, 190, 210, 270, 210, 30, 300, 110, 300, 190, 300, 270, 300, 30, 390, 110, 390, 190, 390, 270, 390};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
	cleardevice();

	productions();
	title();
	loading();
	introduction();

	playGame();
	closegraph();
	exit(0);
}

void productions()
{
	int w,r,s;
	randomize();
	//background
	for(int h=0;h<=1000;h++)
	   {
		   w=random(getmaxx());
		   r=random(getmaxy());
		   s=random(16);
		   putpixel(w,r,s);
	     }

	//elliptical shape
	for(int color=1;color<=14;color++)
	{
		setcolor(color);

		line(100,100,540,100);
		line(100,280,540,280);
		line(100,101,540,101);
		line(100,281,540,281);
		line(100,102,540,102);
		line(100,282,540,282);
		line(100,103,540,103);
		line(100,283,540,283);
		line(100,104,540,104);
		line(100,284,540,284);
		arc(100,190,90,270,90);
		arc(100,191,90,270,90);
		arc(100,192,90,270,90);
		arc(100,193,90,270,90);
		arc(100,194,90,270,90);
		arc(540,190,270,90,90);
		arc(540,191,270,90,90);
		arc(540,192,270,90,90);
		arc(540,193,270,90,90);
		arc(540,194,270,90,90);
		delay(100);
	}

	//productions' name
	setcolor(WHITE);
	settextstyle(0,0,4);
	outtextxy(240,55,"Smart");

	//T
	for(int z=135;z<=255;z+=5)
	{
		bar(135,145,155,z);
		delay(30);
	}

	for(z=88;z<=200;z+=5)
	{
		 bar(88,125,z,145);
		delay(30);
	 }

	//E
	for(z=135;z<=255;z+=5)
	{
		bar(220,145,240,z);
		delay(30);
	}

	for(z=220;z<=300;z+=5)
	{
		bar(220,125,z,145);
		delay(30);
	}

	for(z=220;z<=280;z+=5)
	{
		bar(220,180,z,200);
		delay(30);
	}

	for(z=220;z<=300;z+=5)
	{
		bar(220,235,z,255);
		delay(30);
	 }

	//C
	 for(z=320;z<=420;z+=5)
	  {
		bar(320,125,z,145);
		delay(30);
	}

	for(z=135;z<=255;z+=5)
	 {
		bar(320,135,340,z);
		delay(30);
	 }

	for(z=320;z<=420;z+=5)
	{
		bar(320,235,z,255);
		delay(30);
	}

	//H
	for(z=125;z<=255;z+=5)
	{
		bar(440,125,460,z);
		delay(30);
	}

	for(z=440;z<=520;z+=5)
	{
		bar(440,180,z,200);
		delay(30);
	}

	for(z=125;z<=255;z+=5)
	{
		bar(520,125,540,z);
		delay(30);
	  }


	setcolor(YELLOW);
	settextstyle(2,0,9);
	outtextxy(230,295,"Productions");

	settextstyle(2,0,7);
	outtextxy(250,325,"Presents");
	delay(1000);

}

void title()
{  	int k=0,y=0,q,p,i;
	cleardevice();
	k=midx-200;
	q=midy-20;

	//main font
	settextstyle(0,0,5);
	setcolor(YELLOW);
	outtextxy(k-2,q-2,"MEMORY GAME");

	settextstyle(0,0,5);
	setcolor(BLACK);
	sprintf(msg, "MEMORY GAME", 5);
	outtextxy(k,q,msg);

	delay(550);
	cleardevice();

	//fill red colour
	settextstyle(0,0,5);
	setcolor(YELLOW);
	outtextxy(k-2,q-2,"MEMORY GAME");
	settextstyle(0,0,5);
	setcolor(RED);
	sprintf(msg, "MEMORY GAME", 5);
	outtextxy(k,q,msg);
	delay(550);
	cleardevice();

	//text enlarging effect
	for(i=6,k=midx-250;i<590,k>midx-316;k-=50,i++)
	 {
		cleardevice();
		settextstyle(0,0,i);
		setcolor(YELLOW);
		outtextxy(k-2,q-2,"MEMORY GAME");
		settextstyle(0,0,i);
		setcolor(RED);
		outtextxy(k,q,"MEMORY GAME");

		delay(70);

	 }

	getch();

	//text sliding from bottom to top
	for(y=getmaxy()-8;y>10;y-=100)
	{
		cleardevice();
		settextstyle(0,0,6);
		setcolor(YELLOW);
		outtextxy(k-2,y-2,"MEMORY GAME");
		settextstyle(0,0,6);
		setcolor(RED);
		sprintf(msg, "MEMORY GAME", 6);
		outtextxy(k,y,msg);

		delay(10);

	 }
}

void loading()
{
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(4);
	int c=150;
	 for(int e=0;e<15;e++)
	{
		for(int i=50;i<100;i++)
		 {
			setcolor(11);
			settextstyle(SMALL_FONT, HORIZ_DIR, 10);
			outtextxy(midx,midy,"Loading...");
			settextstyle(SMALL_FONT, HORIZ_DIR, 5);
			outtextxy(midx+6,midy+6,"Please Wait... ");
			circle(midx,midy,i);
			circle(midx,midy,i+1);
			circle(midx,midy,c-1);
			circle(midx,midy,c);
			c--;
			delay(3);
			cleardevice();
		}
	}
}


void introduction()
{
	int y=0,q,i;


	 //text sliding from bottom to top
	for( y=getmaxy()-8;y>=4;y-=30)
	{
		cleardevice();
		 settextstyle(0,0,5);
		 setcolor(RED);
		outtextxy(midx-245,y-2,"MEMORY GAME");
		settextstyle(0,0,5);
		 setcolor(CYAN);
		 sprintf(msg, "MEMORY GAME", 5);
		outtextxy(midx-243,y,msg);

		delay(30);
	}
	//title
	cleardevice();
	settextstyle(0,0,5);
	setcolor(RED);
	outtextxy(midx-245,4,"MEMORY GAME");
	settextstyle(0,0,5);
	setcolor(CYAN);
	sprintf(msg, "MEMORY GAME", 5);
	outtextxy(midx-243,6,msg);

	//options
	settextstyle(3,0,5);
	setcolor(YELLOW);
	outtextxy(midx-120,midy-100,"1.New Game");
	delay(100);

	outtextxy(midx-120,midy-50,"2.Instructions");
	delay(100);

	 outtextxy(midx-120,midy,"3.Credits");
	delay(100);

	outtextxy(midx-120,midy+50,"4.Exit");
	delay(100);

	setcolor(WHITE);
	settextstyle(3,0,2);
	outtextxy(10,midy+170,"Note: Enter 1 for new game, 2 for viewing instructions");
	outtextxy(10,midy+200,"3 for credits and 4 for exiting the game...");

	//for choosing options
	cin>>N;

	switch(N)
	{
		 case 1:cleardevice();
			paintLevelOptions();
			break;
		case 2: cleardevice();
			instructions();
			break;
		case 3: cleardevice();
			credits();
			break;
		case 4:closegraph();
			break;
		default: cout<<"Invalid input"<<endl;
			 break;
	}


}


void dialbox()
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(160,170,470,310);
	 floodfill(200,200,CYAN);

	settextstyle(1,0,1);
	setcolor(RED);
	sprintf(msg, "You need to complete",5);
	outtextxy(195,200,msg);

	sprintf(msg,"previous levels in ",5);
	outtextxy(210,220,msg);


	sprintf(msg,"order to play this level!",5);
	outtextxy(195,240,msg);
	getch();


}

void dialbox1()
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(160,170,470,310);
	 floodfill(200,200,CYAN);

	settextstyle(1,0,1);
	setcolor(RED);
	sprintf(msg, "Game Over",5);
	outtextxy(200,200,msg);
}

void dialbox2()
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(160,170,470,310);
	 floodfill(200,200,CYAN);

	settextstyle(1,0,4);
	setcolor(RED);
	sprintf(msg, "Game duration ",5);
	outtextxy(200,200,msg);
	outtextxy(250,230,"Over");
}



void instructions()
{
	settextstyle(0,0,5);
	 setcolor(RED);
	outtextxy(midx-155,4,"INSTRUCTIONS");
	settextstyle(0,0,5);
	setcolor(CYAN);
	sprintf(msg, "INSTRUCTIONS", 5);
	outtextxy(midx-153,6,msg);


	settextstyle(3,0,3);
	setcolor(RED);
	outtextxy(midx-310,midy-117,"OBJECTIVE:-");

	 settextstyle(3,0,2);
	setcolor(YELLOW);
	outtextxy(midx-310,midy-95,"*The objective of the game is to collect the most matching");

	outtextxy(midx-310,midy-75," pairs");

	 settextstyle(3,0,3);
	 setcolor(RED);
	outtextxy(midx-310,midy-42,"HOW TO PLAY:-");

	settextstyle(3,0,2);
	setcolor(YELLOW);
	outtextxy(midx-310,midy-20,"*The player chooses any one card and clicks on it to turn it.");

	outtextxy(midx-310,midy,"*Then the player selects another card and turns it over.");

	outtextxy(midx-310,midy+20,"*If the two cards are a matching pair for example two A's");

	outtextxy(midx-310,midy+40," or two B's then those two cards will be eliminated. ");


	outtextxy(midx-310,midy+60,"*The player has to continue the same in other chances and");

	outtextxy(midx-310,midy+80," eliminate all the cards.");

	settextstyle(3,0,3);
	setcolor(RED);
	 outtextxy(midx-310,midy+117,"WINNING THE GAME:-");

	settextstyle(3,0,2);
	setcolor(YELLOW);
	outtextxy(midx-310,midy+135,"*Once all the cards are eliminated within the given time limit,");

	outtextxy(midx-310,midy+155," the player wins the game.");

	settextstyle(6,0,1);
	setcolor(BROWN);
	outtextxy(midx+180,midy+180,"Menu (enter 45)");

	cin>>b;
	if(b==45 )
	{
		introduction();
	}
	else
	{
		cout<<"Invalid input"<<endl;
	}


 }

void credits()
{

	settextstyle(0,0,5);
	setcolor(RED);
	outtextxy(midx-145,4,"CREDITS");
	settextstyle(0,0,5);
	setcolor(CYAN);
	sprintf(msg, "CREDITS", 5);
	outtextxy(midx-143,6,msg);

	settextstyle(3,0,5);
	setcolor(YELLOW);
	outtextxy(midx-130,midy-120,"Aneri Bhuptani");

	outtextxy(midx-130,midy-70,"Kareena Shah");

	outtextxy(midx-130,midy-20,"Anirudha Surve");

	outtextxy(midx-130,midy+30,"Anmol Singh");

	settextstyle(10,0,4);
	setcolor(GREEN);
	outtextxy(midx-260,midy+70,"SPECIAL THANKS TO:");
	setcolor(CYAN);
	outtextxy(midx-170,midy+120,"SMRITI MA'AM");

	settextstyle(6,0,1);
	setcolor(BROWN);
	outtextxy(midx+180,midy+180,"Menu (enter 45)");

	cin>>b;
	if(b==45 )
	{

		 introduction();
	}
	else
	{
		cout<<"Invalid input"<<endl;
	}

   }




void playGame()
{
	while (levelSelected != 4)
	{
	       paintLevelOptions();
	       gotoxy(0,0);
	     {  cout<<"select level: ";
	       cin>>levelSelected;
	       }
	       if(levelSelected == 45)
	       {
			introduction();
	       }
	       else if (levelSelected == 4)
	       {
			continue;
	       }
	       else if (levelSelected != 1 && (levelSelected > levelAttained+1))
	       {
			dialbox();
	       }
	       else
	       {
			playLevel(levelSelected);
	       }
	}
	return;
}

void paintLevelOptions()
{
	cleardevice();

	if(levelAttained==0)
	{
		settextstyle(0,0,5);
		setcolor(RED);
		outtextxy(midx-145,4,"LEVELS");
		settextstyle(0,0,5);
		setcolor(CYAN);
		sprintf(msg, "LEVELS", 5);
		outtextxy(midx-143,6,msg);

		//thickness of rectangles
		setcolor(YELLOW);
		for(int h=0,j=100,h1=150,j1=370;h<=10,j<=110,h1>140,j1>360;h++,j++,h1--,j1--)
		rectangle(h,j,h1,j1);
		for(int h2=230,j2=100,h3=380,j3=370;h2<=2200,j2<=110,h3>370,j3>360;h2++,j2++,h3--,j3--)
		rectangle(h2,j2,h3,j3);
		for(int h4=460,j4=100,h5=610,j5=370;h4<=450,j4<=110,h5>600,j5>360;h4++,j4++,h5--,j5--)
		rectangle(h4,j4,h5,j5);

		settextstyle(7,0,4);
		setcolor(GREEN);
		sprintf(msg, "Level 1", 5);
		outtextxy(25,210,msg);

		sprintf(msg, "Level 2", 5);
		outtextxy(256,210,msg);

		sprintf(msg, "Level 3", 5);
		outtextxy(485,210,msg);

		//lock for lev_2
		setcolor(YELLOW);
		setfillstyle(CLOSE_DOT_FILL,BROWN);
		rectangle(285,290,325,330);
		floodfill(300 ,320,YELLOW); //fill the bounded region

		ellipse(305,290,0,180,15,22);
		circle(305,315,3);

		//lock for lev_3
		setcolor(YELLOW);
		setfillstyle(CLOSE_DOT_FILL,BROWN);
		rectangle(515,290,555,330);
		 floodfill(525,320,YELLOW); //fill the bounded region

		ellipse(535,290,0,180,15,22);
		circle(535,315,3) ;
	}

	if(levelAttained==1)
	{
		settextstyle(0,0,5);
		setcolor(RED);
		outtextxy(midx-145,4,"LEVELS");
		settextstyle(0,0,5);
		setcolor(CYAN);
		sprintf(msg, "LEVELS", 5);
		outtextxy(midx-143,6,msg);

		//thickness of rectangles
		setcolor(YELLOW);
		for(int h=0,j=100,h1=150,j1=370;h<=10,j<=110,h1>140,j1>360;h++,j++,h1--,j1--)
		rectangle(h,j,h1,j1);
		for(int h2=230,j2=100,h3=380,j3=370;h2<=2200,j2<=110,h3>370,j3>360;h2++,j2++,h3--,j3--)
		rectangle(h2,j2,h3,j3);
		for(int h4=460,j4=100,h5=610,j5=370;h4<=450,j4<=110,h5>600,j5>360;h4++,j4++,h5--,j5--)
		rectangle(h4,j4,h5,j5);

		settextstyle(7,0,4);
		setcolor(GREEN);
		sprintf(msg, "Level 1", 5);
		outtextxy(25,210,msg);

		sprintf(msg, "Level 2", 5);
		outtextxy(256,210,msg);

		sprintf(msg, "Level 3", 5);
		outtextxy(485,210,msg);

		//lock for lev_3
		setcolor(YELLOW);
		setfillstyle(CLOSE_DOT_FILL,BROWN);
		rectangle(515,290,555,330);
		 floodfill(525,320,YELLOW); //fill the bounded region

		ellipse(535,290,0,180,15,22);
		circle(535,315,3) ;
	}

	if(levelAttained==2)
	{
		settextstyle(0,0,5);
		setcolor(RED);
		outtextxy(midx-145,4,"LEVELS");
		settextstyle(0,0,5);
		setcolor(CYAN);
		sprintf(msg, "LEVELS", 5);
		outtextxy(midx-143,6,msg);

		//thickness of rectangles
		setcolor(YELLOW);
		for(int h=0,j=100,h1=150,j1=370;h<=10,j<=110,h1>140,j1>360;h++,j++,h1--,j1--)
		rectangle(h,j,h1,j1);
		for(int h2=230,j2=100,h3=380,j3=370;h2<=2200,j2<=110,h3>370,j3>360;h2++,j2++,h3--,j3--)
		rectangle(h2,j2,h3,j3);
		for(int h4=460,j4=100,h5=610,j5=370;h4<=450,j4<=110,h5>600,j5>360;h4++,j4++,h5--,j5--)
		rectangle(h4,j4,h5,j5);

		settextstyle(7,0,4);
		setcolor(GREEN);
		sprintf(msg, "Level 1", 5);
		outtextxy(25,210,msg);

		sprintf(msg, "Level 2", 5);
		outtextxy(256,210,msg);

		sprintf(msg, "Level 3", 5);
		outtextxy(485,210,msg);

	}
	settextstyle(6,0,1);
	setcolor(BROWN);
	outtextxy(midx+180,midy+180,"Menu (enter 45)");

	return;
}
void playLevel(int levelSelected)
{
	for (int i = 0; i<=19; i++)
		strcpy(holder1[i], "\0");

	switch(levelSelected)
	{
		case 1:
		       {
				paintGrid1();
				fill1();
				cardsMatch = 0;
				levelSize = level1Size;
				levelStartTime = clock();
				levelStartNo = LEVEL1STARTNO;
				levelEndNo = LEVEL1ENDNO;
				while(!chooseCard())
				{
					;
				}
				break;
			}
		case 2:
			{
				paintGrid1();
				fill1();
				cardsMatch = 0;
				levelSize = level2Size;
				levelStartTime = clock();
				levelStartNo = LEVEL2STARTNO;
				levelEndNo = LEVEL2ENDNO;

				while(!chooseCard())
				{
					;
				}
				break;
			}
		case 3:
			{
				paintGrid1();
				fill1();
				cardsMatch = 0;
				levelSize = level3Size;
				levelStartTime = clock();
				levelStartNo = LEVEL3STARTNO;
				levelEndNo = LEVEL3ENDNO;

				while(!chooseCard())
				{
					;
				}
				break;
			}
	}
	return;
}
void paintGrid1()
{
	int pos=0;
	cleardevice();
	setcolor(2);
	rectangle(2,2,getmaxx()-2,getmaxy()-2);
	setcolor(4);
	rectangle(6,6,getmaxx()-6,getmaxy()-6);
	setcolor(2);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(2);
	rectangle(2,2,getmaxx()-2,getmaxy()-2);
	setcolor(4);
	rectangle(6,6,getmaxx()-6,getmaxy()-6);
	setcolor(2);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);

	switch (levelSelected)
	{
	case 1:
		{
			for (int i=0; i<=11; i++)
			{
				paintCard(cardPos[i][0], cardPos[i][1], YELLOW, RED);
			}
			for (i=0; i<=11; i++)
			{
				paintLegend(legendPos[i][0], legendPos[i][1], pos);
				pos++;
			}

			setcolor(LIGHTGRAY);
			settextstyle(3,0,2);
			outtextxy(375,280,"Note: A hidden timer is ");
			outtextxy(375,300,"checking on you complete");
			outtextxy(375,320,"the game in 1 minute");
			break;
		}
	case 2:
		{
			for (int i=0; i<=15; i++)
			{
				paintCard(cardPos2[i][0], cardPos2[i][1], YELLOW, RED);
			}
			for (i=0; i<=15; i++)
			{
				paintLegend(legendPos2[i][0], legendPos2[i][1], pos);
				pos++;
			}

			setcolor(LIGHTGRAY);
			settextstyle(3,0,2);
			outtextxy(355,280,"Note: A hidden timer is ");
			outtextxy(355,300,"checking on you complete");
			outtextxy(355,320,"the game in 3 minute");
			break;
		}
	case 3:
		{
			for (int i=0; i<=19; i++)
			{
				paintCard(cardPos3[i][0], cardPos3[i][1], YELLOW, RED);
			}
			for (i=0; i<=19; i++)
			{
				paintLegend(legendPos3[i][0], legendPos3[i][1], pos);
				pos++;
			}
			setcolor(LIGHTGRAY);
			settextstyle(3,0,2);
			outtextxy(345,280,"Note: A hidden timer is ");
			outtextxy(345,300,"checking on you complete");
			outtextxy(345,320,"the game in 5 minute");
			break;
		}

	}
	settextstyle(6,0,1);
	setcolor(BROWN);
	outtextxy(midx+175,midy+180,"Go Back (enter 0)");

	return;
}

void paintCard(int cardXCord, int cardYCord, int setClr, int fillStyleClr)
{
	setcolor(setClr);
	setfillstyle(SOLID_FILL, fillStyleClr);
	switch(levelSelected)
	{
		case 1:
			bar3d(cardXCord, cardYCord, cardXCord+80, cardYCord+110, 0,0);
			break;
		case 2:
			bar3d(cardXCord, cardYCord, cardXCord+70, cardYCord+90, 0,0);
			break;
		case 3:
			bar3d(cardXCord, cardYCord, cardXCord+70, cardYCord+80, 0,0);
			break;
	}
	floodfill(cardXCord+20, cardYCord+20, setClr);

	return;
}

void paintLegend(int legendXCord, int legendYCord, int pos)
{
	setcolor(LIGHTGRAY);
	settextstyle(0,0,1);
	outtextxy(legendXCord, legendYCord, cardLegend[pos]);
	return;
}


void fill1()
{

	char letter[12][2] = {"D","B","N","R","P","M","P","N","M","D","B","R"};
	char letter2[16][3] = {"EF","BP","PB","AX","OQ","QO","UV","KR","EF","BP","PB","AX","OQ","QO","UV","KR"};
	char letter3[20][4] = {"32","OQR","ROQ","89","QQ","U","060","32","060","QQ","89","PR","V","OQR","U","PR","V","900","900","ROQ"};
	int  iterationlen = 0;
	int i=0,pos;

	switch (levelSelected)
	{
		case 1:
			iterationlen = 11;
			break;
		case 2:
			iterationlen = 15;
			break;
		case 3:
			iterationlen = 19;
			break;
	}
	randomize();
	for( i=0; i<=iterationlen; i++)
	{
		for(;;)
		{
			pos = random(iterationlen+1);
			if (levelSelected == 1)
			{
				if(strcmpi(letter[pos],"\0")!=0)
				{
					strcpy(holder1[i],letter[pos]);
					strcpy(letter[pos],"\0");
					break;
				}
				else
				{
					continue;
				}

			}
			else if (levelSelected == 2)
			{
				if(strcmpi(letter2[pos],"\0")!=0)
				{
					strcpy(holder1[i],letter2[pos]);
					strcpy(letter2[pos],"\0");
					break;
				}
				else
				{
					continue;
				}
			}
			else if (levelSelected == 3)
			{
				if(strcmpi(letter3[pos],"\0")!=0)
				{
					strcpy(holder1[i],letter3[pos]);
					strcpy(letter3[pos],"\0");
					break;
				}
				else
				{
					continue;
				}
			}
		 }
    }

}

void countDown()
{ char A[30];

  setcolor(WHITE);
  arc(130,470,0,180,90);
  setcolor(WHITE);
  arc(130,470,0,180,88);
  setcolor(WHITE);
  arc(130,470,0,180,86);

  settextstyle(3,0,6);
  setcolor(CYAN);

  for(int c=10;c>=0;c--)
  {   setfillstyle(SOLID_FILL,BLACK);
      floodfill(130,450,WHITE);
      sprintf(A,"%d",c);
      outtextxy(110,390,A);
      delay(1000);
  }
}

int chooseCard()
{
	setcolor(BLACK);
	bar3d(375,30,619,250,0,0);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(400,50,BLACK);

	setcolor(YELLOW);
	settextstyle(8,0,2);
	outtextxy(380,40,"Please Choose First");
	outtextxy(380,68,"Card:");
	//outtextxy(57,6,"Card:");

	gotoxy(57,6);

	N = -1;
	while ((N!=0 && N < levelStartNo) || N > levelEndNo || (N>0 && (strcmpi(holder1[N-1],"\0")==0)))
	{
		cin>>N;

	}

	if (N==0)
	{
		return 1;
	}

	//Check if play time duration for the level has exceeded
	levelCurrentDuration = clock();
	if ((levelCurrentDuration - levelStartTime)/CLK_TCK >= level1Duration)
	{
		dialbox2();
		delay(2000);
		return 1;
	}


   // selectCard1;
	showCard(N,n);

	setcolor(YELLOW);
	settextstyle(8,0,2);
	outtextxy(380,120,"Please Choose Second");
	outtextxy(380,148,"Card:");

	gotoxy(57,11);
	M = -1;
	while (((M !=0 && M < levelStartNo) || M > levelEndNo) || (M == N) || (M>0 && (strcmpi(holder1[M-1], "\0")==0)))
		cin>>M;

	if (M==0)
	{
		return 1;
	}

	//Check if play time duration for the level has exceeded
	levelCurrentDuration = clock();
	if ((levelCurrentDuration - levelStartTime)/CLK_TCK >= level1Duration)
	{
		dialbox2();
		delay(2000);
		return 1;
	}
//  selectCard2();
	showCard(M,m);
       //	getch();
	delay(1000);
	result();
	if (cardsMatch == levelSize)
	{
		levelAttained = levelSelected;
		return 1;
	}
	else
	{
		return 0;
	}
}

void result()
{
	switch(levelSelected)
	{
		case 1:
		      {
			if(strcmpi(m,n)==0)
			{
				paintCard(cardPos[M-1][0], cardPos[M-1][1], YELLOW, BLACK);
				paintCard(cardPos[N-1][0], cardPos[N-1][1], YELLOW, BLACK);
				cardsMatch +=2;
				strcpy(holder1[N-1],"\0");
				strcpy(holder1[M-1],"\0");
			}

			else
			{
				paintCard(cardPos[M-1][0], cardPos[M-1][1], YELLOW, RED);
				paintCard(cardPos[N-1][0], cardPos[N-1][1], YELLOW, RED);
				paintLegend(legendPos[M-1][0],  legendPos[M-1][1], M-1);
				paintLegend(legendPos[N-1][0],  legendPos[N-1][1], N-1);
			}
			break;
		      }
		case 2:
		      {
			if(strcmpi(m,n)==0)
			{
				paintCard(cardPos2[M-1][0], cardPos2[M-1][1], YELLOW, BLACK);
				paintCard(cardPos2[N-1][0], cardPos2[N-1][1], YELLOW, BLACK);
				cardsMatch +=2;
				strcpy(holder1[N-1],"\0");
				strcpy(holder1[M-1],"\0");
			}

			else
			{
				paintCard(cardPos2[M-1][0], cardPos2[M-1][1], YELLOW, RED);
				paintCard(cardPos2[N-1][0], cardPos2[N-1][1], YELLOW, RED);
				paintLegend(legendPos2[M-1][0],  legendPos2[M-1][1], M-1);
				paintLegend(legendPos2[N-1][0],  legendPos2[N-1][1], N-1);
			}
			break;
		      }
		case 3:
		      {
			if(strcmpi(m,n)==0)
			{
				paintCard(cardPos3[M-1][0], cardPos3[M-1][1], YELLOW, BLACK);
				paintCard(cardPos3[N-1][0], cardPos3[N-1][1], YELLOW, BLACK);
				cardsMatch +=2;
				strcpy(holder1[N-1],"\0");
				strcpy(holder1[M-1],"\0");
			}

			else
			{
				paintCard(cardPos3[M-1][0], cardPos3[M-1][1], YELLOW, RED);
				paintCard(cardPos3[N-1][0], cardPos3[N-1][1], YELLOW, RED);
				paintLegend(legendPos3[M-1][0],  legendPos3[M-1][1], M-1);
				paintLegend(legendPos3[N-1][0],  legendPos3[N-1][1], N-1);
			}
			break;
		      }
	}
	if (levelAttained==3)
	{
		dialbox1();
		delay(1500);
	}
}
void showCard(int pos, char selectedChar[])
{
	setcolor(WHITE);

	switch(levelSelected)
	{
		case 1:
			{
			settextstyle(1, 0, 7);
			outtextxy(holder1showpos[pos-1][0],holder1showpos[pos-1][1],holder1[pos-1]);
			strcpy(selectedChar,holder1[pos-1]);
			break;
			}
		case 2:
			{
			settextstyle(1, 0, 5);
			outtextxy(holder2showpos[pos-1][0],holder2showpos[pos-1][1],holder1[pos-1]);
			strcpy(selectedChar,holder1[pos-1]);
			break;
			}
		case 3:
			{
			settextstyle(1, 0, 4);
			outtextxy(holder3showpos[pos-1][0],holder3showpos[pos-1][1],holder1[pos-1]);
			strcpy(selectedChar,holder1[pos-1]);
			break;
			}
	}
       return;
}




