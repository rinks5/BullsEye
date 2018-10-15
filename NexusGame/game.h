#ifndef GAME_H
#define GAME_H

#include "def.h"

// Forward Declaration
class CFPSController;
class CScreenBase;

class CGame
{
public:
	static bool			Start();
	static void			Stop();
	static CGame &		Get();

	bool				Run();
	void				SetActiveScreen(ESCREEN_TYPE type);
	void				Restart();
	void				OnLevelComplete();

	void 				OnLeftMouseDown(int x, int y);
	void 				OnRightMouseDown(int x, int y);

private:
						CGame();
						~CGame();

	bool				InitPrivate();
	bool				Update(double timeElapsed);

private:
	static CGame *		s_pGame;

private:
	CFPSController *	m_pFPSController;
	double				m_timeTotalElapsed;
	bool				m_bRestart;

	CScreenBase *		m_pGameScreen;
	CScreenBase * 		m_pMenuScreen;

	CScreenBase *		m_pRefActiveScreen;
};

#endif // !GAME_H
