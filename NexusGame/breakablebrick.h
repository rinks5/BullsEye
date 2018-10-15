#ifndef BREAKABLEBRICK_H
#define BREAKABLEBRICK_H

#include "brickbase.h"

class CBreakableBrick : public CBrickBase
{
public:
					CBreakableBrick(int xPos, int yPos, int iStartAngle, int iEndAngle, int iRadius, int iInnerRadius, int iRotationSpeed);
	virtual			~CBreakableBrick();

	virtual void	Update(double timeElapsed);
	virtual bool 	IsColliding(CLocalPlayer & localplayer);

	virtual bool	IsBreakable() const;
};

#endif // !UNBREAKABLEBRICK_H
