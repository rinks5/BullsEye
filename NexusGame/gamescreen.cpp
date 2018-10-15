#include "pchNexusGame.h"
#include "gamescreen.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"

CGameScreen::CGameScreen()
{
	m_pCurrentLevel = NULL;
	CLocalPlayer::Create(2000, 0);

	m_bRestartLevel = false;
	m_bNextLevel = false;
}

CGameScreen::~CGameScreen()
{
	CLocalPlayer::Destroy();
	DeActivate();
}

bool CGameScreen::Activate()
{
	LevelSelect(LEVEL_ONE);
	return CScreenBase::Activate();
}

bool CGameScreen::DeActivate()
{
	delete m_pCurrentLevel;
	m_pCurrentLevel = NULL;
	m_bRestartLevel = false;
	m_bNextLevel = false;
	m_eCurrentLevel = LEVEL_ONE;
	return CScreenBase::DeActivate();
}

void CGameScreen::Update(double timeElapsed)
{
	if(!IsActive())
		return;

	m_timeTotalElapsed += timeElapsed;

	if(m_bRestartLevel)
	{
		LevelSelect(ELEVEL_TYPE(m_eCurrentLevel));
		m_bRestartLevel = false;
	}

	if(m_bNextLevel)
	{
		LevelSelect(ELEVEL_TYPE(m_eCurrentLevel+1));
		m_bNextLevel = false;
	}

	setcolor(WHITE);
	rectangle(1, 1, getmaxx()-1, getmaxy()-1);

	static char pattern[8] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF};
	setfillpattern(pattern, WHITE);
	//setfillstyle(SOLID_FILL, WHITE);
	bar(2, 2, getmaxx()-2, getmaxy()-2);

	m_pCurrentLevel->Update(timeElapsed);
}

bool CGameScreen::OnLeftMouseDown(int x, int y)
{
	m_pCurrentLevel->OnLeftMouseDown(x, y);
	return true;
}

bool CGameScreen::OnRightMouseDown(int x, int y)
{
	m_pCurrentLevel->OnRightMouseDown(x, y);
	return true;
}

void CGameScreen::RestartLevel()
{
	m_bRestartLevel = true;
}

bool CGameScreen::OnLevelComplete()
{
	if(m_eCurrentLevel >= LEVEL_TOTAL)
		return false;

	m_bNextLevel = true;
	return true;
}

bool CGameScreen::LevelSelect(ELEVEL_TYPE levelIndex)
{
	delete m_pCurrentLevel;
	switch(levelIndex)
	{
		case LEVEL_ONE:
			m_pCurrentLevel = new CLevelOne();
			break;
		case LEVEL_TWO:
			m_pCurrentLevel = new CLevelTwo();
			break;
		case LEVEL_THREE:
			m_pCurrentLevel = new CLevelThree();
			break;
		case LEVEL_FOUR:
			m_pCurrentLevel = new CLevelFour();
			break;
		case LEVEL_FIVE:
			m_pCurrentLevel = new CLevelFour();
			break;
		default:
			return false;
	}
	m_eCurrentLevel = levelIndex;
	CLocalPlayer::Get().SetCurrentLevel(m_pCurrentLevel);
	return true;
}
