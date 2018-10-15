#include "pchNexusGame.h"
#include "nexus.h"

CNexus::CNexus(int xPos, int yPos)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iRadius = 20;
	m_timeTotalElapsed = 0.0;
}

CNexus::~CNexus()
{

}

void CNexus::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);

	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	fillellipse(m_iPosX, m_iPosY, m_iRadius, m_iRadius);
}
