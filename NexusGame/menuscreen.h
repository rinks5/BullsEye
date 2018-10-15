#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screenbase.h"

class CMenuScreen : public CScreenBase
{
public:
					CMenuScreen();
	virtual			~CMenuScreen();

	virtual void	Update(double timeElapsed);

	virtual bool	OnLeftMouseDown(int x, int y);
	virtual bool	OnRightMouseDown(int x, int y);
private:
	int				m_iStartLeft;
	int				m_iStartTop;
	int 			m_iStartRight;
	int				m_iStartBottom;

};

#endif // !MENUSCREEN_H
