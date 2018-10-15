#ifndef SCREENBASE_H
#define SCREENBASE_H

class CScreenBase
{
public:
					CScreenBase();
	virtual			~CScreenBase();

	virtual bool	Activate();
	virtual bool	DeActivate();
	virtual void	Update(double timeElapsed) = 0;
	bool			IsActive() const;

	virtual bool	OnLeftMouseDown(int x, int y);
	virtual bool	OnRightMouseDown(int x, int y);

	virtual bool	OnLevelComplete();
	virtual void 	RestartLevel();

protected:
	bool			m_bActive;
	double			m_timeTotalElapsed;
};

#endif // !SCREENBASE_H
