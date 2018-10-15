#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "gameobject.h"

// Forward Declarations
class CLevelBase;

class CLocalPlayer : public CGameObject
{
public:

	static bool				Create(int iMovementSpeed, int iRotationSpeed);
	static void 			Destroy();
	static CLocalPlayer &	Get();

	virtual void			Update(double timeElapsed);
	virtual int				GetPosX() const;
	virtual int				GetPosY() const;

	void					SetCurrentLevel(CLevelBase * pLevel);
	void					Spawn(int xPos, int yPos, int iRadius);
	void					ShootAt(int xTarget, int yTarget);

	void 					SetRotationSpeed(int iRotationSpeed);

private:
							CLocalPlayer(int iMovementSpeed, int iRotationSpeed);
	virtual					~CLocalPlayer();

private:
	static CLocalPlayer *	s_pLocalPlayer;

	CLevelBase *			m_pRefCurrentLevel;
	int						m_iMovementSpeed;
	int 					m_iTargetX;
	int						m_iTargetY;
	bool					m_bMoving;
	double					m_timeTravel;
	double 					m_xShootDir;
	double					m_yShootDir;
	int						m_iStartPosX;
	int 					m_iStartPosY;
	int 					m_iRotationSpeed;
	bool					m_bRotate;
	double 					m_timeRotationTravel;
};

#endif // !LOCALPLAYER_H
