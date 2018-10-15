#include "pchNexusGame.h"
#include "levelthree.h"
#include "wall.h"
#include "nexus.h"
#include "game.h"

CLevelThree::CLevelThree()
{
	m_pWallOne = new CWall(m_iPosX, m_iPosY, 80, 60, 100, 2);
	m_pWallTwo = new CWall(m_iPosX, m_iPosY, 120, 100, 120, 8);
	m_pWallThree = new CWall(m_iPosX, m_iPosY, 160, 140, 140, 4);

	CLocalPlayer::Get().SetRotationSpeed(80);
	CLocalPlayer::Get().Spawn(m_iPosX, m_iPosY + m_iRadius * 0.8, 10);
}

CLevelThree::~CLevelThree()
{
	delete m_pWallOne;
	delete m_pWallTwo;
	delete m_pWallThree;
}

void CLevelThree::Update(double timeElapsed)
{
	CLevelBase::Update(timeElapsed);

	m_pWallThree->Update(timeElapsed);
	m_pWallTwo->Update(timeElapsed);
	m_pWallOne->Update(timeElapsed);

	m_pNexus->Update(timeElapsed);

	CLocalPlayer::Get().Update(timeElapsed);

	settextjustify(CENTER_TEXT, TOP_TEXT);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
	setcolor(WHITE);
	outtextxy(m_iPosX + m_iPosX/2, 10, "Level 3");
}

bool CLevelThree::OnLeftMouseDown(int x, int y)
{
	int distance = sqrt((m_iPosX - x)*(m_iPosX - x) + (m_iPosY - y)*(m_iPosY - y));
	if(distance < m_iRadius)
	{
		CLocalPlayer::Get().ShootAt(m_iPosX, m_iPosY);
		return true;
	}
	return false;
}

bool CLevelThree::OnRightMouseDown(int x, int y)
{
	return false;
	double distance = sqrt((m_iPosX - x)*(m_iPosX - x) + (m_iPosY - y)*(m_iPosY - y));
	if(distance < m_iRadius)
	{
		double xDir = (x - m_iPosX) / distance;
		double yDir = (y - m_iPosY) / distance;

		x = xDir * m_iRadius * 0.80;
		y = yDir * m_iRadius * 0.80;

		CLocalPlayer::Get().Spawn(m_iPosX + x, m_iPosY + y, 10);
		return true;
	}

	return false;
}

bool CLevelThree::IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer)
{
	if(CGameObject::IsCollidingObj(localplayer) == false)
		return false;

	if(m_pWallThree->IsColliding(localplayer, bRespawnPlayer) == false)
		return false;

	if(bRespawnPlayer == true)
		return true;

	if(m_pWallTwo->IsColliding(localplayer, bRespawnPlayer) == false)
		return false;

	if(bRespawnPlayer == true)
		return true;

	if(m_pWallOne->IsColliding(localplayer, bRespawnPlayer) == false)
		return false;

	if(bRespawnPlayer == true)
		return true;

	if(m_pNexus->IsCollidingObj(localplayer) == false)
		return false;

	CGame::Get().OnLevelComplete();

	return true;
}
