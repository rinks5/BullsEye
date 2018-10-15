#include "pchNexusGame.h"
#include "menuscreen.h"
#include "game.h"

#include"def.h"

CMenuScreen::CMenuScreen()
{
	int sizeX = 120, sizeY = 30;
    m_iStartLeft = getmaxx()/2 - sizeX;
    m_iStartTop = getmaxy()/2 + 100 - sizeY;
    m_iStartRight = getmaxx()/2 + sizeX;
    m_iStartBottom = getmaxy()/2 + 100 + sizeY;
}

CMenuScreen::~CMenuScreen()
{

}

void CMenuScreen::Update(double timeElapsed)
{
	if(!IsActive())
		return;

	setcolor(WHITE);
	rectangle(1, 1, getmaxx()-1, getmaxy()-1);

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	fillellipse(getmaxx()/2, getmaxy()/4+40, 20, 20);

	setcolor(GREEN);
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 20);
	outtextxy(getmaxx()/2, getmaxy()/4, "Bull's EYE");

	setcolor(GREEN);
	setfillstyle(SLASH_FILL, RED);
	bar(m_iStartLeft, m_iStartTop, m_iStartRight, m_iStartBottom);

	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 6);
	outtextxy(getmaxx()/2, getmaxy()/2 + 115, "START");
}

bool CMenuScreen::OnLeftMouseDown(int x, int y)
{
	if(x > m_iStartLeft && x < m_iStartRight && y > m_iStartTop && y < m_iStartBottom)
	{
		CGame::Get().SetActiveScreen(SCREEN_GAME);
	}
	return true;
}

bool CMenuScreen::OnRightMouseDown(int x, int y)
{
	return true;
}
