# include "iGraphics.h"
int backgroundspeed=2;
#define jumplimit -120
#define screenwidth 600
#define screenheight 800
#define ObstacleNumber 2
#define RJUMPLIMIT -140
#define LJUMPLIMIT 140
#define OBSTACLETIME 1200
int gameover=0;
int timecount=0;
int scorespeed1=800;
int pointspeed1=800;
int scorespeed2=400;
int pointspeed2=400;
int scorespeed3=200;
int pointspeed3=200;
int hisab=1;
int pause=0;
int s1=0;
int s2=0;
int s3=0;
int x = 300, y = 300, r = 15;
int gameState=-1;
char score[100];
char obstacle[4][20]= {"abc.bmp","abc.bmp","abc.bmp","abc.bmp"};
char dead[10]="dead.bmp";
bool rjump=false;
bool ljump= false;
bool ljumpup=false;
bool rjumpup=false;
int ninjarjump=0;
int ninjaljump=0;
FILE *f1;
FILE *f2;
FILE *f3;
int testsk=1;
int easy[6];
int med[6];
int hards[6];
int checkmodesk=1;




struct obstacleposition
{
    int obstaclex1;
    int obstaclex2;
    int obstacley1;
    int obstacley2;
    int obstacleindex;
    bool obstacleshow;
};
obstacleposition obs[ObstacleNumber];






;/*
	function iDraw() is called again and again by the system.
*/
void scorechange();
void obstaclemovement()
{

    for(int i=0; i<ObstacleNumber; i++)
    {
        if(obs[i].obstacleshow)
        {
            iShowBMP2(obs[i].obstaclex1,obs[i].obstacley1,obstacle[obs[i].obstacleindex],0);
        }
        hisab++;
        if(hisab%2000==0)
        {
            backgroundspeed++;
            scorespeed1++;
            pointspeed1--;
            scorespeed2++;
            pointspeed2--;
            scorespeed3++;
            pointspeed3--;

        }
    }
}
void obstaclemovement2()
{
    for(int i=0; i<ObstacleNumber; i++)
    {
        if(obs[i].obstacleshow)
        {
            iShowBMP2(obs[i].obstaclex2,obs[i].obstacley2,obstacle[obs[i].obstacleindex],0);
        }
    }
}

struct frontbackground
{
    int x;
    int y;
};
frontbackground frontbg[6];
void setAll()
{
    int sum=0;
    for(int i=0; i<6; i++)
    {
        frontbg[i].x=0;
        frontbg[i].y=sum;
        sum+=160;
    }
}

struct buttonCoordinate2
{
    int x;
    int y;
} Coordinate[10];
struct buttonCoordinate
{
    int x;
    int y;
} bCoordinate[5];
struct buttonCoordinate soundbCoordinate[2];
struct buttonCoordinate modebCoordinate[3];
int mposx,mposy;
char frontbgimage[6][80]= {"frontgameplaybg1.bmp","frontgameplaybg2.bmp","frontgameplaybg3.bmp","frontgameplaybg4.bmp","frontgameplaybg5.bmp","frontgameplaybg1.bmp"};
char button[30][50]= {"playbutton.bmp","modebutton.bmp","instructionbutton.bmp","soundbutton.bmp","highscore.bmp"};
char homemenu[30]="BakGroundImage.bmp";
char play[40]="playbackgameplay.bmp";
char play2[30]="frontgameplaybg.bmp";
char sound[30]="backgameplaybg.bmp";
char mode[30]="backgameplaybg.bmp";
char instruction[30]="instruction.bmp";
char highscorebg[40]="highscorebg.bmp";
char backbutton[20]="backbutton.bmp";
char ninja[4][20]= {"step1.bmp","step2.bmp","step3.bmp","step4.bmp"};
char ninja2[8][20]= {"R1.bmp","R2.bmp","R3.bmp","R4.bmp","R5.bmp","R6.bmp","R7.bmp","R8.bmp"};
int ninjaCoordinateX=41;
int ninjaCoordinateY=200;
int ninjaindex=0;
int ninja2CoordinateX=459;
int ninja2CoordinateY=200;
int ninja2index=0;
char soundButton[2][30]= {"soundbuttonON.bmp","soundbuttonOFF.bmp"};
char modeButton[3][40]= {"EasyButton.bmp","MediumButton.bmp","HardButton.bmp"};
char ninjaJR[20][20]= {"RL1.bmp","RL2.bmp","RL3.bmp","RL4.bmp","RL5.bmp","RL6.bmp","RL7.bmp"};
char ninjaJL[20][20]= {"LR1.bmp","LR2.bmp","LR3.bmp","LR4.bmp","LR5.bmp","LR6.bmp","LR7.bmp"};
char ninjarj[5][20]= {"rjump5.bmp","rjump6.bmp"};
char ninjalj[3][20]= {"ljump1.bmp","ljump6.bmp"};
char gameovermenu[20][20]= {"playagain.bmp","mainmenu.bmp"};
bool soundactivation=true;

