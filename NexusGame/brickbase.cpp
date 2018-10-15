#include "pchNexusGame.h"
#include "brickbase.h"

CBrickBase::CBrickBase(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iInnderRadius, int iRotationSpeed)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iStartAngle = iStartAngle;
	m_iEndAngle = iEndAngle;
	m_iRadius = iRadius;
	m_iInnerRadius = iInnderRadius;
	m_iRotationSpeed = iRotationSpeed;
	m_timeTotalElapsed = 0.0;
}

CBrickBase::~CBrickBase()
{

}

void CBrickBase::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);
}

bool CBrickBase::IsColliding(CLocalPlayer & gameObject)
{
	if(CGameObject::IsCollidingObj(gameObject))
	{
		double dist = Distance(m_iPosX, m_iPosY, gameObject.GetPosX(), gameObject.GetPosY());
		double xDir = (gameObject.GetPosX() - m_iPosX) / dist;
		double yDir = (gameObject.GetPosY() - m_iPosY) / dist;

		double angle = acos(xDir) * 180.0/PI;

		if(yDir > 0)
		{
			angle = 360 - angle;
		}

		int iStartAngle = m_iCurStartAngle;
		int iEndAngle = m_iCurEndAngle;

		if(iStartAngle < 0)
		{
			iStartAngle = 360 + iStartAngle;
		}
		if(iEndAngle < 0)
		{
			iEndAngle = 360 + iEndAngle;
		}
		if(iEndAngle < iStartAngle)
		{
			if((angle > iStartAngle && angle <= 360) || (angle < iEndAngle && angle >= 0))
				return true;
		}
		else if(angle > iStartAngle && angle < iEndAngle)
		{
			return true;
		}
	}
	return false;
}
