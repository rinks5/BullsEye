#include "pchNexusGame.h"
#include "gameobject.h"


CGameObject::CGameObject()
{
    m_iPosX = 0;
    m_iPosY = 0;
    m_iRadius = 1;
    m_timeTotalElapsed = 0.0;
}

CGameObject::~CGameObject()
{

}

void CGameObject::Update(double timeElapsed)
{
    m_timeTotalElapsed += timeElapsed;
}

bool CGameObject::IsCollidingObj(CGameObject & gameObject)
{
	double distance = Distance(m_iPosX, m_iPosY, gameObject.GetPosX(), gameObject.GetPosY());
	if(distance < m_iRadius + gameObject.m_iRadius)
		return true;
	return false;
}

double CGameObject::Distance(int xSource, int ySource, int xDest, int yDest) const
{
	return sqrt((xSource-xDest)*(xSource-xDest) + (ySource-yDest)*(ySource-yDest));
}

int CGameObject::GetPosX() const
{
	return m_iPosX;
}

int CGameObject::GetPosY() const
{
	return m_iPosY;
}

int CGameObject::GetRadius() const
{
	return m_iRadius;
}
