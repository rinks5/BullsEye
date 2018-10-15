#ifndef LEVELBASE_H
#define LEVELBASE_H

#include "gameobject.h"

// Forward Declarations
class CNexus;
class CLocalPlayer;

class CLevelBase : public CGameObject
{
public:
					CLevelBase();
	virtual			~CLevelBase();

	virtual void	Update(double timeElapsed);

	virtual bool	OnLeftMouseDown(int x, int y) = 0;
	virtual bool	OnRightMouseDown(int x, int y) = 0;

	virtual bool	IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer) = 0;

protected:
	CNexus *		m_pNexus;

};

#endif // !LEVELBASE_H
