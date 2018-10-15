#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screenbase.h"

// Forward Declarations
class CLevelBase;

enum ELEVEL_TYPE
{
	LEVEL_ONE = 0,
	LEVEL_TWO,
	LEVEL_THREE,
	LEVEL_FOUR,
	LEVEL_FIVE,

	LEVEL_TOTAL = LEVEL_FIVE
};

class CGameScreen : public CScreenBase
{
public:
					CGameScreen();
					~CGameScreen();

	virtual bool	Activate();
	virtual bool	DeActivate();
	virtual void	Update(double timeElapsed);

	virtual bool	OnLeftMouseDown(int x, int y);
	virtual bool	OnRightMouseDown(int x, int y);

	bool			OnLevelComplete();
	void			RestartLevel();

private:
	bool			LevelSelect(ELEVEL_TYPE levelIndex);

private:
	CLevelBase *	m_pCurrentLevel;

	ELEVEL_TYPE		m_eCurrentLevel;

	bool			m_bRestartLevel;
	bool			m_bNextLevel;
};

#endif // !GAMESCREEN_H
