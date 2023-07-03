/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
# include "gl.h"

int ball_x=200, ball_y=200;
int dx=10, dy=10;
int r=255,g=100,b=255;
int choice;
void play()
{
     PlaySound("GameBackgroundSound.wav",NULL,SND_ASYNC);
}
void stop()
{
     PlaySound(0,0,0);
}




/*
	function iDraw() is called again and again by the system.
*/
void change()
{
    ball_x+=dx;
    ball_y+=dy;
    if(ball_x>=400 || ball_x<=0) dx*=(-1);
    if(ball_y>=400 || ball_y<=0) dy*=(-1);
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;


}
void iDraw()
{
	//place your drawing codes here

	iClear();

    iSetColor(r, g, b);
	iFilledCircle(ball_x, ball_y, 50,1000);

	iSetColor(0, 255, 0);
	iText(10, 10, "Press p for pause, r for resume, END for exit.",GLUT_BITMAP_TIMES_ROMAN_24);
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
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
    if(choice=1)
    {
       choice=2;
    }
    else if(choice=2)
    {
        choice=1;
    }

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here








	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key=='u')
    {
        ball_y+=20;
    }
    else if(key=='d')
    {
        ball_y-=20;
    }
     else if(key=='r')
    {

    }
     else if(key=='g')
    {
        r=0;
        g=255;
        b=0;
    }
     else if(key=='b')
    {
        r=0;
        g=0;
        b=255;
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
	//place your codes for other keys here
}

void ballChange(){
	ball_x += dx;
	ball_y += dy;

	if(ball_x > 400 || ball_x < 0)dx = -dx;
	if(ball_y > 400 || ball_y < 0)dy = -dy;
}

int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	iSetTimer(25, change);
	//dx = 5;
	//dy = 7;
	do
    {
        switch(choice)
        {
            case 1: play();
                    break;
            case 2: stop();
                    break;
        }
    }
    while(choice!=3);
	iInitialize(400, 400, "Ball Demo");

	return 0;
}

