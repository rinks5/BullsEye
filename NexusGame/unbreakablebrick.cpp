#include "pchNexusGame.h"
#include "unbreakablebrick.h"

CUnbreakableBrick::CUnbreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iInnerRadius, int iRotationSpeed):
	CBrickBase(xPos, yPos, iStartAngle, iEndAngle, iRadius, iInnerRadius, iRotationSpeed)
{

}

CUnbreakableBrick::~CUnbreakableBrick()
{

}

void CUnbreakableBrick::Update(double timeElapsed)
{
	CBrickBase::Update(timeElapsed);

	m_iCurStartAngle = m_iStartAngle + m_iRotationSpeed * m_timeTotalElapsed;
	m_iCurEndAngle = m_iEndAngle + m_iRotationSpeed * m_timeTotalElapsed;

	m_iCurStartAngle = m_iCurStartAngle % 360;
	m_iCurEndAngle = m_iCurEndAngle % 360;

	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(m_iPosX, m_iPosY, m_iCurStartAngle, m_iCurEndAngle, m_iRadius);

	setcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	pieslice(m_iPosX, m_iPosY, m_iCurStartAngle, m_iCurEndAngle, m_iInnerRadius);
}

bool CUnbreakableBrick::IsBreakable() const
{
	return false;
}
