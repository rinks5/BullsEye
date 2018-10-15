#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "levelbase.h"

//Forward Declarations
class CWall;

class CLevelThree : public CLevelBase
{
public:
					CLevelThree();
	virtual			~CLevelThree();

	virtual void	Update(double timeElapsed);

	virtual bool	OnLeftMouseDown(int x, int y);
	virtual bool	OnRightMouseDown(int x, int y);

	virtual bool	IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer);

private:
	CWall *			m_pWallOne;
	CWall *			m_pWallTwo;
	CWall * 		m_pWallThree;
	CWall * 		m_pWallFour;
};

#endif // !LEVELBASE_H
