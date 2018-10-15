#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

// Forward Declarations
class CBrickBase;

class CWall : public CGameObject
{
public:
					CWall(int xPos, int yPos, int iOutterRadius, int iInnerRadius, int iRotationSpeed, int nBricks);
	virtual			~CWall();

	virtual void	Update(double timeElapsed);
	virtual bool 	IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer);

private:
	CBrickBase **	m_pListBricks;
	int				m_nBricks;
	int 			m_iInnerRadius;
};

#endif // !WALL_H
