#include "pchNexusGame.h"
#include "levelbase.h"
#include "nexus.h"

CLevelBase::CLevelBase()
{
	m_iPosX = getmaxx()/2.0;
	m_iPosY = getmaxy()/2.0;
	m_iRadius = 340;
	m_timeTotalElapsed = 0.0;

	m_pNexus = new CNexus(m_iPosX, m_iPosY);
}

CLevelBase::~CLevelBase()
{
	delete m_pNexus;
}

void CLevelBase::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillellipse(m_iPosX, m_iPosY, m_iRadius, m_iRadius);

	/*
	char buffer[100];
	sprintf(buffer, "Time Elapsed : %0.2f (Secs)", m_timeTotalElapsed);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
	setcolor(WHITE);
	outtextxy(10, 10, buffer);
	*/
}
