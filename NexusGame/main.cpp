#include "pchNexusGame.h"
#include "app.h"


int main()
{
	CApp * pApp = new CApp();
	pApp->Run();
	delete pApp;
	return 0;
}

/*
int main()
{
    DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight);
    int x=getmaxx()/2;
    int y=getmaxy()/2;
    int page=0,s=0;
    while(!kbhit())
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        setbkcolor(WHITE);

        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        fillellipse(x, y, 370, 370);


        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(x,y,0+s,60+s,30);

        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        pieslice(x,y,60+s,120+s,30);

        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(x,y,120+s,180+s,30);

        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        pieslice(x,y,180+s,240+s,30);

        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(x,y,240+s,300+s,30);

        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        pieslice(x,y,300+s,360+s,30);

        s+=5; // Increase this value for speed

        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(x, y, 20, 20);

        page=1-page;
        delay(33); // 40 millisecond means game runs at 25 FPS
    }

    getch();
    closegraph();
    return 0;
}

*/
