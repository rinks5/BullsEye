#include "pchNexusGame.h"
#include "levelfour.h"
#include "wall.h"
#include "nexus.h"
#include "game.h"

CLevelFour::CLevelFour()
{
	m_pWallOne = new CWall(m_iPosX, m_iPosY, 80, 60, -90, 2);
	m_pWallTwo = new CWall(m_iPosX, m_iPosY, 120, 100, 100, 4);
	m_pWallThree = new CWall(m_iPosX, m_iPosY, 160, 140, -75, 6);

	CLocalPlayer::Get().SetRotationSpeed(0);
	CLocalPlayer::Get().Spawn(m_iPosX, m_iPosY + m_iRadius * 0.8, 10);
}

CLevelFour::~CLevelFour()
{
	delete m_pWallOne;
	delete m_pWallTwo;
	delete m_pWallThree;
}

void CLevelFour::Update(double timeElapsed)
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
	outtextxy(m_iPosX + m_iPosX/2, 10, "Level 4");
}

bool CLevelFour::OnLeftMouseDown(int x, int y)
{
	int distance = sqrt((m_iPosX - x)*(m_iPosX - x) + (m_iPosY - y)*(m_iPosY - y));
	if(distance < m_iRadius)
	{
		CLocalPlayer::Get().ShootAt(m_iPosX, m_iPosY);
		return true;
	}
	return false;
}

bool CLevelFour::OnRightMouseDown(int x, int y)
{
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

bool CLevelFour::IsColliding(CLocalPlayer & localplayer, bool & bRespawnPlayer)
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
