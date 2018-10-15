#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "levelbase.h"

//Forward Declarations
class CWall;

class CLevelTwo : public CLevelBase
{
public:
					CLevelTwo();
	virtual			~CLevelTwo();

	virtual void	Update(double timeElapsed);

	virtual bool	OnLeftMouseDown(int x, int y);
	virtual bool	OnRightMouseDown(int x, int y);

	virtual bool	IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer);

private:
	CWall *			m_pWallOne;
	CWall *			m_pWallTwo;
	CWall * 		m_pWallThree;
};

#endif // !LEVELBASE_H