struct backbuttonCoordinate
{
    int x;
    int y;
} backbuttonCoordinate;

void iDraw()
{
    int i;
    iClear();
    iSetColor(0,100,255);
    //place your drawing codes here

    if(gameState==-1)
    {
                        iPauseTimer(0);
                        iPauseTimer(1);
                        iPauseTimer(2);
                        iPauseTimer(3);
                        iPauseTimer(4);
                        iPauseTimer(5);
                        iPauseTimer(6);


        iShowBMP(0,0,homemenu);
        for(i=0; i<5; i++)
        {
            iShowBMP2(bCoordinate[i].x,bCoordinate[i].y,button[i],0);
        }

    }
    else if(gameState==0)
    {
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            iResumeTimer(5);
            iResumeTimer(6);

        int i=0;
        iShowBMP(0,0,play);
        if(ljump)
        {
            if(ljumpup)
            {

                iShowBMP2(ninjaCoordinateX+ninjaljump,ninjaCoordinateY,ninjalj[0],0);

            }
            else
            {

                iShowBMP2(ninjaCoordinateX+ninjaljump,ninjaCoordinateY,ninjalj[1],0);

            }

        }
        else
        {
            iShowBMP2(ninjaCoordinateX,ninjaCoordinateY,ninja[ninjaindex],0);

        }












        for( i=0; i<6; i++)
        {
            iShowBMP2(frontbg[i].x,frontbg[i].y,frontbgimage[i],0);
            timecount++;
        }

        //iShowBMP(0,0,play2);
        if(timecount>=OBSTACLETIME)
        {
            obstaclemovement();
            obstaclemovement2();
            for(int i=0; i<ObstacleNumber; i++)
            {
                if(obs[i].obstacley1<=200+backgroundspeed &&obs[i].obstacley1>=200-backgroundspeed)
                {
                    if(!ljump)
                    {
                        iPauseTimer(0);
                        iPauseTimer(1);
                        iPauseTimer(2);
                        iPauseTimer(3);
                        iPauseTimer(4);
                        iPauseTimer(5);
                        iPauseTimer(6);
                        gameover=1;
                        iShowBMP2(40,200,dead,0);
                        for(i=1; i==1; i++)
                        {
                            iShowBMP2(Coordinate[i].x,Coordinate[i].y,gameovermenu[i],0);
                        }
                        int j;

                        if( checkmodesk==1)
                        {
                             sprintf(score,"%d",s1);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("input.txt","a");
                                fprintf(f1,"%d  ",s1);
                                fclose(f1);
                                testsk++;


                                f1=fopen("input.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&easy[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(easy[j]<easy[m])
                                        {
                                            int temp=easy[j];
                                            easy[j]=easy[m];
                                            easy[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("input.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",easy[j]);

                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",easy[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s1);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }
                        else if( checkmodesk==2)
                        {
                             sprintf(score,"%d",s2);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("medscore.txt","a");
                                fprintf(f1,"%d  ",s2);
                                fclose(f1);
                                testsk++;


                                f1=fopen("medscore.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&med[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(med[j]<med[m])
                                        {
                                            int temp=med[j];
                                            med[j]=med[m];
                                            med[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("medscore.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",med[j]);

                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",med[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s2);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }
                        else if( checkmodesk==3)
                        {
                             sprintf(score,"%d",s3);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("hardscore.txt","a");
                                fprintf(f1,"%d  ",s3);
                                fclose(f1);
                                testsk++;


                                f1=fopen("hardscore.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&hards[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(hards[j]<hards[m])
                                        {
                                            int temp=hards[j];
                                            hards[j]=hards[m];
                                            hards[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("hardscore.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",hards[j]);

                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",hards[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s3);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }


                    }


                }
            }

        }



    }
    else if(gameState==1)
    {
        iShowBMP(0,0,mode);
        iShowBMP2(backbuttonCoordinate.x,backbuttonCoordinate.y,backbutton,0);
        for(i=0; i<3; i++)
        {
            iShowBMP2(modebCoordinate[i].x,modebCoordinate[i].y,modeButton[i],0);
        }

    }
    else if(gameState==2)
    {
        iShowBMP(0,0,instruction);
        iShowBMP2(backbuttonCoordinate.x,backbuttonCoordinate.y,backbutton,0);
    }
    else if(gameState==3)
    {
        iShowBMP(0,0,sound);
        iShowBMP2(backbuttonCoordinate.x,backbuttonCoordinate.y,backbutton,0);
        //iShowBMP2(200,400+i*100,sButton[1],0);
        for(i=0; i<2; i++)
        {
            iShowBMP2(soundbCoordinate[i].x,soundbCoordinate[i].y,soundButton[i],0);
        }

    }
    else if(gameState==4)
    {
        int i=0;
        iShowBMP(0,0,play);
        if(rjump)
        {
            if(rjumpup)
            {

                iShowBMP2(ninja2CoordinateX+ninjarjump,ninja2CoordinateY,ninjarj[0],0);

            }
            else
            {

                iShowBMP2(ninja2CoordinateX+ninjarjump,ninja2CoordinateY,ninjarj[1],0);

            }

        }
        else
        {
            iShowBMP2(ninja2CoordinateX,ninja2CoordinateY,ninja2[ninja2index],0);

        }


        for( i=0; i<6; i++)
        {
            iShowBMP2(frontbg[i].x,frontbg[i].y,frontbgimage[i],0);
            timecount++;
        }

        if(timecount>=OBSTACLETIME)
        {
            obstaclemovement();
            obstaclemovement2();
            for(int i=0; i<ObstacleNumber; i++)
            {
                if(obs[i].obstacley2<=200+backgroundspeed &&obs[i].obstacley2>=200-backgroundspeed)
                {
                    if(!rjump)
                    {
                        iPauseTimer(0);
                        iPauseTimer(1);
                        iPauseTimer(2);
                        iPauseTimer(3);
                        iPauseTimer(4);
                        iPauseTimer(5);
                        iPauseTimer(6);
                        gameover=1;
                        iShowBMP2(40,200,dead,0);
                        for(i=1; i==1; i++)
                        {
                            iShowBMP2(Coordinate[i].x,Coordinate[i].y,gameovermenu[i],0);
                        }
                        // FILE  *f1;
                        int j;

                        if( checkmodesk==1)
                        {
                             sprintf(score,"%d",s1);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("input.txt","a");
                                fprintf(f1,"%d  ",s1);
                                fclose(f1);
                                testsk++;


                                f1=fopen("input.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&easy[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(easy[j]<easy[m])
                                        {
                                            int temp=easy[j];
                                            easy[j]=easy[m];
                                            easy[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("input.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",easy[j]);

                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",easy[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s1);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }
                        else if( checkmodesk==2)
                        {
                             sprintf(score,"%d",s2);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("medscore.txt","a");
                                fprintf(f1,"%d  ",s2);
                                fclose(f1);
                                testsk++;


                                f1=fopen("medscore.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&med[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(med[j]<med[m])
                                        {
                                            int temp=med[j];
                                            med[j]=med[m];
                                            med[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("medscore.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",med[j]);

                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",med[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s2);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }
                        else if( checkmodesk==3)
                        {
                             sprintf(score,"%d",s3);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            if(testsk==1)
                            {
                                FILE *f1;
                                f1=fopen("hardscore.txt","a");
                                fprintf(f1,"%d  ",s3);
                                fclose(f1);
                                testsk++;


                                f1=fopen("hardscore.txt","r");
                                for(j=0; j<6; j++)
                                {
                                    fscanf(f1,"%d",&hards[j]);
                                }
                                for(j=0; j<6; j++)
                                {
                                    for(int m=j+1; m<6; m++)
                                    {
                                        if(hards[j]<hards[m])
                                        {
                                            int temp=hards[j];
                                            hards[j]=hards[m];
                                            hards[m]=temp;
                                        }

                                    }
                                }
                                fclose(f1);
                                f1=fopen("hardscore.txt","w");
                                for(j=0; j<5; j++)
                                {
                                    fprintf(f1,"%d  ",med[j]);
                                }
                                fclose(f1);
                            }
                            sprintf(score,"%d",med[0]);
                            iText(370,430,score,GLUT_BITMAP_TIMES_ROMAN_24);
                            sprintf(score,"%d",s3);
                            iText(400,600-20,score,GLUT_BITMAP_TIMES_ROMAN_24);
                        }






                    }


                }
            }

        }


    }
    else if(gameState==5)
    {
        int j;
        iShowBMP(0,0,highscorebg);
        iShowBMP2(backbuttonCoordinate.x,backbuttonCoordinate.y,backbutton,0);
        f1=fopen("hardscore.txt","r");
        for(j=4; j>=0; j--)
        {
            fscanf(f1,"%d",&hards[0]);
            sprintf(score,"%d",hards[0]);
             iText(307,63+j*25,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        fclose(f1);
        f1=fopen("medscore.txt","r");
        for(j=4; j>=0; j--)
        {
            fscanf(f1,"%d",&hards[0]);
            sprintf(score,"%d",hards[0]);
             iText(307,288+j*25,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        fclose(f1);
        f1=fopen("input.txt","r");
        for(j=4; j>=0; j--)
        {
            fscanf(f1,"%d",&hards[0]);
            sprintf(score,"%d",hards[0]);
             iText(307,430+64+j*25,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        fclose(f1);

    }
    if(gameState==0 || gameState==4)
    {

        if(checkmodesk==1)
        {
            sprintf(score,"%d",s1);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(checkmodesk==2)
        {
            sprintf(score,"%d",s2);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(checkmodesk==3)
        {
            sprintf(score,"%d",s3);
        iText(300,750,score,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        //iText(300,390,score,GLUT_BITMAP_TIMES_ROMAN_24);


    }



}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        int i;
        if(gameState==-1)
        {
            for(i=0; i<5; i++)
            {
                if(mx>=bCoordinate[i].x && mx<=bCoordinate[i].x+200&& my>=bCoordinate[i].y && my<=bCoordinate[i].y+76)
                {
                    if(i<4)
                    {
                        gameState=i;
                    }
                    else
                    {
                        gameState=i+1;
                    }
                }
            }
        }
        if(gameState>=0)
        {
            if(mx>=backbuttonCoordinate.x && mx<=backbuttonCoordinate.x+100&& my>=backbuttonCoordinate.y && my<=backbuttonCoordinate.y+47)
            {
                gameState=-1;
            }
        }
        if(gameState==3)
        {
            for(i=0; i<2; i++)
            {
                if(mx>=soundbCoordinate[i].x && mx<=soundbCoordinate[i].x+260&& my>=soundbCoordinate[i].y && my<=soundbCoordinate[i].y+79)
                {
                    if(i==0)
                    {
                        soundactivation==true;
                        PlaySound("GameBackgroundSound.wav",NULL,SND_ASYNC );
                    }
                    else
                    {
                        soundactivation==false;
                        PlaySound(0,0,0);
                    }
                    gameState=-1;
                }
            }
        }
        if(gameState==1)
        {
            for(i=0; i<3; i++)
            {
                if(mx>=modebCoordinate[i].x && mx<=modebCoordinate[i].x+200&& my>=modebCoordinate[i].y && my<=modebCoordinate[i].y+79)
                {
                    if(i==0)
                    {
                        scorespeed1=800;
                        backgroundspeed=2;
                        checkmodesk=1;
                        testsk=1;



                    }
                    if(i==1)
                    {
                        backgroundspeed=5;
                        scorespeed2=400;
                        checkmodesk=2;
                        testsk=1;


                    }
                    if(i==2)
                    {
                        backgroundspeed=8;
                        scorespeed3=200;
                        checkmodesk=3;
                        testsk=1;

                    }
                    s1=0;
                    s2=0;
                    s3=0;
                    gameState=-1;
                    testsk=1;
                }
            }
        }
        if(gameState==0 || gameState==4)
        {
            if(gameover==1)
            {
                for(i=0; i<2; i++)
                {
                    if(mx>=Coordinate[i].x && mx<=Coordinate[i].x+200 && my>=Coordinate[i].y && my<=Coordinate[i].y+97 )
                    {

                        if(i==1)
                        {
                            s1=0;
                            s2=0;
                            s3=0;
                            gameover=0;
                            gameState=-1;
                            timecount=0;
                            hisab=0;
                            backgroundspeed=2;
                            for(i=0;i<ObstacleNumber;i++)
                            {
                                for(int i=0; i<ObstacleNumber; i++)
        {
            obs[i].obstacley1=1400;




        }
        for(int i=0; i<ObstacleNumber; i++)
        {
            obs[i].obstacley2=1400;

        }
                            }



                        }
                    }
                }

            }

        }
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 5;
        y -= 5;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    if(key==' ')
    {
        if(gameover==0)
        {
             if(gameState==4)
        {
            if(!rjump)
            {
                rjump= true;
                rjumpup=true;
            }

        }
        else if(gameState==0)
        {
            if(!ljump)
            {
                ljump= true;
                ljumpup=true;
            }

        }
        }



    }
    if(key=='p')
    {
        if(gameState==0 || gameState==4)
        {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        }

    }
    if(key=='r')
    {
        if(gameover==0)
        {
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
        }


    }

    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key==GLUT_KEY_RIGHT)
    {

        if(gameState==0)
        {

            gameState=4;
        }


    }
    if(key==GLUT_KEY_LEFT)
    {

        if(gameState==4)
        {

            gameState=0;
        }


    }
    //place your codes for other keys here
}
void change2();
void scorechange1()
{



    s1++;



}
void scorechange2()
{
    s2++;
}
void scorechange3()
{
    s3++;
}
void change()
{
    ninjaindex++;
    if(ninjaindex>=4)
    {
        ninjaindex=0;
    }

}
void change2()
{
    int i;
    for(i=0; i<6; i++)
    {
        frontbg[i].y-=backgroundspeed;
        if(frontbg[i].y<=-170)
        {
            frontbg[i].y=800;

        }

    }
    if(timecount>=OBSTACLETIME)
    {
        for(int i=0; i<ObstacleNumber; i++)
        {
            obs[i].obstacley1-=backgroundspeed;
            if(obs[i].obstacley1<=0)
            {
                obs[i].obstacley1=screenheight+rand()%300;
            }

            obs[i].obstacleindex++;
            if(obs[i].obstacleindex>=3)
            {
                obs[i].obstacleindex=0;
            }
        }
        for(int i=0; i<ObstacleNumber; i++)
        {
            obs[i].obstacley2-=backgroundspeed;
            if(obs[i].obstacley2<=0)
            {
                obs[i].obstacley2=screenheight+rand()%200;
            }

            obs[i].obstacleindex++;
            if(obs[i].obstacleindex>=3)
            {
                obs[i].obstacleindex=0;
            }
        }

    }






}
void change3()
{
    ninja2index++;
    if(ninja2index>=8)
    {
        ninja2index=0;
    }
}

void changeobs()
{

}
void setobstaclevariable()
{
    for(int i=0; i<ObstacleNumber; i++)
    {
        obs[i].obstaclex1=18;
        obs[i].obstacley1=screenheight+rand()%600;
        obs[i].obstacleindex=rand()%2;
        obs[i].obstacleshow=true;


    }
}
void setobstaclevariable2()
{
    for(int i=0; i<ObstacleNumber; i++)
    {
        obs[i].obstaclex2=485;

        obs[i].obstacley2=screenheight+rand()%200;
        obs[i].obstacleindex=rand()%2;
        obs[i].obstacleshow=true;
    }



}
void jumpchange()
{
    if(rjump)
    {
        if(rjumpup)
        {
            ninjarjump-=15;
            if(ninjarjump<=RJUMPLIMIT)
            {
                rjumpup=false;

            }
        }
        else
        {
            ninjarjump+=15;
            if(ninjarjump>0)
            {
                rjump=false;


            }

        }
    }
    if(ljump)
    {
        if(ljumpup)
        {
            ninjaljump+=15;
            if(ninjaljump>=LJUMPLIMIT)
            {
                ljumpup=false;

            }
        }
        else
        {
            ninjaljump-=15;
            if(ninjaljump<0)
            {
                ljump=false;


            }

        }
    }
}




int main()
{
    obstaclemovement();


    int i;
    int sum=50;
    for(i=4; i>=0; i--)
    {
        bCoordinate[i].x=200;
        bCoordinate[i].y=sum;
        sum+=80;
    }
    backbuttonCoordinate.x=0;
    backbuttonCoordinate.y=750;
    setobstaclevariable();
    setobstaclevariable2();
    sum=0;
    for(i=1; i>=0; i--)
    {
        soundbCoordinate[i].x=172;
        soundbCoordinate[i].y=sum+400;
        sum+=100;
    }
    sum=0;
    for(i=2; i>=0; i--)
    {
        modebCoordinate[i].x=200;
        modebCoordinate[i].y=sum+350;
        sum+=100;
    }

    backbuttonCoordinate.x=0;
    backbuttonCoordinate.y=755;
    sum=200;
    for(i=1; i>=0; i--)
    {
        Coordinate[i].x=sum;
        Coordinate[i].y=300;
        sum+=250;
    }

    if(soundactivation==true)
        PlaySound("GameBackgroundSound.wav",NULL,SND_ASYNC | SND_LOOP );

    //PlaySound("GameBackgroundSound.wav",NULL ,SND_ASYNC );

    //place your own initialization codes here.
    iSetTimer(100,change);
    iSetTimer(10,change2);
    iSetTimer(50,change3);
    iSetTimer(30,jumpchange);



            iSetTimer(pointspeed1,scorechange1);
            iSetTimer(pointspeed2,scorechange2);
            iSetTimer(pointspeed3,scorechange3);

    // iSetTimer(200,scorechange);
    setAll();


    iInitialize(screenwidth, screenheight, "Ninja Jump");
    return 0;
}
