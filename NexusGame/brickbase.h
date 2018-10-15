#ifndef BRICKBASE_H
#define BRICKBASE_H

#include "gameobject.h"

class CBrickBase : public CGameObject
{
public:
					CBrickBase(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iInnerRadius, int iRotationSpeed);
	virtual			~CBrickBase();

	virtual void	Update(double timeElapsed);
	virtual bool	IsColliding(CLocalPlayer & gameObject);

	virtual bool	IsBreakable() const = 0;

protected:
	int				m_iInnerRadius;
	int				m_iStartAngle;
	int				m_iEndAngle;
	int				m_iRotationSpeed;
	int				m_iCurStartAngle;
	int				m_iCurEndAngle;
};

#endif // !BRICKBASE_H
