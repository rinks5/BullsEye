#include "pchNexusGame.h"
#include "wall.h"
#include "breakablebrick.h"
#include "unbreakablebrick.h"
#include "game.h"

CWall::CWall(int xPos, int yPos, int iOutterRadius, int iInnerRadius, int iRotationSpeed, int nBricks)
{
	m_iPosX = xPos;
	m_iPosY = yPos;
	m_iRadius = iOutterRadius;
	m_iInnerRadius = iInnerRadius;
	m_nBricks = nBricks;

	if(m_nBricks%2 == 1)
		m_nBricks -= 1;

	if(m_nBricks == 0)
		m_nBricks = 2;

	m_pListBricks = new CBrickBase*[m_nBricks];

	int iBrickAngle = 360/m_nBricks;

	int nEndAngle = 0;
	for(int i = 0; i < m_nBricks; i++)
	{
		if(i%2 == 0)
			m_pListBricks[i] = new CBreakableBrick(m_iPosX, m_iPosY, nEndAngle, (i+1)*iBrickAngle, m_iRadius, m_iInnerRadius, iRotationSpeed);
		else
			m_pListBricks[i] = new CUnbreakableBrick(m_iPosX, m_iPosY, nEndAngle, (i+1)*iBrickAngle, m_iRadius, m_iInnerRadius, iRotationSpeed);
		nEndAngle = (i+1)*iBrickAngle;
	}
}

CWall::~CWall()
{
	for(int i = 0; i < m_nBricks; i ++)
	{
		delete m_pListBricks[i];
	}

	delete[] m_pListBricks;
}

void CWall::Update(double timeElapsed)
{
	CGameObject::Update(timeElapsed);

	for(int i = 0; i < m_nBricks; i ++)
	{
		if(m_pListBricks[i] != NULL)
			m_pListBricks[i]->Update(timeElapsed);
	}
}

bool CWall::IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer)
{
	if(CGameObject::IsCollidingObj(localplayer) == false)
		return false;

	for(int i = 0; i < m_nBricks; i ++)
	{
		if(m_pListBricks[i] && m_pListBricks[i]->IsColliding(localplayer))
		{
			if(m_pListBricks[i]->IsBreakable())
			{
				delete m_pListBricks[i];
				m_pListBricks[i] = NULL;
				bRespawnPlayer = true;
			}
			else
			{
				CGame::Get().Restart();
			}
			break;
		}
	}
	return true;
}
